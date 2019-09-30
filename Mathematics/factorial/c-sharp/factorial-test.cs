using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AlgorithmService.Tests
{
    [TestClass]
    public class AlgorithmServiceTests
    {
        private readonly AlgorithmService _algorithmService;

        public BasicAlgorithmServiceTests()
        {
            _algorithmService = new AlgorithmService();
        }

        [TestMethod]
        public void Factorialize_ReturnCorrectType()
        {
            var result = _algorithmService.Factorialize(5);

            Assert.IsInstanceOfType(result, typeof(long));
        }

        [DataTestMethod]
        [DataRow(5, 120)]
        [DataRow(10, 3628800)]
        [DataRow(20, 2432902008176640000)]
        [DataRow(0, 1)]
        public void Factorialize_ReturnCorrectValue(int input, long expected)
        {
            var result = _algorithmService.Factorialize(input);

            Assert.AreEqual(expected, result);
        }
    }
}