#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data){ 
        this->val=data; 
        left=NULL;
        right=NULL;
    } 
};

// iterative function for inorder traversal
void inorder(TreeNode* root){ 
	stack<TreeNode*> st;
	while(root || !st.empty()){
		while(root){
			st.push(root);
			root=root->left;
		}
		TreeNode* temp=st.top();
		st.pop();
		cout<<temp->val<<" ";
		root=temp->right;
	}
}
int main(){
	
	/* Constructed binary tree is 
              1 
            /   \ 
          2      3 
        /  \ 
      4     5 
    */

	  TreeNode *root=new TreeNode(1); 
    root->left=new TreeNode(2); 
    root->right=new TreeNode(3); 
    root->left->left=new TreeNode(4); 
    root->left->right=new TreeNode(5);

    inorder(root);
    return 0;
}
