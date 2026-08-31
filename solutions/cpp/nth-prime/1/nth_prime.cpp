#include "nth_prime.h"

namespace nth_prime {
// TODO: add your solution here
int nth(size_t num)
{
    if (num <= 0)
        throw std::domain_error("");
    std::vector<int> primes = {2};
    int candidate = 3;
    while (primes.size() < num)
    {
        bool prime = true;
        for (int p : primes)
        {
            if (p * p > candidate)
                break;
            if (candidate % p == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
            primes.push_back(candidate);
        candidate += 2;
    }
    return primes.back();  
}
}  // namespace nth_prime
