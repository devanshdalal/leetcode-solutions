class Solution {
public:
    int minCut(string s) {
        
        int n = s.length();
        if(n<=1)return 0; 
        
        bool d[n][n];
        
        // for(int i=0;i<n;i++){
        //     d[i][i]=1;
        // }
        
        
        for(int len=1;len<=n;len++){
            for(int i=0;i<n;i++){
                int j= i+len-1;
                if(j<n)
                    d[i][j]=(s[i]==s[j] && (i+1>=j-1 or d[i+1][j-1]) );
            }   
        }
        
        int l[n];
        
        l[0]=0;
        for(int i=1;i<n;i++){
            int j;
            l[i]=i+1;
            for(j=0;j<=i;j++){
                if(d[j][i]){
                    l[i]= min( l[i], (j>0?1+l[j-1]:0) );       
                }
            }
        }
    
        return l[n-1];
            
    }
};