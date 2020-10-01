//Recursively 

int height(Node* root)
      {
      
      if(root==NULL){
            return 0;
      }
      int leftHeight=height(root->left);
      int rightHeight=height(root->right);
      
      if(leftHeight>rightHeight){
            return leftHeight+1;
      }
      else{
            return rightHeight+1;
      }
      
      
      
      
      }


// Iteratively

int height(Node* root)
      {
      
      if(root==NULL){
            return 0;
      }
      int leftHeight=height(root->left);
      int rightHeight=height(root->right);
      
      if(leftHeight>rightHeight){
            return leftHeight+1;
      }
      else{
            return rightHeight+1;
      }
      
      
      
      
      }

