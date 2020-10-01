 int countNodesinLoop(struct Node *head)
   {
      
      struct Node*s=head;
      struct Node*f=head->next;
      
      bool isLoop=false;
      while((f!=NULL)&&(f->next!=NULL))
      {
         if(s==f)
         {
               isLoop=true;
               break;
         }
         
         f=f->next->next;
         s=s->next;
      }
      
      
      if(isLoop==true)
      {
         struct Node*temp=f->next;
         
         int count=1;
         
         
         while(temp!=s)
         {
               count++;
               temp=temp->next;
         }
      
      
      return count;   
      }
      
      else{
         return 0;
      }
      
      
      
      // Code here
   }

