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
ListNode* createList(vector<int> &ans){
    int n=ans.size();
    ListNode* dummy=new ListNode(0);
    ListNode* temp=dummy;
    for(int i=0;i<n;i++){
        ListNode* node=new ListNode(ans[i]);
        temp->next=node;
        temp=temp->next;
      


    }
    return dummy->next;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> ans;
        int carry=0,sum=0;
        while(l1!=NULL && l2!=NULL){
          sum=carry+l1->val+l2->val;
          carry=sum/10;
          int d=sum%10;
          ans.push_back(d);
          l1=l1->next;
          l2=l2->next;
        }
        while(l1!=NULL){
             sum=carry+l1->val;
          carry=sum/10;
          int d=sum%10;
          ans.push_back(d);
          l1=l1->next;
        }
        while(l2!=NULL){
             sum=carry+l2->val;
          carry=sum/10;
          int d=sum%10;
          ans.push_back(d);
          l2=l2->next;
        }
           if(carry!=0){
            ans.push_back(carry);

           }
          ListNode* res=createList(ans);
          return res;
    }
};