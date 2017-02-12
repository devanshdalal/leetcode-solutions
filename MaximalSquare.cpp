class Solution {
public:
    int maximalSquare(vector<vector<char>>& a) {
        
        int n=a.size();
        if(n==0)return 0;
        int m=a[0].size();
        // cerr << a[0][0] << endl;
        
        int x[n+1][m+1];
        int y[n+1][m+1];
        int d[n+1][m+1];
        
        for(int i=0;i<=n;i++){
            x[i][m]=y[i][m]=d[i][m]=0;
        }
        
        for(int i=0;i<=m;i++){
            x[n][i]=y[n][i]=d[n][i]=0;
        }
        
        int ans =0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                x[i][j]=(a[i][j]-'0')*(x[i+1][j]+1) ;
                y[i][j]=(a[i][j]-'0')*(y[i][j+1]+1) ;
                d[i][j]=(a[i][j]-'0')*min(min(d[i+1][j+1]+1,x[i][j]),y[i][j]);
                ans = max(ans,d[i][j]*d[i][j]);
            }
        }
        
        
        return ans;
        
        
    }
};