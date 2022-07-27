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
//     void reorderList(ListNode* head) {
//         if(!head || !head->next) 
//             return;
        
//         ListNode *slow = head, *fast = head;
//         while(fast && fast->next){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         ListNode *prev = nullptr, *curr = slow, *tmp;
//         while(curr){
//             tmp = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = tmp;
//         }
        
//         ListNode *n1 = head, *n2 = prev;
//         while(n2->next){
//             tmp = n1->next;
//             n1->next = n2;
//             n1 = tmp;
            
//             tmp = n2->next;
//             n2->next = n1;
//             n2 = tmp;
//         }
//     }


// or

void reorderList(ListNode* head) 
    {
	
	    //in case of a list with <=2 nodes, no change is required
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr)
            return;	
		
		//last here is actually the 2nd last node of the list
        ListNode *last=head;
        while(last->next->next) 
            last=last->next;
			
		//moving the last node right next to the front node
        last->next->next=head->next;
        head->next=last->next;
        last->next=nullptr;
        reorderList(head->next->next);
    }

};



