public static class TelemetryBuffer
{
public static byte[] ToBuffer(long reading)
    {
        byte[] data;
        byte prefix;

        if (reading >= 4_294_967_296L && reading <= long.MaxValue)
        {
            data = BitConverter.GetBytes(reading);
            prefix = (byte)(256 - sizeof(long));
        }
        else if (reading >= 2_147_483_648L && reading <= 4_294_967_295L)
        {
            data = BitConverter.GetBytes((uint)reading);
            prefix = (byte)sizeof(uint);
        }
        else if (reading >= 65_536 && reading <= 2_147_483_647)
        {
            data = BitConverter.GetBytes((int)reading);
            prefix = (byte)(256 - sizeof(int));
        }
        else if (reading >= 0 && reading <= 65_535)
        {
            data = BitConverter.GetBytes((ushort)reading);
            prefix = (byte)sizeof(ushort);
        }
        else if (reading >= -32_768 && reading <= -1)
        {
            data = BitConverter.GetBytes((short)reading);
            prefix = (byte)(256 - sizeof(short));
        }
        else if (reading >= int.MinValue && reading <= -32_769)
        {
            data = BitConverter.GetBytes((int)reading);
            prefix = (byte)(256 - sizeof(int));
        }
        else
        {
            data = BitConverter.GetBytes(reading);
            prefix = (byte)(256 - sizeof(long));
        }

        byte[] buffer = new byte[9];
        buffer[0] = prefix;
        Array.Copy(data, 0, buffer, 1, data.Length);

        return buffer;
    }
    public static long FromBuffer(byte[] buffer)
{
    byte prefix = buffer[0];

    return prefix switch
    {
        0x02 => BitConverter.ToUInt16(buffer, 1),
        0x04 => BitConverter.ToUInt32(buffer, 1),
        0xFE => BitConverter.ToInt16(buffer, 1),
        0xFC => BitConverter.ToInt32(buffer, 1),
        0xF8 => BitConverter.ToInt64(buffer, 1),
        _ => 0
    };
}
}
