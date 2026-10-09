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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int> mp;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            
           
                mp[temp->val]+=1;
                
                temp=temp->next;
            
        }
        temp=head;
        while(temp!=NULL){
                if(mp[temp->val]>1){

                    ListNode* curr=temp;
                    if(temp==head){
                    head=head->next;
                    }
                    else prev->next=temp->next;
                    temp=temp->next;
                    delete(curr);
                }
           else{
            prev=temp;
            temp=temp->next;
           }
               
            
        }

        return head;
    }
};