#include "sieve.h"
namespace sieve {
const std::vector<int> primes(int limit)
{
    if (limit < 2)
        return {};
    std::vector<bool> isPrime(limit + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= limit; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= limit; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    std::vector<int> result;
    for (int i = 2; i <= limit; i++)
    {
        if (isPrime[i])
            result.push_back(i);
    }
    return result;
}
} // namespace sieve