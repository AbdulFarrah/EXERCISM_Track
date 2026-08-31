#include "resistor_color.h"
namespace resistor_color {
// TODO: add your solution here
size_t color_code(const string& color)
{
    vector<string> band {"black","brown","red","orange","yellow","green","blue","violet","grey","white"};
    for(size_t i=0;i<band.size();i++)
    {
        if(band[i]==color) return i;
    }
    return band.size()+1;
}
vector<string> colors()
{
    return {"black","brown","red","orange","yellow","green","blue","violet","grey","white"};
}
}  // namespace resistor_color
