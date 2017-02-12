class TrieNode {
public:
    TrieNode* t[26];
    int leaf;
    // Initialize your data structure here.
    TrieNode() {
        leaf=0;
        for(int i=0;i<26;i++){
            t[i]=NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string w) {
        
        auto it = root;
        
        int n=w.length();
        if(n==0){
            it->leaf=1;
            return ;
        }
        for(int i=0;i<n;i++){
            int id = w[i]-'a';
            if(it->t[id]==NULL){
                it->t[id]=new TrieNode();
            }
            it=it->t[id];
        }
        it->leaf=1;
        
    }

    // Returns if the word is in the trie.
    bool search(string w) {
        auto it = root;
        
        int n=w.length();
        if(n==0){
            return it->leaf==1;
        }
        for(int i=0;i<n;i++){
            int id = w[i]-'a';
            if(it->t[id]==NULL){
                return 0;
            }
            it=it->t[id];
        }
        return it->leaf==1;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string p) {
        
        auto it = root;
        int n=p.length();
        if(n==0){
            return it->leaf==1;
        }
        for(int i=0;i<n;i++){
            int id = p[i]-'a';
            if(it->t[id]==NULL){
                return 0;
            }
            it=it->t[id];
        }
        return 1;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");