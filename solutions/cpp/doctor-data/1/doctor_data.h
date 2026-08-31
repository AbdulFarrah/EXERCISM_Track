#pragma once
#include <string>
namespace star_map{
    enum class System{
    BetaHydri,
    Sol,
    EpsilonEridani,
    AlphaCentauri,
    DeltaEridani,
    Omicron2Eridani
};
}
namespace heaven{
    class Vessel{
    public:
    Vessel(std::string name,int generation);
    Vessel(std::string name,int generation,star_map::System current_system);
    Vessel replicate(std::string);
    void make_buster();
    bool shoot_buster();
    
    std::string name;
    int generation;
    star_map::System current_system;
    int busters;
    };
    std::string get_older_bob(Vessel A, Vessel B);
    bool in_the_same_system(Vessel A, Vessel B);
}