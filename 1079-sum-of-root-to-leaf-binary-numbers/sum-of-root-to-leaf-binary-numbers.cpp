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
    void solve(TreeNode* root,vector<int>store,int&ans){
        store.push_back(root->val);
        if(!root->left&&!root->right){
            int n = store.size();
            int sum =0;
            int mul = 0;
            for(int i =n-1;i>=0;i--){
                sum+=pow(2,mul)*store[i];
                mul++;
            }
            ans+=sum;
            // store.pop_back();
            return ;
        }
        if(root->left){
            solve(root->left,store,ans);
        }
        if(root->right){
            solve(root->right,store,ans);
        }
        // store.pop_back();
        return ;
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> store;
        int ans=0;
        solve(root,store,ans);
        return ans;
    }
};