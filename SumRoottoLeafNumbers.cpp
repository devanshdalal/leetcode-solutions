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
    int sum(TreeNode* root,int curr) {
        if(root==NULL)return 0;
        int l=0,r=0;
        if(root->left==NULL and root->right==NULL)return curr*10+root->val;
        if(root->left!=NULL)l=sum(root->left,curr*10+root->val);
        if(root->right!=NULL)r=sum(root->right,curr*10+root->val);
        return l+r;
        
    }

    int sumNumbers(TreeNode* root) {
        return sum(root,0);
        
    }
};