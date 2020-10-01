// We Can Do here any recursive traversal but here is the short trick where we do it in 
//the simple tree and it happen for whole  

 //                                  1
   //                               / \
     //                            2   3
// Write Code For it  like this 
//  get 2 get 3 check 2 and 3 with 1 which is smaller return that                                 
                                           
 

//Recursive

            int findMax(struct node* root)
            {
            int rootData,left,right,max=INT_MIN;
            
            if(root!=NULL){
                  rootData=root->data;
                  left=findMax(root->left);
                  right=findMax(root->right);
                  
                  if(left>right){
                        max=left;
                  }
                  else{
                        max=right;
                  }
                  if(rootData>max){
                        max=rootData;
                  }
                  
            }
            
            return max;
            }

            // Returns minimum value in a given Binary Tree
            int findMin(struct node* root)
            {
            int rootData,left,right,min=INT_MAX;
            
            if(root!=NULL){
                  rootData=root->data;
                  left=findMin(root->left);
                  right=findMin(root->right);
                  
                  if(left<right){
                        min=left;
                  }
                  else{
                        min=right;
                  }
                  if(rootData<min){
                        min=rootData;
                  }
                  
            }
            
            return min;
            }


//Iterative


    int findMax(struct node* root)
            {
            int max=INT_MIN;
            
            //stack<node*>s;
            queue<node*>q;
            
            q.push(root);
            
            while(q.size()!=0)
            {
                  node*temp=q.front();
                  q.pop();
                  if(temp->data>max){
                        max=temp->data;
                  }
                  
                  
                  if(temp->left!=NULL)
                  {
                        q.push(temp->left);
                  }
                  
                  if(temp->right!=NULL){
                        q.push(temp->right);
                  }
                  
                  
                  
            }
            
            
            return max;
            }

            // Returns minimum value in a given Binary Tree
            int findMin(struct node* root)
            {
            int min=INT_MAX;
            
            //stack<node*>s;
            queue<node*>q;
            
            q.push(root);
            
            while(q.size()!=0)
            {
                  node*temp=q.front();
                  q.pop();
                  if(temp->data<min){
                        min=temp->data;
                  }
                  
                  
                  if(temp->left!=NULL)
                  {
                        q.push(temp->left);
                  }
                  
                  if(temp->right!=NULL){
                        q.push(temp->right);
                  }
                  
                  
                  
            }
            
            
            return min;
            }
