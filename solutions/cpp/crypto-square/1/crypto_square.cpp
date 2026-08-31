#include "crypto_square.h"

namespace crypto_square {
// TODO: add your solution here
cipher::cipher(const string& s)
{
    encodedstr=s;
}
const string cipher::normalized_cipher_text()
{
    if (encodedstr.empty()) return "";
    string partialencode;
    for (unsigned char ch : encodedstr)
    {
        if (isalnum(ch))
            partialencode += tolower(ch);
    }
    int n = partialencode.size();
    if (n <= 3)
        return partialencode;
    int c = 1;
    while (c * c < n)
        c++;
    int r = (n + c - 1) / c;
    string result;
    for (int col = 0; col < c; col++)
    {
        for (int row = 0; row < r; row++)
        {
            int index = row * c + col;
            if (index < n)
                result += partialencode[index];
            else
                result += ' ';
        }
        if (col != c - 1)
            result += ' ';
    }
    return result;
}
}  // namespace crypto_square
