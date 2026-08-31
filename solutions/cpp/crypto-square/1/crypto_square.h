#pragma once
#include <string>
#include <cctype>
using namespace std;
namespace crypto_square {
// TODO: add your solution here
class cipher{
    public:
    cipher(const string&);
    string encodedstr;
    const string normalized_cipher_text();
};
}  // namespace crypto_square
