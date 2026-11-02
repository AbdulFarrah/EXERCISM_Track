public static class SquareRoot
{
    public static int Root(int number)
    {
        if (number==1) return number;
        var n=number/2;
        Console.WriteLine($"{n}");
        for(int i=0;i<=n;i++)
            if(i*i==number)
                return i;
        return -1;
    }
}
