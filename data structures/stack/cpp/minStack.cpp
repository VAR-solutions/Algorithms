/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.
*/
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */

    MinStack() 
    {
     	  stack<int> main_stack;
     	  stack<int> min_stack;
    }
    
    void push(int x) 
    {
     	int min=x;
     	if(!min_stack.empty())
     	{
     		if(min>min_stack.peek())
     		{
     			min=min_stack.peek();
     		}
     	}
     	main_stack.push_back(x);
     	min_stack.push_back(min);   
    }
    
    void pop() 
    {
    	if(min_stack.empty())
    	{
    		cout << "stack is empty!"<<endl; 
    	}
    	else
    	{
    		min_stack.pop_back();
    		main_stack.pop_back();
    	}	
    }
    
    void peek() 
    {
    	if(main_stack.empty())
    	{
    		cout << "stack is empty!"<<endl; 
    	}
    	else
    	{
    		cout << main_stack.top(); 
    	}
    		
    }
    
    void getMin() 
    {
    	if(min_stack.empty())
    	{
    		cout << "stack is empty!"<<endl; 
    	}
    	else
    	{
    		cout << min_stack.top(); 
    	}
    }
};

int main()
{
	MinStack obj=new MinStack();
	obj.push(3); 
    obj.push(5); 
    obj.getMin(); 
    obj.push(2); 
    obj.push(1); 
    obj.getMin(); 
    obj.pop(); 
    obj.getMin(); 
    obj.pop(); 
    obj.peek(); 
	return 0;
}