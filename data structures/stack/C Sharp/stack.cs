using System;

namespace StackImplementation
{
  internal class Stack
  {
    static readonly int MAX = 1000;
    int top;
    int[] stack = new int[MAX];

    bool IsEmpty()
    {
      return (top < 0);
    }
    public Stack()
    {
      top = -1;
    }
    internal bool Push(int data)
    {
      if (top >= MAX)
      {
        Console.WriteLine("Stack Overflow");
        return false;
      }
      else
      {
        stack[++top] = data;
        return true;
      }
    }

    internal int Pop()
    {
      if (top < 0)
      {
        Console.WriteLine("Stack Underflow");
        return 0;
      }
      else
      {
        int value = stack[top--];
        return value;
      }
    }

    internal void Peek()
    {
      if (top < 0)
      {
        Console.WriteLine("Stack Underflow");
        return;
      }
      else
        Console.WriteLine("The topmost element of Stack is : {0}", stack[top]);
    }

    internal void PrintStack()
    {
      if (top < 0)
      {
        Console.WriteLine("Stack Underflow");
        return;
      }
      else
      {
        Console.WriteLine("Items in the Stack are :");
        for (int i = top; i >= 0; i--)
        {
          Console.WriteLine(stack[i]);
        }
      }
    }
  }

  class Program
  {
    static void Main(string[] args)
    {
      int n, num;
      Stack myStack = new Stack();

      Console.Write("Enter the number of stack items:");
      n = Convert.ToInt32(Console.ReadLine());
      Console.WriteLine("Enter the elements in stack:");
      while (n > 0)
      {
        num = Convert.ToInt32(Console.ReadLine());
        myStack.Push(num);
        n--;
      }
      myStack.PrintStack();
      myStack.Peek();
      Console.WriteLine("Item popped from Stack : {0}", myStack.Pop());
      myStack.PrintStack();
    }
  }
}
