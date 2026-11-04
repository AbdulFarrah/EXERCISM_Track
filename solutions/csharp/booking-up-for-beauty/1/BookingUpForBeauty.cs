static class Appointment
{
    public static DateTime Schedule(string appointmentDateDescription)
    => DateTime.Parse(appointmentDateDescription);

    public static bool HasPassed(DateTime appointmentDate)
    => appointmentDate < DateTime.Now;

    public static bool IsAfternoonAppointment(DateTime appointmentDate)
    => appointmentDate.TimeOfDay >= TimeSpan.FromHours(12)
    && appointmentDate.TimeOfDay < TimeSpan.FromHours(18);

    public static string Description(DateTime appointmentDate)=> $"You have an appointment on {appointmentDate.ToString()}.";

    public static DateTime AnniversaryDate()=> new (DateTime.Now.Year, 9, 15);
}
