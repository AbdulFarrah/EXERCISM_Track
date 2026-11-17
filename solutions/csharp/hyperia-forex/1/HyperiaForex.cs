public struct CurrencyAmount
{
    private decimal amount;
    private string currency;
    public CurrencyAmount(decimal amount, string currency)
    {
        this.amount = amount;
        this.currency = currency;
    }
     public static bool operator ==(CurrencyAmount left, CurrencyAmount right)
    {
        if (left.currency != right.currency)
            throw new ArgumentException("Cannot compare different currencies.");
        return left.amount == right.amount;
    }
    public static bool operator !=(CurrencyAmount left, CurrencyAmount right) => !(left == right);
    public static bool operator >(CurrencyAmount left, CurrencyAmount right)
    {
        if (left.currency != right.currency)
            throw new ArgumentException("Cannot compare different currencies.");
        return left.amount > right.amount;
    }
    public static bool operator <(CurrencyAmount left, CurrencyAmount right) => !(left > right);
    public static CurrencyAmount operator +(CurrencyAmount left, CurrencyAmount right)
    {
        if (left.currency != right.currency)
            throw new ArgumentException("Cannot compare different currencies.");
         return new CurrencyAmount(left.amount + right.amount, left.currency);
    }
    public static CurrencyAmount operator -(CurrencyAmount left, CurrencyAmount right)
    {
        if (left.currency != right.currency)
            throw new ArgumentException("Cannot compare different currencies.");
         return new CurrencyAmount(left.amount - right.amount, left.currency);
    }
    public static CurrencyAmount operator *(CurrencyAmount left, decimal multiplier) => new CurrencyAmount(left.amount * multiplier, left.currency);
    public static CurrencyAmount operator /(CurrencyAmount left, decimal divisor) => new CurrencyAmount(left.amount / divisor, left.currency);
   public static explicit operator double(CurrencyAmount value) => (double)value.amount;
    public static implicit operator decimal(CurrencyAmount value) => value.amount;
}
