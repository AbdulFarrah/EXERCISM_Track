#include "beer_song.h"

namespace beer_song {
// TODO: add your solution here
string verse(int lyric)
{
    if(lyric==0)
        return "No more bottles of beer on the wall, no more bottles of beer.\n"
        "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
    if (lyric==1)
        return "1 bottle of beer on the wall, 1 bottle of beer.\n"
        "Take it down and pass it around, no more bottles of beer on the "
        "wall.\n";
    if(lyric==2)
        return "2 bottles of beer on the wall, 2 bottles of beer.\n"
        "Take one down and pass it around, 1 bottle of beer on the wall.\n";
    if(lyric >=3 && lyric <= 99)
        return to_string(lyric)+" bottles of beer on the wall, "+to_string(lyric)+" bottles of beer.\n"
        "Take one down and pass it around, "+to_string(lyric-1)+" bottles of beer on the wall.\n";
    return "";
}
string sing(int from, int to)
{
    string s;
    for (int i = from; i >= to; --i)
    {
        s += verse(i);
        if (i != to)
            s += '\n';
    }
    return s;
}
}  // namespace beer_song
