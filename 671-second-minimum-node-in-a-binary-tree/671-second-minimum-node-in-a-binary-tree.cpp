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
    void inorder(TreeNode* root, vector<int>& arr)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    
    int findSecondMinimumValue(TreeNode* root) 
    {
        vector<int>arr;
        set<int>s;
        inorder(root,arr);
        for(auto x:arr)
        {
            s.insert(x);
        }
        if(s.size()==1||s.size()==0)
        {
            return -1;
        }
        int x = *std::next(s.begin(), 1);
        return x;
    }
};