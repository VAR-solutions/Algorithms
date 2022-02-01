/*

https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

*/

#include <iostream>
#include <sstream>
#include <string>
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : val(0), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    int carry=0;
    ListNode* ptr= new ListNode(0);
    ListNode* start=ptr;
    while(l1!=NULL || l2!=NULL)
    {
        if(l1==NULL)
        {
            ptr->next = new ListNode((l2->val+carry)%10);
            carry=(l2->val+carry)/10;
            l2=l2->next;
            ptr=ptr->next;
        }
        else if(l2==NULL)
        {
            ptr->next = new ListNode((l1->val+carry)%10);
            carry=(l1->val+carry)/10;
            l1=l1->next;
            ptr=ptr->next;
        }
        else
        {
            ptr->next = new ListNode((l1->val+l2->val+carry)%10);
            carry=(l1->val+l2->val+carry)/10;
            l1=l1->next;
            l2=l2->next;
            ptr=ptr->next;
        }
    }
    if (carry>0)
    {
        ptr->next = new ListNode(carry);
        ptr=ptr->next;
    }
    return start->next;
}

// the code below does not change
void insert(ListNode** root, int item)
{
    ListNode* temp = new ListNode;
    ListNode* ptr;
    temp->val = item;
    temp->next = NULL;

    if (*root == NULL)
        *root = temp;
    else {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

void display(ListNode* root)
{
while (root != NULL)
  {
    std::cout << root->val << " ";
    root = root->next;
  }
}

int main(int argc, char const *argv[])
{
  ListNode *number1 = new ListNode();
  ListNode *number2 = new ListNode();
  int input,length=0;
  std::string line;
  std::cout << "Enter a vector of numbers between 0 and 9 that together form an integer in reverse order without leading Zeroes. for Ex : 807 will be entered as 7 0 8. if there are invalid numbers they will be discarded. " << '\n';
  std::getline(std::cin, line);
  std::istringstream stream(line);
  while (stream >> input && length<=100)
  {
    if(input <=9 && input>=0)
    {
        insert(&number1, input);
        length++;
    }
  }
  std::cout << "Enter a vector of numbers between 0 and 9 that together form an integer in reverse order without leading Zeroes. for Ex : 807 will be entered as 7 0 8. if there are invalid numbers they will be discarded. " << '\n';
  std::getline(std::cin, line);
  std::istringstream stream2(line);
  length =0;
  while (stream2 >> input && length<=100)
  {
    if(input <=9 && input>=0)
    {
        insert(&number2, input);
        length++;
    }
  }
  ListNode* answerHead = addTwoNumbers(number1->next,number2->next);
  std::cout << "after Adding the value is " << '\n';
  display(answerHead);
  std::cout << '\n';
  return 0;
}
/* this solution was 20ms */
