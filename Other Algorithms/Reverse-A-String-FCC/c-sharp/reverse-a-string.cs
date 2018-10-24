
namespace AlgorithmService
{
    public class BasicAlgorithmService
    {
        public string ReverseString(string original)
        {
            if (original == null)
                throw new ArgumentNullException(nameof(original));

            if (original.Length == 0)
                return "";

            return string.Join("", original.ToCharArray().Reverse());
        }
    }
}
