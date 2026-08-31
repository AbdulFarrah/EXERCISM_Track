#include "rna_transcription.h"
namespace rna_transcription {
// TODO: add your solution here
char to_rna(char dna)
{
    switch (dna)
    {
        case 'G': return 'C';
        case 'C': return 'G';
        case 'T': return 'A';
        case 'A': return 'U';
    }
    return '\0';
}

string to_rna(const string& dna)
{
    string rna;
    for (char c : dna)
        rna += to_rna(c);
    return rna;
}
}  // namespace rna_transcription
