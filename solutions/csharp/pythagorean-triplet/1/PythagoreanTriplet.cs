public static class PythagoreanTriplet
{
    public static IEnumerable<(int a, int b, int c)> TripletsWithSum(int sum)
{
    var result = new List<(int, int, int)>();
    for (int a = 1; a < sum; a++)
    {
        for (int b = a + 1; b < sum; b++)
        {
            int c = sum - a - b;
            if (b < c && a * a + b * b == c * c)
            {
                result.Add((a, b, c));
            }
        }
    }
    return result;
}
}