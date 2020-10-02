package com.CP;

/*
Given a singly linked list, group all odd nodes together followed by the even nodes. 
Please note here we are talking about the node number and not the value in the nodes.
You should try to do it in place. The program should run in O(1) space complexity 
and O(nodes) time complexity.
Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL*/

class ListNode {
	int data;
	ListNode next;

	public ListNode() {
		next = null;
	}

	public ListNode(int data) {
		this.data = data;
		next = null;
	}

}

public class OddEven_LinkedList {

	public static void main(String[] args) {

		ListNode head = new ListNode(1);
		head.next = new ListNode(2);
		head.next.next = new ListNode(3);
		head.next.next.next = new ListNode(4);
		head.next.next.next.next = new ListNode(5);
		
		// Original Linked List
		print(head);

		ListNode ptr=null;
		// O(n) Space Solution
		/*
		 * ptr = oddEvenList1(head);
		 * 
		 * print(head);
		 */		
		
		// O(1) Space Solution
		ptr = oddEvenList2(head);		
				
		print(head);

	}

	// O(n) Space Solution

	public static ListNode oddEvenList1(ListNode head) {

		if (head == null || head.next == null || head.next.next == null)
			return head;

		ListNode temp, ptr, ptr2, ptr3, ptr4;

		ptr = head;

		ptr2 = new ListNode(0);
		ptr3 = ptr2;
		temp = new ListNode(0);
		ptr4 = temp;

		int i = 1;
		while (ptr != null) {
			if (i % 2 != 0) {
				ptr2.next = ptr;
				ptr2 = ptr2.next;
				ptr = ptr.next;
			} else if (i % 2 == 0) {
				temp.next = new ListNode(ptr.data);
				temp = temp.next;
				ptr = ptr.next;
			}
			i++;
		}

		ptr2.next = ptr4.next;

		return ptr3.next;
	}

	// OPTIMIZE SOLUTION O(1) Space Solution

	public static ListNode oddEvenList2(ListNode head) {

		if (head == null)
			return head;

		ListNode oddHead = head;
		ListNode oddPtr = oddHead;
		ListNode evenHead = head.next;
		ListNode evenPtr = evenHead;

		while (oddPtr.next != null && evenPtr.next != null) {
			oddPtr.next = evenPtr.next;
			oddPtr = oddPtr.next;

			evenPtr.next = oddPtr.next;
			evenPtr = evenPtr.next;
		}

		oddPtr.next = evenHead;

		return oddHead;

	}

	public static void print(ListNode head) {

		while (head != null) {
			System.out.print(head.data+" ");
			head = head.next;
		}
		
		System.out.println();
	}

}
