#include "rail_fence_cipher.h"

namespace rail_fence_cipher {

std::string encode(const std::string& plaintext, int num_rails) {
    std::string result;
    std::vector<std::vector<char>> board(num_rails,std::vector<char>(plaintext.size(),'\0'));
   int row = 0,dir = 1;
    for (size_t col = 0; col < plaintext.size(); ++col) 
    {
        board[row][col] = plaintext[col];
        if (row == 0)
            dir = 1;
        else if (row == num_rails - 1)
            dir = -1;
        row += dir;
    }
    for(int i=0;i<num_rails;i++)
        for(size_t j=0;j<plaintext.size();j++)
            if (board[i][j] != '\0')
                result+=board[i][j];
    return result;
}

std::string decode(const std::string& ciphertext, int num_rails) {
    std::string result;
    std::vector<std::vector<char>> board(num_rails,std::vector<char>(ciphertext.size(),'\0'));
   int row = 0,dir = 1;
    for (size_t col = 0; col < ciphertext.size(); ++col) 
    {
        board[row][col] = '*';
        if (row == 0)
            dir = 1;
        else if (row == num_rails - 1)
            dir = -1;
        row += dir;
    }
    int c=0;
    for(int i=0;i<num_rails;i++)
        for(size_t j=0;j<ciphertext.size();j++)
            if(board[i][j]=='*')
            {
                board[i][j]=ciphertext[c];
                c++;
            }
    row = 0;dir = 1;
    for (size_t col = 0; col < ciphertext.size(); ++col) 
    {
        result+=board[row][col];
        if (row == 0)
            dir = 1;
        else if (row == num_rails - 1)
            dir = -1;
        row += dir;
    }
    return result;
}

}  // namespace rail_fence_cipher
