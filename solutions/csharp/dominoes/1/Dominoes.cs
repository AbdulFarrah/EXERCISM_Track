public static class Dominoes
{
   public static bool CanChain(IEnumerable<(int, int)> dominoes)
{
    var list = dominoes.ToList();
    if (list.Count == 0)
        return true;
    var connections = new Dictionary<int, List<int>>();
    foreach (var (a, b) in list)
    {
        connections.TryAdd(a, []);
        connections.TryAdd(b, []);
        connections[a].Add(b);
        connections[b].Add(a);
    }
    if (connections.Values.Any(x => x.Count % 2 != 0))
        return false;
    var visited = new HashSet<int>();
    var stack = new Stack<int>();
    stack.Push(list[0].Item1);
    while (stack.Count > 0)
    {
        var current = stack.Pop();
        if (!visited.Add(current))
            continue;
        foreach (var next in connections[current])
            stack.Push(next);
    }
    return visited.Count == connections.Count;
}
}