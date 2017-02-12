class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        int last[1126];
        fill(last,last+1126,-1);
        int len=0,ans=0;
        for(int i=0;i<n;i++){
            ans=max(min(len+1,i-last[s[i] ]),ans);
            len=min(len+1,i-last[s[i]]);
            last[s[i]]=i;
        }
        
        return ans;
    }
};