struct trieNode{
    bool leaf;
    trieNode* t[26];
};

class WordDictionary {
public:
    trieNode* Trie;
    WordDictionary(){
        Trie = new trieNode;
        for(int i=0;i<26;i++){
            Trie->t[i]=NULL;
            Trie->leaf=0;
        }
    }
    ~WordDictionary(){
        // delete Trie;
    }
    // Adds a word into the data structure.
    void addWord(string w) {
        trieNode* it=Trie;
        int n=w.length();
        for(int i=0;i<n;i++){
            int ind=w[i]-'a';
            if(it->t[ind]==NULL){
                it->t[ind]=new trieNode;
                for(int j=0;j<26;j++){
                    it->t[ind]->t[j]=NULL;
                    it->t[ind]->leaf=0;
                }
            }
            it=it->t[ind];
        }
        it->leaf=1;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    
    bool search_help(string& w,int n,int id,trieNode *tnode) {
        // cout << id << endl;
        if(id==n){
            // for(int i=0;i<26;i++){
            //     if(tnode->t[i])return 0;
            // }
            return tnode->leaf;
        }
        if(w[id]=='.'){
            bool res=0;
            for(int i=0;i<26;i++){
                // cout << char(i+'a') << " " << (tnode->t[i]!=NULL) <<   endl;
                res|= tnode->t[i]!=NULL and search_help(w,n,id+1,tnode->t[i]);
                if(res)return 1;
            }
            return res;
        }
        
        return tnode->t[w[id]-'a']!=NULL and search_help(w,n,id+1,tnode->t[w[id]-'a']);
        
        
    }
    
    
    bool search(string w) {
        trieNode * it=Trie;
        int n=w.length();
        cout <<" " << w << endl;
        return search_help(w,n,0,it);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");