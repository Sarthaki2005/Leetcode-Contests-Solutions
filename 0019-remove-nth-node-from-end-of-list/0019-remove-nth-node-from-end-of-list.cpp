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
ListNode* deleteK(ListNode* head,int k){
    if(k==1){
        ListNode* temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    int cnt=1;
    ListNode* temp=head;
    while(temp!=NULL && cnt<k-1){
        cnt++;
        temp=temp->next;
    }
    ListNode* curr=temp->next;
    temp->next=curr->next;
    delete(curr);
    return head;

}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int  len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        int k=len-n+1;
        head=deleteK(head,k);
        return head;
    }
};