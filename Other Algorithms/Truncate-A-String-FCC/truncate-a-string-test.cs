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

        [DataTestMethod]
        [DataRow("A-tisket a-tasket A green and yellow basket", 8, "A-tisket...")]
        [DataRow("Peter Piper picked a peck of pickled peppers", 11, "Peter Piper...")]
        [DataRow("A-", 1, "A...")]
        [DataRow("Absolutely Longer", 2, "Ab...")]
        public void TruncateString_ReturnsCorrectValue(string input, int length, string expected)
        {
            var result = _basicAlgorithmService.TruncateString(input, length);

            Assert.AreEqual(expected, result);

        }

        [TestMethod]
        public void TruncateString_ReturnsCorrectValue_Expression()
        {
            var testInput = "A-tisket a-tasket A green and yellow basket";

            var result = _basicAlgorithmService.TruncateString(testInput, testInput.Length);

            Assert.AreEqual(testInput, result);

            var newResult = _basicAlgorithmService.TruncateString(testInput, testInput.Length + 2);

            Assert.AreEqual(testInput, newResult);
        }
    }
}