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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if(root==NULL)return ans; 
        stack< pair<TreeNode*,int> > s;
        TreeNode* it=root;
        // while(it!=NULL){
        //     s.push( make_pair(it,0) );
        //     it=it->left;
        // }
        s.push( make_pair(it,0) );
        
        while(!s.empty()){
            auto tp = s.top(); s.pop();
            
            if(tp.second==2){
                ans.push_back(tp.first->val);
            }else if(tp.second==1){
                tp.second=2;
                s.push(tp);
                it=tp.first->right;
                if(it!=NULL)s.push(make_pair(it,0) );
            }else{
                tp.second=1;
                s.push(tp);
                it=tp.first->left;
                if(it!=NULL)s.push(make_pair(it,0) );
            }
            
            
        }
        
        return ans;
        
        
        
    }
};