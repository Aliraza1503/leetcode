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
    void solve(TreeNode* root,vector<int>&store,vector<vector<int>>&ans){
        store.push_back(root->val);
        if(!root->left&&!root->right){
            ans.push_back(store);
            store.pop_back();
            return ;
        }
        if(root->left){
            solve(root->left,store,ans);
        }
        if(root->right){
            solve(root->right,store,ans);
        }
        store.pop_back();
        return ;
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> store;
        vector<vector<int>> ans;
        solve(root,store,ans);
        int temp =0;
        for(int i =0;i<ans.size();i++){
            int n = ans[i].size();
            int cap =0;
            int st = 0;
            for(int j=n-1;j>=0;j--){
                cap+=pow(2,st)*ans[i][j];
                st++;
            }
            temp+=cap;
        }
        return temp;
    }
};