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
    ListNode* doubleIt(ListNode* head) {
        ListNode* node=head;
       vector<int>v;

       while(node){
        v.push_back(2*node->val);
        node=node->next;
       }
       int c=0;
       int n=v.size();
       for(int i=n-1;i>=0;i--){
        int x=(v[i]+c)%10;
         c=(v[i]+c)/10;
         v[i]=x;
       }
     
        int i=0;
        node=head;
        while(node){
            node->val=v[i];
            node=node->next;
            i++;
        }
        if(c){
            ListNode* temp=new ListNode();
            temp->val=1;
            temp->next=head;
            head=temp;
        }
        return head;
  
    }
};