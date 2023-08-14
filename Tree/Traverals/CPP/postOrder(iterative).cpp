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

// iterative function for postorder traversal
void postorder(TreeNode* root){
	stack<TreeNode*> st;
	while(true){ 
        while(root!=NULL){ 
            st.push(root); 
            st.push(root); 
            root=root->left; 
        } 
        if(st.empty()) return; 
        root=st.top(); 
        st.pop();
        if(!st.empty() && st.top()==root) root=root->right; 
       	else{ 
            cout<<root->val<<" "; 
            root=NULL;
        } 
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

    postorder(root);
    return 0;
}
