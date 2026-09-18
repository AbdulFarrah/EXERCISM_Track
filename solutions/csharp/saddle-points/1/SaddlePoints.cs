public static class SaddlePoints
{
    public static IEnumerable<(int, int)> Calculate(int[,] matrix)
{
    int rows = matrix.GetLength(0), cols = matrix.GetLength(1);
    var result = new List<(int, int)>();
    var columnMin = new int[cols];
    for (int col = 0; col < cols; col++)
    {
        columnMin[col] = matrix[0, col];
        for (int row = 1; row < rows; row++)
            columnMin[col] = Math.Min(columnMin[col], matrix[row, col]);
    }
    for (int row = 0; row < rows; row++)
    {
        int rowMax = matrix[row, 0];
        for (int col = 1; col < cols; col++)
            rowMax = Math.Max(rowMax, matrix[row, col]);
        for (int col = 0; col < cols; col++)
            if (matrix[row, col] == rowMax && matrix[row, col] == columnMin[col])
                result.Add((row + 1, col + 1));
    }
    return result;
}
}
