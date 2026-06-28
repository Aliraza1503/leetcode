/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,int t,vector<vector<int>>&ans,vector<int>&store){
        store.push_back(root->val);
        if(!root->left&&!root->right){
            if(root->val==t){
            ans.push_back(store);
            }
            store.pop_back();
            return ;
        }
        if(root->left){
            solve(root->left,t-root->val,ans,store);
        }
        if(root->right){
            solve(root->right,t-root->val,ans,store);
        }
        store.pop_back();
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> store;
        vector<vector<int>> ans;
        if(!root) return ans;
        solve(root,targetSum,ans,store);
        return ans;
    }
};