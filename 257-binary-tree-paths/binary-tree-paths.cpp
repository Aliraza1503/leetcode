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
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> store;
        vector<vector<int>> ans;
        solve(root,store,ans);
        vector<string> temp;
        for(int i =0;i<ans.size();i++){
            string st ="";
            int n = ans[i].size();
            for(int j=0;j<n-1;j++){
                string ch = to_string(ans[i][j]);
                st+=ch+"->";
            }
            st+=to_string(ans[i][n-1]);
            temp.push_back(st);
        }
        return temp;
    }
};