#pragma once
#include <string>
#include <vector>
namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};
int preparationTime(std::vector<std::string>& layers,int minutes=2);
amount quantities(std::vector<std::string>& layers);
void addSecretIngredient(std::vector<std::string>& mylist,const std::vector<std::string>& friendlist);
std::vector<double> scaleRecipe(const std::vector<double>& amounts,int multiplier);
void addSecretIngredient(std::vector<std::string>& mylist,std::string incredient);
}  // namespace lasagna_master
