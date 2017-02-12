/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

string inorder(TreeNode* root ){
    if(root==NULL)return "";
    // cout << " here " << endl;
    
    // long long c=(long long)root;
    
    return inorder(root->left)+" " + to_string(  (int)(size_t)root ) + " " +  to_string(root->val) +" " + inorder(root->right);
} 

string preorder(TreeNode* root ){
    if(root==NULL)return "";
    return to_string( (int)(size_t)root) + " " +  to_string(root->val) + " " + preorder(root->left)+ " " + preorder(root->right);
}

TreeNode* restore(vector<pair<int,int> > in,vector<pair<int,int> > pre){
    
    int n = in.size();
    int m = pre.size();
    
    assert(n==m);
    
    if(n==0)return NULL;
    
    int r = pre[0].first,j;
    
    for(j=0;j<n;j++){
        if(in[j].first==r)break;
    }
    
    TreeNode* nn = (TreeNode*)malloc(sizeof(TreeNode));
    nn->val=pre[0].second;
    
    
    nn->left = restore( vector<pair<int,int> >(in.begin(),in.begin()+j) , vector<pair<int,int> >(pre.begin()+1,pre.begin()+j+1) );
    
    
    nn->right = restore( vector<pair<int,int> >( min(in.end(),in.begin()+j+1),in.end() ) , vector<pair<int,int> >( min(pre.end(),pre.begin()+j+1), pre.end() ) );
    
    // cout << " hfdjskj \n";
    return nn;
}

 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)return "";
        
        // cout << inorder(root) << endl;
        string ret = inorder(root)+ " | " + preorder(root); 
        // cout << ret << endl;
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string d) {
        
        int n = d.length(),i;
        if(n==0)return NULL;
        
        // cout << " herejhcl " << endl;
        
        for(i=0;i<n;i++){
            if(d[i]=='|')break;
        }
        
        // string in=d.substr(0,i);
        // string pst=d.substr(i+1,n-(i+1));
        
        vector<pair<int,int> > in,pre;
        
        {
            // cout << "????? " << d.substr(0,i) << endl;
            istringstream ss(d.substr(0,i));
            do{
                int x,y;
                ss>> x >> y;
                if(ss)in.push_back( make_pair(x,y) );
            }while(ss);
        }
        {
            // cout << "???? " << d.substr(i+1,n-i-1) << endl;
            istringstream ss(d.substr(i+1,n-i-1));
            do{
                int x,y;
                ss>> x >> y;
                if(ss)pre.push_back( make_pair(x,y) );
            }while(ss);
        }
        
        // cout << "mfdjkfkfbdjksjvn" << in.size() << " " << pre.size()  << endl;
        
        // for(int i=0;i<in.size();i++){
        //     cout << in[i] << endl;
        // }
        
        // for(int i=0;i<in.size();i++){
        //     cout << pre[i] << endl;
        // }
        
        return restore(in,pre);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));