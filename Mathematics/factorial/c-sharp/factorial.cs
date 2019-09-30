namespace Algorithms
{
    public class AlgorithmService
    {
        public long Factorialize(int value)
        {
            if (value < 0)
                throw new InvalidOperationException("Please enter a value greater than or equal to zero.");

            return (value == 0) ? 1 : value * Factorialize(value - 1);
        }
    }
}