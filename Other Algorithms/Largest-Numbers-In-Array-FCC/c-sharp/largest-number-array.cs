using System.Linq;

namespace AlgorithmService
{
    public class BasicAlgorithmService
    {
        public int[] LargestOfFour(int[][] input)
        {
            if (input.Length != 4)
                throw new InvalidOperationException("Your array must have 4 items");

            return input
                .Select(i => i.Max())
                .ToArray();
        }
    }
}