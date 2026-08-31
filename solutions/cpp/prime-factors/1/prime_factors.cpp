#include "prime_factors.h"

namespace prime_factors {
// TODO: add your solution here
const std::vector<long long> of(long long n)
{
    std::vector<long long> factors;

    for (long long factor = 2; factor * factor <= n; ++factor)
    {
        while (n % factor == 0)
        {
            factors.push_back(factor);
            n /= factor;
        }
    }

    if (n > 1)
        factors.push_back(n);

    return factors;
}
}  // namespace prime_factors
