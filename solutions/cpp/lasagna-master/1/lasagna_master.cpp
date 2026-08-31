#include "lasagna_master.h"

namespace lasagna_master {

// TODO: add your solution here
int preparationTime(std::vector<std::string>& layers,int minutes)
{
    return layers.size()*minutes;
}
amount quantities(std::vector<std::string>& layers)
{
    amount result{};
    for(std::size_t i=0;i<layers.size();++i)
        {
            if(layers[i] == "sauce") result.sauce+=0.2;
            if(layers[i] == "noodles") result.noodles+=50;
        }
    return result;
}

void addSecretIngredient(std::vector<std::string>& mylist,const std::vector<std::string>& friendlist){
        mylist[mylist.size()-1] = friendlist[friendlist.size()-1];
    }
std::vector<double> scaleRecipe(const std::vector<double>& amounts,int multiplier){
    std::vector<double> result;
    for(auto itr:amounts)
        {
    result.emplace_back(itr*(multiplier/2.0));
        }
    return result;
}
void addSecretIngredient(std::vector<std::string>& mylist,std::string incredient)
{
        mylist[mylist.size()-1] = incredient;
}
}  // namespace lasagna_master
