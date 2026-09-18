static class AssemblyLine
{
    public static double SuccessRate(int speed)
    {
       if(speed==0) return 0.00;
       if(speed<=4) return 1.00;
       if(speed<=8) return 0.9;
       if(speed==9) return 0.8;
       if(speed==10) return 0.77;
       else return 0.00;
    }
    
    public static double ProductionRatePerHour(int speed)=>SuccessRate(speed)*speed*221;

    public static int WorkingItemsPerMinute(int speed)=>(int)ProductionRatePerHour(speed)/60;
}
