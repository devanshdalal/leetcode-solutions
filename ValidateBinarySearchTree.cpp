/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
class Solution {
public:

    long long min(TreeNode* root){
        if(root==NULL)return (long long)INT_MAX + 1LL;
        return root->left!=NULL?min(root->left):root->val;
    }
    
    long long max(TreeNode* root){
        if(root==NULL)return -1LL + (long long)INT_MIN;
        return root->right!=NULL?max(root->right):root->val;
    }

    bool isValidBST(TreeNode* root) {
        if(root==NULL) return 1;
        if( isValidBST(root->left) and isValidBST(root->right) and max(root->left)<root->val and min(root->right)>root->val )return 1;
        return 0;
        
    }
};