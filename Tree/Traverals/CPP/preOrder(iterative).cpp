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

// iterative function for preorder traversal
void preOrder(TreeNode* root){
	stack<TreeNode*> st;
	st.push(root);
	while(!st.empty()){
		TreeNode* temp=st.top();
		st.pop();
		cout<<temp->val<<" ";
		if(temp->right) st.push(temp->right);
		if(temp->left) st.push(temp->left);
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

    preOrder(root);
    return 0;
}
