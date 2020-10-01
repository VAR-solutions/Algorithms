  // iteratively
  
  #include<queue>



      void mirror(Node* node) 
      {
      queue<Node*>q;
      
      
      q.push(node);
      
      
      while(q.size()>0){
            
            Node*temp=q.front();
            q.pop();
            
            Node*temp1=temp->left;
            
            temp->left=temp->right;
            
            temp->right=temp1;
            
            
            
            if(temp->left!=NULL)
            {
            q.push(temp->left);
            }
            
            if(temp->right!=NULL)
            {
            q.push(temp->right);
            }
            
            
            
            
      }
      }



   //Recursively


      void mirror(Node* node) 
            {
            
            if(node==NULL)
            {
                  return ;
            }
                  
                  
            Node*temp=node->left;
            node->left=node->right;
            
            node->right=temp;
            
            mirror(node->left);
            
            mirror(node->right);
            
            
            
            
            
            }

               