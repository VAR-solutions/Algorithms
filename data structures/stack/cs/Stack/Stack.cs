using System;
using System.Collections.Generic;

namespace Stack {
    ///<summary>
    /// Stack implementation on top a list.
    ///</summary>
    public class Stack<T> {

        private List<T> _Stack { get; } = new List<T> ();

        public void Push (T item) => _Stack.Add (item);

        public T Pop () => _Stack[_Stack.Count - 1];

        public int Count { get => _Stack.Count; }

        public bool IsEmpty { get => _Stack.Count == 0; }
    }
}