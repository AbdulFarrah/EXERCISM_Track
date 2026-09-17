public static class LogAnalysis 
{
    // TODO: define the 'SubstringAfter()' extension method on the `string` type
    public static string SubstringAfter(this string str,string key)=>str[(str.IndexOf(key)+key.Length)..];
    // TODO: define the 'SubstringBetween()' extension method on the `string` type
    public static string SubstringBetween(this string str,string start,string end)=>str[(str.IndexOf(start)+ start.Length)..str.IndexOf(end)];
    // TODO: define the 'Message()' extension method on the `string` type
    public static string Message(this string str)=>str.SubstringAfter(": ");
    // TODO: define the 'LogLevel()' extension method on the `string` type
    public static string LogLevel(this string str)=>str.SubstringBetween("[","]");
}