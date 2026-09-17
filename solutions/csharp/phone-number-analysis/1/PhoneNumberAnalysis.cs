public static class PhoneNumber
{
    public static (bool IsNewYork, bool IsFake, string LocalNumber) Analyze(string phoneNumber)
{
    bool isNewYork = false;
    bool isFake = false;
    if (phoneNumber[0..3] == "212")
        isNewYork = true;
    if (phoneNumber[4..7] == "555")
        isFake = true;
    return (isNewYork, isFake, phoneNumber[8..]);
}

    public static bool IsFake((bool IsNewYork, bool IsFake, string LocalNumber) phoneNumberInfo)=>phoneNumberInfo.IsFake;
}
