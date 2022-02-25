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
    
    void inorder(TreeNode* root,vector<int>& arr)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    
    
    bool findTarget(TreeNode* root, int k)
    {
        vector<int>arr;
        inorder(root,arr);
        int n = arr.size();
        int i=0,j=n-1;
        if(n<2)
        {
            return false;
        }
        while(i<j)
        {
            if(arr[i]+arr[j]==k)
            {
                return true;
            }
            else if(arr[i]+arr[j]>k)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};