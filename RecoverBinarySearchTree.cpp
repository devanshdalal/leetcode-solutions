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

    bool done=0;
    TreeNode* prev=NULL;
    TreeNode* first,*second;
    
    void inorder(TreeNode* a){
        if(a==NULL)return;
        inorder(a->left);
    
        if(!done and prev!=NULL and prev->val>a->val){
            first=prev;
            second=a;
            done=1;
        }else if(prev!=NULL and prev->val>a->val){
            second = a;
        }
        
        prev=a;
        inorder(a->right);
        
        
    }

    void recoverTree(TreeNode* root) {
        
        done=0;
        prev=NULL;
        
        inorder(root);
        
        if(first && second)
        swap(first->val,second->val);
        
        
        
    }
};