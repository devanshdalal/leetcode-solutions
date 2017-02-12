class Solution {
public:
    bool isScramble(string s1, string s2) {
        
        int n = s1.length();
        
        vector<bool> d[n][n];
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                d[i][j]=vector<bool>(n+1-max(i,j),0);
                if(s1[i]==s2[j])d[i][j][1]=1;
                for(int k=2;k<=n-max(i,j);k++){
                    // if(i==0 and j==0 and s1=="aa" and s2=="ab")return 0;
                    for(int l=1;l<k;l++){
                        if(!d[i][j][k]){
                            d[i][j][k] = (d[i][j][l] and d[i+l][j+l][k-l]) || (d[i][j+k-l][l] and d[i+l][j][k-l]);
                        }
                    }
                }
            }
        }
        
        // if(s1=="aa" and s2=="ab")return 1;
        return d[0][0][n];
        
    }
};