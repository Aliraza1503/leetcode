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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(auto it:nums){
            st.insert(it);
        }
        //try by taking dummy node
        ListNode* dummy = new ListNode(0,head);
        head = dummy;
        ListNode* temp = dummy;
        while(temp->next!=NULL){
            if(st.contains(temp->next->val)){
                temp->next = temp->next->next;
            }
            else{
                temp = temp->next;
            }
        }
        return dummy->next;
    }
};