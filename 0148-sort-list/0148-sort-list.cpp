/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* merge(ListNode* l1,ListNode* l2){
ListNode* dummyNode=new ListNode(-1);
ListNode* temp=dummyNode;
while(l1!=NULL && l2!=NULL){
    if(l1->val<=l2->val){
        temp->next=l1;
        temp=temp->next;
        l1=l1->next;
    }else{
        temp->next=l2;
        temp=temp->next;
        l2=l2->next;
    }
}
while(l1!=NULL){
     temp->next=l1;
        temp=temp->next;
        l1=l1->next;
}
while(l2!=NULL){
     temp->next=l2;
        temp=temp->next;
        l2=l2->next;
}
return dummyNode->next;
}
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast!=NULL &&  fast->next!=NULL){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        ListNode* left=NULL;
        ListNode* right=NULL;
        if(fast==NULL){
            prev->next=NULL;
            left=sortList(head);
            right=sortList(slow);
        }else{
        ListNode* temp=slow->next;
        slow->next=NULL;
         left= sortList(head);
         right=sortList(temp);
        }
      
        return merge(left,right);
    }

};