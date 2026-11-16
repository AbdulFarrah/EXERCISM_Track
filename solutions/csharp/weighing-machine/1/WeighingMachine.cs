class WeighingMachine
{
    public int Precision { get; }
    public WeighingMachine(int precision)
    {
        Precision = precision;
    }
    private double weight;
    public double Weight
    {
        get => weight;
        set
        {
            if (value < 0)
                throw new ArgumentOutOfRangeException(nameof(value));
            weight = value;
        }
    }
    public double TareAdjustment { get; set; } = 5.0;
    public string DisplayWeight => $"{(Weight - TareAdjustment).ToString($"F{Precision}")} kg";
}