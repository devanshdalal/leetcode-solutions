class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        
        map<string,vector<string>> m;
        
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            auto it = m.find(s);
            if(it!=m.end()){
                it->second.push_back(strs[i]);
            }else{
                m[s]=vector<string>(1,strs[i]);
            }
        }
        
        vector<vector<string> > ans;
        for(auto it=m.begin();it!=m.end();it++){
            sort(it->second.begin(),it->second.end());
            ans.push_back(it->second);
        }
        
        return ans ;
        
    }
};