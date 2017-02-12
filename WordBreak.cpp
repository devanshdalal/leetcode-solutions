class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.length();
        if(n<1)return 0;
        
        bool d[n];
        
        for(int i=0;i<n;i++){
            d[i]=0;
            for(int j=i;j>=0;j--){
                if( (j==0 or d[j-1]) and wordDict.find(s.substr(j,i-j+1))!=wordDict.end()){
                    d[i]=1;
                    break;
                }
            }
            // cout << d[i] << endl;
        }
        
        return d[n-1];
        
    }
};