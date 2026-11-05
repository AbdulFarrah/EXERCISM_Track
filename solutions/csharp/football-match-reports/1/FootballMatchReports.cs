public static class PlayAnalyzer
{
    public static string AnalyzeOnField(int shirtNum)
    {
        switch (shirtNum)
        {
            case 1: return "goalie";
            case 2: return "left back";
            case 3: 
            case 4: return "center back";
            case 5: return "right back";
            case 6:
            case 7:
            case 8: return "midfielder";
            case 9: return "left wing";
            case 10: return "striker";
            case 11: return "right wing";
            default: return "UNKNOWN";       
        }
    }

    public static string AnalyzeOffField(object report)
    {
        switch (report)
        {
            case int s: return $"There are {s} supporters at the match.";
            case string m: return m;
            case Foul f: return f.GetDescription();
            case Injury i: return $"Oh no! {i.GetDescription()} Medics are on the field."; 
            case Incident d: return d.GetDescription();
            case Manager m when !string.IsNullOrEmpty(m.Club):
    return $"{m.Name} ({m.Club})";

case Manager m:
    return m.Name;
            default: return "";
        }
    }
}
