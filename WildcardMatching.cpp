class Solution {
public:

    bool equal(char c1,char c2){
        return c1==c2 or c2=='?' or c1=='?';
    }
    
    bool isMatch(string s, string p) {
        
        int n = s.length();
        int m = p.length();
        
        bool d[n+1][m+1];
        // dp(i,j) = isMatch(s[0:i-1],p[0:j-1])
        
        d[0][0]=1;
        
        for(int i=1;i<=n;i++){
            d[i][0]= 0;
        }
        
        for(int j=1;j<=m;j++){
            d[0][j]= d[0][j-1] && p[j-1]=='*';
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                d[i][j]=0;
                
                if( p[j-1]!='*' ){
                    d[i][j]= (d[i-1][j-1] and equal(s[i-1],p[j-1]) ); 
                }else{
                    d[i][j]= (d[i][j-1] or d[i-1][j] );
                }
                
            }
        }
        
        
        return d[n][m];
        
        
    }
};