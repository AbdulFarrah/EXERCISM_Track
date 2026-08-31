#include "power_of_troy.h"

namespace troy {
void give_new_artifact(human& HumanObj,std::string ArtifactName)
{
    HumanObj.possession = std::make_unique<artifact>(ArtifactName);
}
void exchange_artifacts(std::unique_ptr<artifact>& A,std::unique_ptr<artifact>& B)
{
    std::unique_ptr<artifact> temp = std::move(A);
    A=std::move(B);
    B=std::move(temp);
}
void manifest_power(human& HumanObj,std::string PowerName)
{
    HumanObj.own_power = std::make_shared<power>(PowerName);
}
void use_power(human& CasterObj,human& TargetObj)
{
    TargetObj.influenced_by = CasterObj.own_power;
}
int power_intensity(human& HumanObj)
{
    return HumanObj.own_power.use_count();
}
}  // namespace troy
