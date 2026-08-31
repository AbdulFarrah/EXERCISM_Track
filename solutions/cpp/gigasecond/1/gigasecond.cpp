#include "gigasecond.h"
namespace gigasecond {
// TODO: add your solution here
const ptime advance(ptime t)
{
    return t+seconds(1000000000);
}
}  // namespace gigasecond
