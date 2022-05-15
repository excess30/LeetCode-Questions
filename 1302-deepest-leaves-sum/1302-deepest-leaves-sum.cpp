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
    int deepestLeavesSum(TreeNode* root) 
    {
        queue<TreeNode*>q;
        if(root==NULL)
        {
            return 0;
        }
        int sum=0;
        q.push(root);
        while(q.empty()==false)
        {
            int sz=q.size();
            sum=0;
            while(sz--)
            {
                auto curr=q.front();
                q.pop();
                sum+=curr->val;
                if(curr->left!=NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                    q.push(curr->right);
                }
            }
        }
        return sum;
    }
};