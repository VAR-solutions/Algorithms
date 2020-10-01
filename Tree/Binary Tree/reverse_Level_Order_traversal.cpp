     vector<int> reverseLevelOrder(Node *root)
            {
                  queue <Node*> q;
                  stack<Node*>s;
                  vector<int>v;
                  
                  
                  
                  q.push(root);
                  
                  while(q.size()!=0){
                        Node*temp=q.front();
                        q.pop();
                        
                        s.push(temp);
                        
                        
                        if(temp->right!=NULL){
                              q.push(temp->right);
                        }
                        
                        if(temp->left!=NULL){
                              q.push(temp->left);
                        }
                        
                        
                  }
                  
                  while(s.size()!=0){
                        v.push_back(s.top()->data);
                        s.pop();
                  }
                  
                  
                  
                  return v;
                  
                  
            }
