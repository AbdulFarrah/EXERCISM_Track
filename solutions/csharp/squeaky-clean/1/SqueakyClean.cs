public static class Identifier
{
    public static string Clean(string identifier)
    {
        string result = "";

        if (string.IsNullOrEmpty(identifier))
            return result;

        for (int i = 0; i < identifier.Length; i++)
        {
            if (identifier[i] == ' ')
                result += '_';
            else if (identifier[i] == '\0')
                result += "CTRL";
            else if (identifier[i] == '-')
            {
                if (i + 1 < identifier.Length)
                    result += char.ToUpper(identifier[++i]);
            }
            else if (identifier[i] >= 'α' && identifier[i] <= 'ω')
                continue;
            else if (!char.IsLetter(identifier[i]))
                continue;
            else
                result += identifier[i];
        }

        return result;
    }
}