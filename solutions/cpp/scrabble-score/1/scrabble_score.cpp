#include "scrabble_score.h"
namespace scrabble_score {
// TODO: add your solution here
int score(const string& s)
{
    unordered_map<unsigned char,int> scoremap;
    scoremap['A']=1; scoremap['E']=1;scoremap['I']=1;
    scoremap['O']=1;scoremap['U']=1;scoremap['L']=1;
    scoremap['N']=1;scoremap['R']=1;scoremap['S']=1;
    scoremap['T']=1;scoremap['D']=2;scoremap['G']=2;
    scoremap['B']=3;scoremap['C']=3;scoremap['M']=3;
    scoremap['P']=3;scoremap['F']=4;scoremap['H']=4; 
    scoremap['V']=4;scoremap['W']=4;scoremap['Y']=4;
    scoremap['K']=5;scoremap['J']=8;scoremap['X']=8;
    scoremap['Q']=10;scoremap['Z']=10;
    int score=0;
    for(unsigned char c : s)
    {
        if(isalpha(c))
        {
            score+=scoremap[toupper(c)];
        }
    }
    return score;
}
}  // namespace scrabble_score
