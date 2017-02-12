bool *v[100000];
int n , m;

struct trieNode{
    string leaf;
    trieNode* t[26];
};

trieNode * Trie;

trieNode* create (){
    trieNode * node = new trieNode;
    for(int i=0;i<26;i++){
        node->t[i]=NULL;
        node->leaf="";
    }
    return node;
}

void insert(string w,string id) {
    trieNode* it=Trie;
    int n=w.length();
    for(int i=0;i<n;i++){
        int ind=w[i]-'a';
        if(it->t[ind]==NULL){
            it->t[ind]=create();
        }
        it=it->t[ind];
    }
    it->leaf=id;
}

vector<string> ans;

void back_track(int x,int y,trieNode* root,vector<vector<char>>& b){
    if(v[x][y])return;
    
    int id = b[x][y]-'a';
    
    if(root->t[id]!=NULL and root->t[id]->leaf!=""){
        ans.push_back(root->t[id]->leaf);
        root->t[id]->leaf="";
    }
    
    if(root->t[id]!=NULL){
        v[x][y]=1;
        
        if( x>0 )back_track(x-1,y,root->t[id],b);
        
        if(x<n-1 )back_track(x+1,y,root->t[id],b);
        
        if(y>0 )back_track(x,y-1,root->t[id],b);
        
        if(y<m-1 )back_track(x,y+1,root->t[id],b);
        
        v[x][y]=0;
    }
}

class Solution {
public:

    vector<string> findWords(vector<vector<char>>& b, vector<string>& w) {
        ans.clear();
        n=b.size();
        if(n==0)return ans;
        m=b[0].size();
        
        Trie = create();
        
        for(int i=0;i<n;i++){
            v[i]=new bool[m];
            for(int j=0;j<m;j++){
                v[i][j]=0;
            }
        }
        
        int q=w.size();
        
        for(int i=0;i<q;i++){
            insert(w[i],w[i]);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(Trie!=NULL){
                    back_track(i,j,Trie,b);
                }

            }
        }
        
        for(int i=0;i<n;i++){
            delete v[i];
        }
        
        return ans ;
    }
};