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
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int>arr1,arr2,arr3;
        inorder(root1,arr1);
        inorder(root2,arr2);
        for(int i=0;i<arr1.size();i++)
        {
            arr3.push_back(arr1[i]);
        }
        for(int i=0;i<arr2.size();i++)
        {
            arr3.push_back(arr2[i]);
        }
        sort(arr3.begin(),arr3.end());
        return arr3;
    }
};