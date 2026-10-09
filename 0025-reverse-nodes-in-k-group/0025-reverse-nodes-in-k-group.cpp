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
    ListNode* temp=head;
    int cnt=1;
    while(temp!=NULL && cnt<k){
        cnt++;
        temp=temp->next;
    }
    return temp;
}
ListNode* reverse(ListNode* head){
    ListNode* curr=head;
    ListNode* prev=NULL;
    while(curr!=NULL){
        ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL)
{
ListNode* kthNode=findKthNode(temp,k);

if(kthNode==NULL){
    if(prev) prev->next=temp;
    break;
}
cout<<"Kth Node: "<<kthNode->val;
ListNode* nextNode=kthNode->next;
kthNode->next=NULL;
reverse(temp);
if(temp==head){
    head=kthNode;
}
if(prev) prev->next=kthNode;
prev=temp;
temp=nextNode;
}   
return head;
 }
};