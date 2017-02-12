class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        
        unordered_set<int> s;
        
        
        int n=a.size();
        
        for(int i=0;i<n;i++){
            s.insert(a[i]);
        }
        
        int ans=0;
        while(s.size()>0){
            auto it=s.begin();
            
            int c=1;
            int v=*it;
            
            while(s.find(v+1)!=s.end()){
                s.erase(v+1);
                v++;
                c++;
            }
            
            v=*it;
            s.erase(v);
            
            while(s.find(v-1)!=s.end()){
                s.erase(v-1);
                v--;
                c++;
            }
            
            ans = max(ans,c);
        }
        
        
        return ans;
        
    }
};