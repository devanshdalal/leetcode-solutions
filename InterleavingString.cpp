class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int n = s1.length();
        
        int m = s2.length();
        
        if(s3.length()!=n+m)return 0;
        
        if(n==0) return s2==s3;
        if(m==0) return s1==s3;
        
        bool d[n+1][m+1];
        
        d[0][0]=1;
        for(int i=1;i<=n;i++){
            d[i][0]=( s1[i-1]==s3[i-1] and d[i-1][0] );
        }
        
        for(int i=1;i<=m;i++){
            d[0][i]=( s2[i-1]==s3[i-1] and d[0][i-1] );
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                d[i][j]=(s1[i-1]==s3[i+j-1] and  d[i-1][j])|( s2[j-1]==s3[i+j-1] and  d[i][j-1]);
            }
        }
        
        return d[n][m];
        
        
    }
};