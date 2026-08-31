#include "parallel_letter_frequency.h"
#include <thread>
#include <algorithm>
#include <cctype>
using namespace std;
namespace parallel_letter_frequency {
void worker(const vector<string_view>& texts,size_t begin,size_t end,unordered_map<char, int>& local)
{
    for (size_t i = begin; i < end; ++i)
        for (unsigned char c : texts[i])
            if (isalpha(c))
                ++local[tolower(c)];
}
const unordered_map<char, int> frequency(const vector<string_view>& texts)
{
    if (texts.empty())
        return {};
    size_t num_threads = min(texts.size(),static_cast<size_t>(max(1u,thread::hardware_concurrency())));
    vector<unordered_map<char, int>> local_maps(num_threads);
    vector<thread> workers;
    for (size_t t = 0; t < num_threads; ++t) {
        size_t begin = t * texts.size() / num_threads;
        size_t end   = (t + 1) * texts.size() / num_threads;
workers.emplace_back(worker,cref(texts),begin,end,ref(local_maps[t]));
    }
    for (auto& th : workers)
        th.join();
    unordered_map<char, int> result;
    for (const auto& m : local_maps)
        for (const auto& [c, count] : m)
            result[c] += count;
    return result;
}
}