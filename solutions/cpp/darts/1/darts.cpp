#include "darts.h"
namespace darts {
// TODO: add your solution here
int score(double x,double y)
{
    double r2 = x * x + y * y;
    if (r2 <= 1) return 10;      
    if (r2 <= 25) return 5;      
    if (r2 <= 100) return 1; 
    return 0;
}
}  // namespace darts
