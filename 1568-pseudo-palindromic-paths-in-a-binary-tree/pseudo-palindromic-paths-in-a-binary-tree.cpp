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
    int check(vector<int>&temp){
        int count =0;
        for(auto it:temp){
            if(it%2!=0){
                count++;
                if(count>=2){
                    return 0;
                }
            }
        }
        return 1;
    }
    void solve(TreeNode* root,vector<int>&store,int &ans,vector<int>&temp){
        store.push_back(root->val);
        temp[root->val]++;
        if(!root->left&&!root->right){
            ans+=check(temp);
            // store.pop_back();
            temp[root->val]--;
            return;
        }
        if(root->left){
            solve(root->left,store,ans,temp);
        }
        if(root->right){
            solve(root->right,store,ans,temp);
        }
        // store.pop_back();
        temp[root->val]--;
        // return ;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans =0;
        vector<int> store;
        vector<int> temp(10);
        solve(root,store,ans,temp);
        return ans;
    }
};