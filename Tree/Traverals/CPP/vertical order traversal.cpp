/*---Problem Description---*/
//problem description can be found at: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

/*---video tutorial of approach used---*/
// link: https://www.youtube.com/watch?v=4w2Ri4VhgZo&list=PLjhq5EHRYAeLdh0xtn2v7wbQsVc8WAB2e&index=6&ab_channel=CodeCampaign

#include<bits/stdc++.h>
#include<sstream>
using namespace std;

/*----STRUCTURE OF TREE NODE-----*/

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode (int data){
        this->val=data;
        this->left=NULL;
        this->right=NULL;
    }
};


// Function to Build Tree 

TreeNode* Buildtree()
{
    int a;
    cin >> a;
    TreeNode *root = new TreeNode(a);
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        cin >> a;
        if (a != -1)
        {
            TreeNode *temp = new TreeNode(a);
            if (q.front()->left == NULL){
                q.front()->left = temp;
            }
            else
            {
                q.front()->right = temp;
                q.pop();
            }
            q.push(temp);
        }
        else
        {
            if (q.front()->left == NULL)
            {
                cin >> a;
                if (a == -1){
                    q.pop();
                }
                else{
                    TreeNode *temp1 = new TreeNode(a);
                    q.front()->right = temp1;
                    q.pop();
                    q.push(temp1);
                }
            }
            else{
                q.pop();
            }
        }
    }
    return root;
}


/*-------- FUNCTION FOR VERTICAL ORDER TRAVERSAL---------*/

void PrintVerticalOrder(TreeNode* root, int d, map<int, vector<int> > &m){
    if(root==NULL){
        return;
    }
    m[d].push_back(root->val);
    PrintVerticalOrder(root->left,d-1,m);
    PrintVerticalOrder(root->right,d+1,m);
}

// Driver Code

int main(){
	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	//Buildtree is function to build tree (as per input or your convienience, you can define it)
    TreeNode* root=Buildtree();
	

    map<int,vector<int> > m;
    PrintVerticalOrder(root,0,m);
	
	//printing the vertical order traversal
    for(auto p:m){
        for(auto x:p.second){
            cout<<x<<" ";
        }
        cout<<endl;
    }


    return 0;
}

/*---- SAMPLE INPUT/OUTPUT FOR A TREE ----*/
/*
input : 1 2 3 4 5 6  -1 -1 -1 -1 -1 -1 -1
tree corresponding to the input: 

             1
          /      \
       2           3
    /     \       /
   4       5     6

output:
4
2
1 5 6
3
this is the vertical order traversal of a tree
*/