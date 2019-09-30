#include <bits/stdc++.h>

using namespace std;

class Node{
	public:
		Node* left;
		Node* right;
		int data;
		Node(int x){
			data = x;
			left = NULL;
			right = NULL;
		}
};

class Solution{
	public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

		Node* flatten(Node* A) {
		    if(!A)return NULL;

		    // Take the left and right subtree
		    Node* tempr = A->right;
	        Node* templ = A->left;
	        
	        // Recursively Flatten them
	        flatten(templ);
	        flatten(tempr);

	        // If left subtree exists, place it as the right subtree and make the right subtree
	        // as the child of this new right subtree
	        if(templ){
	            A->right = templ;
	            Node* x = templ;
	            // Go to the end of the right subtree (which was earlier left subtree)
	            while(x->right){
	                x = x->right;
	            }
	            // Place the earlier right subtree as the right subtree of the current right subtree
	            x->right = tempr;

	            // Make the new left subtree as NULL
	            templ->left = NULL;
	        }
	       	
	       	// Nullify the left subtree.
	       	A->left = NULL;

	       	// Return the tree.
	        return A;
		}

		void inOrder(Node* tree){
			if(!tree) return;

			inOrder(tree->left);
			cout << tree->data << " " ;
			inOrder(tree->right);
		}
};

// Initial Tree:
//			  4
//			/	\
//		   2	 7
//	      /	\	/
//	     1	 3 6

// Final Tree:
// 			  4
// 			/	\
//		   N     2
//				/ \
//			   N   1
//	   			  / \
//			     N   3
//				    / \
//			       N   7
//				      / \
//			         N   6
// N - NULL


int main() {
	Solution myTree;
	Node* root = NULL;
	root = myTree.insert(root,4);
	root = myTree.insert(root,2);
	root = myTree.insert(root,3);
	root = myTree.insert(root,1);
	root = myTree.insert(root,7);
	root = myTree.insert(root,6);
	
	cout << "InOrder Traversal is of the tree is as follows: " << endl;
	myTree.inOrder(root);
	cout << endl;
	

	myTree.flatten(root);
	cout << "\n\nInOrder Traversal is of the flattened tree is as follows: " << endl;
	myTree.inOrder(root);
	cout << endl;
	return 0;
}

