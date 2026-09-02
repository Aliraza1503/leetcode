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
    bool isPalindrome(ListNode* head) {
        //my approach would be like check for odd palindrome 

        ListNode* first = head;
        ListNode* second = head;
       
        while(second->next!=NULL&&second->next->next!=NULL){
        
            first = first->next;
            second = second->next->next;
        }
      second = first->next;
      ListNode* prev = NULL;
    
      while(second!=NULL){
      ListNode*  nnext = second->next;
        second->next = prev;
        prev = second;
        second = nnext;
      }

      ListNode* temp = head;
      while(prev!=NULL){
        if(prev->val!=temp->val) return false;
        prev = prev->next;
        temp = temp->next;
      }
      return true;
    }
};