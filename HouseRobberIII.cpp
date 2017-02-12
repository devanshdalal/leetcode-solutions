/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 #include<pair>
 
pair<int,int> better_robber(TreeNode* root) {
    if(root==NULL)return make_pair(0,0);
    pair<int,int> p=better_robber(root->left);
    pair<int,int> q=better_robber(root->right);
    return make_pair( root->val+ p.second + q.second , max(p.second,p.first) + max(q.second,q.first) );
    
    
}
 
class Solution {
public:
    int rob(TreeNode* root) {
          pair<int,int> res = better_robber( root );
          
          return max(res.first,res.second);
          
    }
};