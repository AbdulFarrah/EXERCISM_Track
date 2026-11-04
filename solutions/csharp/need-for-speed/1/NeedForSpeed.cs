class RemoteControlCar
{
    // TODO: define the constructor for the 'RemoteControlCar' class
    private int _speed;
    private int _batteryDrain;
    private int _batteryRemain=100;
    private int _distanceCovered=0;
    public RemoteControlCar(int s,int b)
    {
        _speed=s;
        _batteryDrain=b;
    }
    
    public bool BatteryDrained() => _batteryRemain < _batteryDrain;

    public int DistanceDriven()=>_distanceCovered;

    public void Drive()
    {
        if(_batteryRemain >= _batteryDrain)
        {
            _distanceCovered+=_speed;
            _batteryRemain-=_batteryDrain;
        }
    }

    public static RemoteControlCar Nitro() => new RemoteControlCar(50, 4);
}

class RaceTrack
{
    // TODO: define the constructor for the 'RaceTrack' class
    private int _distance;
    public RaceTrack(int d)
    {
        _distance=d;
    }
    
    public bool TryFinishTrack(RemoteControlCar car)
    {
        while(!car.BatteryDrained())
        {
            car.Drive();
            if (car.DistanceDriven() >= _distance)
                return true;
        }
        return false;
    }
}
