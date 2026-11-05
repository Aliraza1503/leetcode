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
    TreeNode* solve(TreeNode* temp,int val){
        if(!temp) return NULL;
        if(temp->val==val) return temp;
        
        if(temp->val>val){
           return  solve(temp->left,val);
        }
       return  solve(temp->right,val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
       return solve(root,val);
    }
};