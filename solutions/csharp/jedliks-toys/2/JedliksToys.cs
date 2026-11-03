class RemoteControlCar
{
    public int DistanceCovered = 0;
    public int RemainingBattery = 100;

    public static RemoteControlCar Buy() => new RemoteControlCar();

    public string DistanceDisplay() => $"Driven {DistanceCovered} meters";

    public string BatteryDisplay() =>
        RemainingBattery > 0 ? $"Battery at {RemainingBattery}%" : "Battery empty";

    public void Drive()
    {
        if (RemainingBattery > 0)
        {
            DistanceCovered += 20;
            RemainingBattery--;
        }
    }
}