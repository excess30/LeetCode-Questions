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
    int res;
    int help(TreeNode *root)
    {
        if(!root)
            return 0;
        int l=help(root->left);
        int r=help(root->right);
        res=max(res,max(root->val,max(root->val+l+r,root->val+max(l,r))));
        return max(root->val,root->val+max(l,r));
    }
    int maxPathSum(TreeNode* root) {
        res=INT_MIN;
        if(!root)
            return 0;
        int x=help(root);
        return max(res,x);
    }
};
