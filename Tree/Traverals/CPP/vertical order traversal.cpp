/*----STRUCTURE OF TREE NODE-----*/
/*
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
*/

/*-------- FUNCTION FOR VERTICAL ORDER TRAVERSAL---------*/

void PrintVerticalOrder(TreeNode* root, int d, map<int, vector<int> > &m){
    if(root==NULL){
        return;
    }
    m[d].push_back(root->val);
    PrintVerticalOrder(root->left,d-1,m);
    PrintVerticalOrder(root->right,d+1,m);
}

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