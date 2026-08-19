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
    TreeNode* solve(int &idx,int start,int end,vector<int>&inorder,vector<int>&postorder){
        if(start>end) return NULL;
        int rootval = postorder[idx];
        int indx = end;
        for(;indx>=start;indx--){
            if(rootval==inorder[indx]) break;
        }
        idx--;
        TreeNode* root = new TreeNode(rootval);
        root->right = solve(idx,indx+1,end,inorder,postorder);
        root->left = solve(idx,start,indx-1,inorder,postorder);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int idx = n-1;
         return solve(idx,0,n-1,inorder,postorder);
    }
};