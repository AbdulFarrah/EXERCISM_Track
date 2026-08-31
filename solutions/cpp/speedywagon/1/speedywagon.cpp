#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:
bool connection_check(pillar_men_sensor* sensor)
{
    return sensor;
}
int activity_counter(pillar_men_sensor* ptr,int capacity)
{
    int size=0;
    for(int i=0;i<capacity;++i)
        {
            size += (ptr+i)->activity;
        }
    return size;
}
bool alarm_control(pillar_men_sensor* sensor)
{
    return sensor ? sensor->activity : false;
}
bool uv_alarm(pillar_men_sensor* sensor)
{
    return !sensor ? false : uv_light_heuristic(&sensor->data) > sensor->activity;
}
// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

}  // namespace speedywagon
