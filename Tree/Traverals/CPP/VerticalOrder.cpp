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

// iterative function for Vertical order traversal
void verticalOrderTraversal(TreeNode* root){
	map<int, vector<int>> mp;
	queue<pair<TreeNode*,int>> q;
	q.push(make_pair(root,0));
	while(!q.empty()){
		pair<TreeNode*,int> p=q.front();
		q.pop();
		TreeNode* temp=p.first;
		int level=p.second;
		mp[level].push_back(temp->val);
		if(temp->left!=NULL) q.push(make_pair(temp->left,level-1));
		if(temp->right!=NULL) q.push(make_pair(temp->right,level+1));
	}
	for(auto i:mp){
		vector<int> v=i.second;
		for(int j=0;j<v.size();j++){
			cout<<v[j]<<" ";
		} cout<<endl;
	}
}
int main(){
	
	/* Constructed binary tree is 
              1 
            /   \ 
          2      3 
         / \ 	  / \
      	4   5  6   7
      			    \	  \
      			     8	 9
    */

	  TreeNode *root=new TreeNode(1); 
    root->left=new TreeNode(2); 
    root->right=new TreeNode(3); 
    root->left->left=new TreeNode(4); 
    root->left->right=new TreeNode(5); 
    root->right->left=new TreeNode(6); 
    root->right->right=new TreeNode(7); 
    root->right->left->right=new TreeNode(8); 
    root->right->right->right=new TreeNode(9);

    verticalOrderTraversal(root);
    
    return 0;
}
