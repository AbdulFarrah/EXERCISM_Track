class Lasagna
{
    // TODO: define the 'ExpectedMinutesInOven()' method
    public int ExpectedMinutesInOven()=>40;
    // TODO: define the 'RemainingMinutesInOven()' method
    public int RemainingMinutesInOven(int a)=>ExpectedMinutesInOven()-a;
    // TODO: define the 'PreparationTimeInMinutes()' method
    public int PreparationTimeInMinutes(int a)=>2*a;
    // TODO: define the 'ElapsedTimeInMinutes()' method
    public int ElapsedTimeInMinutes(int a,int b)=>PreparationTimeInMinutes(a)+b;
}
