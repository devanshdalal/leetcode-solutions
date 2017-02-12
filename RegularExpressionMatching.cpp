class Solution {
public:

    bool equal(char c1,char c2){
        return c1==c2 or c2=='.' or c1=='.';
    }
    
    bool isMatch(string s, string p) {
        
        int n = s.length();
        int m = p.length();
        
        vector< pair<char,int> > pat;
        
        for(int i=0;i<m;i++){
            if( i<m-1 and p[i+1]!='*' )pat.push_back( make_pair(p[i],1)  );
            else{
                if(i<m-1){
                    pat.push_back( make_pair(p[i++],2)  );
                }else{
                    pat.push_back( make_pair(p[i],1)  );
                }
            }
        }
        
        m=pat.size();
        
        bool d[n+1][m+1];
        
        d[0][0]=1;
        
        for(int i=1;i<=n;i++){
            d[i][0]= 0;
        }
        
        for(int i=1;i<=m;i++){
            d[0][i]= d[0][i-1] && (pat[i-1].second==2);
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                d[i][j]=0;
                
                if( pat[j-1].second==1 ){
                    d[i][j]= (d[i-1][j-1] and equal(pat[j-1].first,s[i-1]) ); 
                }else{
                    d[i][j]= (d[i][j-1] or (d[i-1][j] and equal(pat[j-1].first,s[i-1]) ) );
                }
                
            }
        }
        
        
        return d[n][m];
        
        
    }
};