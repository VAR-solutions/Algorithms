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
        public void FindLongestWordLength_ReturnCorrectType()
        {
            var result = _basicAlgorithmService.FindLongestWordLength("The quick brown fox jumped over the lazy dog");

            Assert.IsInstanceOfType(result, typeof(int));
        }

        [DataTestMethod]
        [DataRow("The quick brown fox jumped over the lazy dog", 6)]
        [DataRow("May the force be with you", 5)]
        [DataRow("Google do a barrel roll", 6)]
        [DataRow("What is the average airspeed velocity of an unladen swallow", 8)]
        [DataRow("What if we try a super-long word such as otorhinolaryngology", 19)]
        public void FindLongestWordLength_ReturnCorrectValue(string input, int expected)
        {
            var result = _basicAlgorithmService.FindLongestWordLength(input);

            Assert.AreEqual(expected, result);
        }
    }
}