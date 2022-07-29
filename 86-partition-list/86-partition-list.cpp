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
    ListNode* partition(ListNode* head, int x) {
        ListNode * small=new ListNode(0);
        ListNode * high=new ListNode(0);
        
        ListNode * smallhead=small;
        ListNode * highhead=high;
        
        while(head){
            if(head->val<x){
                smallhead->next=head;
                smallhead=smallhead->next;
            }
            else{
                highhead->next=head;
                highhead=highhead->next;
            }
            head=head->next;
        }
        
        highhead->next=NULL;
        smallhead->next=high->next;
       
        return small->next;
    }
};