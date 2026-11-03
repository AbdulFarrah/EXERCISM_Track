class RemoteControlCar
{
    public int DistanceCovered=0;
    public int RemainingBattery=100;
    public static RemoteControlCar Buy()
    {
        return new RemoteControlCar();
    }

    public string DistanceDisplay()
    {
        return $"Driven {DistanceCovered} meters";
    }

    public string BatteryDisplay()
    {
        return RemainingBattery > 0 ? $"Battery at {RemainingBattery}%" : "Battery empty";
    }

    public void Drive()
    {
        if(RemainingBattery>0)
        {
        DistanceCovered+=20;
        RemainingBattery--;
        }
    }
}
