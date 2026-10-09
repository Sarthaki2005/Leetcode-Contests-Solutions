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
ListNode* findKthNode(ListNode* head,int k){
    int cnt=1;
    ListNode* temp=head;
    while(temp!=NULL && cnt<k){
        cnt++;
        temp=temp->next;
    }
    return temp;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
       
        int N=0;
        ListNode* temp=head;
        while(temp!=NULL){
            N++;
            temp=temp->next;
        }
        if(N==1) return head;
        k=k%N;
         if(k==0) return head;
        int kth=N-k;
        ListNode* kthNode=findKthNode(head,kth);
        ListNode* newHead=kthNode->next;
         temp=newHead;
        while(temp->next!=NULL){
            temp=temp->next;

        }
        temp->next=head;
        kthNode->next=NULL;
        return newHead;
    }
};