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
    
    TreeNode* convertTree(vector<int>& nums,int s, int e)
    {
        int n = nums.size();
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = convertTree(nums,s,mid-1);
            root->right = convertTree(nums,mid+1,e);
            return root;
        }
        return NULL;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return convertTree(nums,0,nums.size()-1);
    }
};