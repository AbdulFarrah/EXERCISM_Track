#ifndef AFFINE_CIPHER_H
#define AFFINE_CIPHER_H
#include <stdexcept>
#include <string>
#include <cctype>
#include <numeric>
using namespace std;
namespace affine_cipher {
// TODO: add your solution here
const string encode(const string&,int,int);
const string decode(const string&,int,int);
}  // namespace affine_cipher

#endif  // AFFINE_CIPHER_H
