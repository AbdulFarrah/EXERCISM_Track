#include "two_bucket.h"
namespace two_bucket {
// TODO: add your solution here
struct State
{
    int b1;
    int b2;
    int moves;
};

measure_result measure(int c1, int c2, int goal, bucket_id start)
{
    std::queue<State> q;
    std::vector<std::vector<bool>> visited(c1 + 1, std::vector<bool>(c2 + 1, false));
    State first = start == bucket_id::one ? State{c1, 0, 1} : State{0, c2, 1};
    q.push(first);
    visited[first.b1][first.b2] = true;
    while (!q.empty())
    {
        State current = q.front();
        q.pop();
        if (current.b1 == goal)
            return {current.moves, bucket_id::one, current.b2};
        if (current.b2 == goal)
            return {current.moves, bucket_id::two, current.b1};
        std::vector<State> next;
        next.push_back({c1, current.b2, current.moves + 1});
        next.push_back({current.b1, c2, current.moves + 1});
        next.push_back({0, current.b2, current.moves + 1});
        next.push_back({current.b1, 0, current.moves + 1});
        int space2 = c2 - current.b2;
        int pour12 = current.b1 < space2 ? current.b1 : space2;
        next.push_back({ current.b1 - pour12, current.b2 + pour12, current.moves + 1 });
        int space1 = c1 - current.b1;
        int pour21 = current.b2 < space1 ? current.b2 : space1;
        next.push_back({ current.b1 + pour21, current.b2 - pour21, current.moves + 1 });
        for (const State& s : next)
        {
            if (s.b1 == current.b1 && s.b2 == current.b2)
                continue;
            if (start == bucket_id::one)
            {
                if (s.b1 == 0 && s.b2 == c2) continue;
            }
            else
            {
                if (s.b2 == 0 && s.b1 == c1) continue;
            }
            if (visited[s.b1][s.b2]) continue;
            visited[s.b1][s.b2] = true;
            q.push(s);
        }
    }
    throw std::invalid_argument("goal cannot be measured");
}
}  // namespace two_bucket
