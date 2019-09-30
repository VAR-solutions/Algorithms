using System;
using Collections;
using Xunit;

namespace LinkedListTest {
    public class UnitTest1 {
        [Fact]
        public void TestAppendOneItem () {
            LinkedList<int> list = new LinkedList<int> ();
            list.Append (42);
            Assert.Equal (42, list[0]);
        }

        [Fact]
        public void TestAppendMultipleItem () {
            LinkedList<int> list = new LinkedList<int> ();
            list.Append (42);
            list.Append (23);
            list.Append (1337);
            Assert.Equal (42, list[0]);
            Assert.Equal (23, list[1]);
            Assert.Equal (1337, list[2]);
        }

        [Fact]
        public void TestIndexOutOfRangeException () {
            LinkedList<int> list = new LinkedList<int> ();
            Assert.Throws<IndexOutOfRangeException>(() => list[0]);
        }
    }
}