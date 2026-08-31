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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = new ListNode(0,head);
        // temp->next = head;
        head = temp;
        ListNode* dummy = temp;
        while(dummy->next!=NULL){
            if(dummy->next->val==val){
                dummy->next=dummy->next->next;
            }
            else dummy = dummy->next;
        }
        return temp->next;
    }
};