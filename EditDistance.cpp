class Solution {
public:
    int minDistance(string a, string b) {
        
        int n = a.length(),m=b.length();
        if(n*m==0)return max(n,m);
        
        int d[n][m];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i]==b[j])
                    d[i][j]=(i>0 and j>0?d[i-1][j-1]:max(i,j));
                else{
                    int sub = (i>0 and j>0?d[i-1][j-1]:max(i,j));
                    d[i][j]=1+min(i>0?d[i-1][j]:j,j>0?d[i][j-1]:i);
                    d[i][j]=min(sub+1,d[i][j]);
                }
                // cout << d[i][j] << " ";
            }
            // cout << endl;
        }
        
        return d[n-1][m-1];
        
    }
};