namespace AlgorithmService
{
    public class BasicAlgorithmService
    {
        // Truncate a string (first argument) if it is longer than the
        // given maximum string length (second argument)
        // Return the truncated string with a ... ending
        public string TruncateString(string input, int maxLength)
        {
            if (input.Length <= maxLength)
                return input;

            return $"{input.Substring(0, maxLength)}...";
        }
    }
}