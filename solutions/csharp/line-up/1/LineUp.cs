public static class LineUp
{
    public static string Format(string name, int number)
    {
        string suffix="th";
        int remainder = number%10;
        if(remainder==1)
        {
            if(number%100!=11) suffix="st";
        }
        else if(remainder==2)
        {
            if(number%100!=12) suffix="nd";
        }
        else if(remainder==3)
        {
            if(number%100!=13) suffix="rd";
        }   
        return $"{name}, you are the {number}{suffix} customer we serve today. Thank you!";
    }
}
