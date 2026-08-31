#include "rotational_cipher.h"
namespace rotational_cipher {
// TODO: add your solution here
string rotate(const string& s, int key)
{
    key %= 26;
    if (key < 0) key += 26;
    string result;
    for (unsigned char c : s)
    {
        if (isalpha(c))
        {
            char base = islower(c) ? 'a' : 'A';
            result += (c - base + key) % 26 + base;
        }
        else result += c;
    }
    return result;
}
}  // namespace rotational_cipher
