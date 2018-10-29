using Xunit;
using Stack;

namespace StackTest {
    public class StackTest {
        private Stack<int> Stack;
        public StackTest () {
            Stack = new Stack<int> ();
        }

        [Fact]
        public void NewStackIsEmpty()
        {
            Assert.True(Stack.IsEmpty);
        }
        [Fact]
        public void Push () {
            Stack.Push (23);
            Assert.Equal (1, Stack.Count);
            Stack.Push (42);
            Assert.Equal (2, Stack.Count);
        }

        [Fact]
        public void Pop()
        {
            Stack.Push(42);
            Assert.Equal(42, Stack.Pop());
        }
    }
}