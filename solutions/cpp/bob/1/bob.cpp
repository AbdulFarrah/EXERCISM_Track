#include "bob.h"
namespace bob {
// TODO: add your solution here
string hey(string s)
{
    bool has_letter = false;
    bool all_caps = true;
    char last = '\0';
    for (char c : s)
    {
        if (!isspace(static_cast<unsigned char>(c)))
            last = c;
        if (isalpha(static_cast<unsigned char>(c)))
        {
            has_letter = true;
            if (!isupper(static_cast<unsigned char>(c)))
                all_caps = false;
        }
    }
    if (last == '\0')
        return "Fine. Be that way!";
    bool question = (last == '?');
    all_caps &= has_letter;
    if (all_caps && question)
        return "Calm down, I know what I'm doing!";
    if (all_caps)
        return "Whoa, chill out!";
    if (question)
        return "Sure.";
    return "Whatever.";
}
}  // namespace bob
