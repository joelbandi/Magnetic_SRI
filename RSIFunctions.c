/*
 * RSIFunctions.c
 *
 * Created: 5/12/2015 1:45:54 PM
 *  Author: Camacho
 */ 


static byte[] GetBytes(string str)
{
	byte[] bytes = new byte[str.Length * sizeof(char)];
	System.Buffer.BlockCopy(str.ToCharArray(), 0, bytes, 0, bytes.Length);
	return bytes;
}

static string GetString(byte[] bytes)
{
	char[] chars = new char[bytes.Length / sizeof(char)];
	System.Buffer.BlockCopy(bytes, 0, chars, 0, bytes.Length);
	return new string(chars);
}