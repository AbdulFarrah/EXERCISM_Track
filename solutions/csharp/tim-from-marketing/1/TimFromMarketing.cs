static class Badge
{
    public static string Print(int? id, string name, string? department)
    {
        string first = id != null ? $"[{id}] - " : "";
        string dpt = department ?? "OWNER";
        return $"{first}{name} - {dpt.ToUpper()}";
    }
}
