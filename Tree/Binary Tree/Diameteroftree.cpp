  #include<queue>

      int height(Node* node){
      
      
      if(node==NULL){
            return 0;
      }
      
      int left=height(node->left);
      int right=height(node->right);
      
      if(left>right){
      return left+1;
      }
      
      else{
            return right+1;
      }
      
      
      }

      int diameter(Node* node) {
      int max=INT_MIN;
      queue<Node*>q;
      
      q.push(node);
      
      while(q.size()>0){
            
            Node*temp=q.front();
            q.pop();
            
            int tl=0;
            int tr=0;
            int p=0;
            
            
      // if(temp->left!=NULL && temp->right!=NULL){
            
            tl=height(temp->left);
            tr=height(temp->right);
            
            // cout<<"here"<<endl;
            
            p=tl+tr+1;
            
            if(p>max)
            {
                  max=p;
            }
      // }
            
      
            
      
      
            
            if(temp->left!=NULL)
            {
            
            q.push(temp->left);
                  
                  
            }
            
            if(temp->right!=NULL)
            {
            q.push(temp->right);
            }
            
            
      }
      
            return max;

      
      
      }