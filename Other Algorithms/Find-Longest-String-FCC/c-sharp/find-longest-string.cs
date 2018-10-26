using System.Linq;

namespace AlgorithmService
{
    public class BasicAlgorithmService
    {
        public int FindLongestWordLength(string input)
        {
            if (string.IsNullOrWhiteSpace(input))
                throw new InvalidOperationException("Your input cannot be blank.");
            
            return input
                    .Split(' ')
                    .Select(w => w.Length)
                    .Max();
        }
    }
}