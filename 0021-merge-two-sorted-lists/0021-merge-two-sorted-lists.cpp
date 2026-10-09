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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp=NULL;
        ListNode* curr1=list1;
        ListNode* curr2=list2;
        ListNode* newHead=NULL;
        while(curr1!=NULL && curr2!=NULL){
            if(curr1->val<=curr2->val){
                if(temp==NULL){
                    temp=curr1;
                    newHead=curr1;
                }else{
                    temp->next=curr1;
                     temp=temp->next;
                }
                curr1=curr1->next;
            }else{
                if(temp==NULL){
                    temp=curr2;
                    newHead=curr2;
                }else{
                    temp->next=curr2;
                     temp=temp->next;
                }
                curr2=curr2->next;
            }
           
        }
        while(curr1!=NULL){
             if(temp==NULL){
                    temp=curr1;
                    newHead=curr1;
                }else{
                    temp->next=curr1;
                    temp=temp->next;
                }
                 curr1=curr1->next;
                
        }
        while(curr2!=NULL){
              if(temp==NULL){
                    temp=curr2;
                    newHead=curr2;
                }else{
                    temp->next=curr2;
                     temp=temp->next;
                }
                curr2=curr2->next;
             
        }
        return newHead;
    }
};