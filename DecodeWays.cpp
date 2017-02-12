class Solution {
public:
    int numDecodings(string s) {
        
        int n=s.length();
        if(n==0)return 0;
        int d[n+1];
        d[n]=1;
        
        for(int i=n-1;i>=0;i--){
            d[i]= (s[i]>'0' and s[i]<='9')? d[i+1]:0;
            if( i<n-1 and s[i]>='1' and s.substr(i,2)<string("27")   )d[i]+=d[i+2];
        }
        
        
        return d[0];
        
        
    }
};