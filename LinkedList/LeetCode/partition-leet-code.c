/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    
    struct ListNode *small, *large;
    struct ListNode *p = head;
    struct ListNode *s,*l;
    small = large = NULL;
    
    if(p==NULL)
    {
        return p;
    }
    else{
    while(p!=NULL)
    {
        if(p->val<x)
        {
            if(small != NULL)
            {
                small->next = p;
                p = p->next;
                small = small->next;
                small->next = NULL;
            }
            else{
                small = p;
                p = p->next;
                small->next = NULL;
                s = small;
            }
        }
        else{
            if(large != NULL)
            {
                large->next = p;
                p = p->next;
                large = large->next;
                large->next = NULL;
            }
            else{
                large = p;
                p = p->next;
                large->next = NULL;
                l = large;
            }
        }
    }
    }
    if(large==NULL)
    {
        return head;
    }
    else if(small==NULL){
        return head;
    }
    else{
        small->next = l;
        head = s;
        return head;
    }
}