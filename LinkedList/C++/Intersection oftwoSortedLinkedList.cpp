 
   Node* findIntersection(Node* head1, Node* head2)
   {
      struct Node*newNode=new Node(0);
      
      struct Node*ptr=newNode;
      
      while(head1!=NULL&&head2!=NULL)
      {
         if(head1->data==head2->data)
         {
               struct Node*temp=new Node(head1->data);
               
               ptr->next=temp;
               
               ptr=temp;
               
               head1=head1->next;
               head2=head2->next;
               
         }
         
         
         else if(head1->data>head2->data)
         {
               
               head2=head2->next;
               
         }
         
         
         else{
               
               head1=head1->next;
               
         }
         
         
      }
      
      newNode=newNode->next;
      
      return newNode;
      
      
   }