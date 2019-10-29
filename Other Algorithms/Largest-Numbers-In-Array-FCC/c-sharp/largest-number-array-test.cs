using Microsoft.VisualStudio.TestTools.UnitTesting;
using AlgorithmService;

namespace AlgorithmService.Tests
{
    [TestClass]
    public class BasicAlgorithmServiceTests
    {
        private readonly BasicAlgorithmService _basicAlgorithmService;

        public BasicAlgorithmServiceTests()
        {
            _basicAlgorithmService = new BasicAlgorithmService();
        }

        [TestMethod]
        public void LargestOfFour_ReturnCorrectType()
        {
            var input = new int[4][]
            {
                new int[4] { 4, 5, 1, 3 },
                new int[4] { 13, 27, 18, 26 },
                new int[4] { 32, 35, 37, 39 },
                new int[4] { 1000, 1001, 857, 1 },
            };

            var result = _basicAlgorithmService.LargestOfFour(input);

            Assert.IsInstanceOfType(result, typeof(IEnumerable));
        }

        [TestMethod]
        public void LargestOfFour_ReturnCorrectValue()
        {
            var input = new int[4][]
            {
                new int[4] { 4, 5, 1, 3 },
                new int[4] { 13, 27, 18, 26 },
                new int[4] { 32, 35, 37, 39 },
                new int[4] { 1000, 1001, 857, 1 },
            };

            var expected = new int[4] { 5, 27, 39, 1001 };

            var result = _basicAlgorithmService.LargestOfFour(input);

            CollectionAssert.AreEqual(expected, result);

            input = new int[4][]
            {
                new int[4] { 4, 9, 1, 3 },
                new int[4] { 13, 35, 18, 26 },
                new int[4] { 32, 35, 97, 39 },
                new int[4] { 1000000, 1001, 857, 1 },
            };

            expected = new int[4] { 9, 35, 97, 1000000 };

            result = _basicAlgorithmService.LargestOfFour(input);

            CollectionAssert.AreEqual(expected, result);

            input = new int[4][]
            {
                new int[4] { 17, 23, 25, 12 },
                new int[4] { 25, 7, 34, 48 },
                new int[4] { 4, -10, 18, 21 },
                new int[4] { -72, -3, -17, -10 },
            };

            expected = new int[4] { 25, 48, 21, -3 };

            result = _basicAlgorithmService.LargestOfFour(input);

            CollectionAssert.AreEqual(expected, result);
        }
    }
}