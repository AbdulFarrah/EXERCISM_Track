#include "protein_translation.h"
namespace protein_translation {
// TODO: add your solution here
vector<string> proteins(const string& s)
{
    vector<string> result;
    for (size_t i = 0; i + 2 < s.size(); i += 3)
    {
    std::string temp = s.substr(i, 3);
    if (temp == "AUG") result.push_back("Methionine");
    else if (temp == "UUU" || temp == "UUC") result.push_back("Phenylalanine");
    else if (temp == "UUA" || temp == "UUG") result.push_back("Leucine");
    else if (temp == "UCU" || temp == "UCC" || temp == "UCA" || temp == "UCG") result.push_back("Serine");
    else if (temp == "UAU" || temp == "UAC") result.push_back("Tyrosine");
    else if (temp == "UGU" || temp == "UGC") result.push_back("Cysteine");
    else if (temp == "UGG") result.push_back("Tryptophan");
    else if (temp == "UAA" || temp == "UAG" || temp == "UGA")     break;
    }
    return result;
}
}  // namespace protein_translation
