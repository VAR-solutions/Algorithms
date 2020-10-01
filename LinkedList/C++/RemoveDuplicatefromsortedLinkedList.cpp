  Node *removeDuplicates(Node *root)
      {
         struct Node*p1;
         struct Node*p2;
         p1=root;
         p2=root->next;
         
         
         while(p2!=NULL)
         {
            if(p1->data==p2->data){
                  
                  p1->next=p2->next;
                  
                  delete(p2);
                  
                  p2=p1->next;
                  continue;
            }
         
         p1=p1->next;
         p2=p2->next;
         }
         
         return root;
      // your code goes here
      }
