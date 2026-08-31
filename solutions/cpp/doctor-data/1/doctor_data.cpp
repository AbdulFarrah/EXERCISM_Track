#include "doctor_data.h"
heaven::Vessel::Vessel(std::string name,int generation) {
    this->name = name;
    this->generation=generation;
}
heaven::Vessel::Vessel(std::string name,int generation,star_map::System current_system) {
    this->name = name;
    this->generation = generation;
    this->current_system  = current_system;
}

heaven::Vessel heaven::Vessel::replicate(std::string name)
{
    heaven::Vessel result{name,(this->generation)+1,star_map::System::Sol};
    return result;
}

void heaven::Vessel::make_buster()
{
    this->busters++;
}

bool heaven::Vessel::shoot_buster()
{
    if(this->busters>0)
    {
        this->busters--;
        return true;
    }
    return false;
}
std::string heaven::get_older_bob(heaven::Vessel A, heaven::Vessel B)
{
        if(A.generation>B.generation)
            return B.name;
        return A.name;
}

bool heaven::in_the_same_system(heaven::Vessel A, heaven::Vessel B)
{
    return A.current_system == B.current_system;
}