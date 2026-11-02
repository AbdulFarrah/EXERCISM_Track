public class Player
{
    public int RollDie()
    {
            int start = 1;
    int end = 18;
    return Random.Shared.Next(start, end + 1);
    }

    public double GenerateSpellStrength()
    {
        double start = 1.0;
    double end = 100.0;

    return Random.Shared.NextDouble() * (end - start) + start;
    }
}
