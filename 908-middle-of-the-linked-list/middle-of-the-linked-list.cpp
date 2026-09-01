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
    ListNode* middleNode(ListNode* head) {
        int cnt =1;
        ListNode* temp = head;
        if(head->next==NULL){
            return head;
        }
        while(temp->next){
            cnt++;
            temp=temp->next;
        }
        cnt = (cnt/2)+1;
        int start =2;
        ListNode* dummy = head;
        while(start<cnt){
            dummy->next= dummy->next->next;
            start++;
        }
       
        dummy = dummy->next;
        return dummy;

    }
};