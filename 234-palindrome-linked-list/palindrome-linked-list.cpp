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
        vector<int> store;
        ListNode* temp = head;
        store.push_back(temp->val);
        while(temp->next!=NULL){
            store.push_back(temp->next->val);
            temp = temp->next;
        }
        int n = store.size();
        int i=0;
        int j =n-1;
        while(i<=j){
        if(store[i]!=store[j]) return false;
        i++;
        j--;
        }
        return true;
    }
};