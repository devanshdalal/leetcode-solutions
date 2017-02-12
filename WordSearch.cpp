#include<bits/stdc++.h>

class Solution {
public:
    
    bool exist2(vector<vector<char>>& b, string & w,int ind,vector<vector<bool>>& v,int x,int y) {
        
        int n=b.size();
        int l=w.length();
        if(n*l==0)return 0;
        int m=b[0].size();
        
        if( !v[x][y] and b[x][y]==w[ind] ){
            
            if(ind==l-1)return 1;
            v[x][y]=1;
            bool res = (x<n-1 and exist2(b,w,ind+1,v,x+1,y) ) || (y<m-1 and exist2(b,w,ind+1,v,x,y+1) ) ||
                                    (x>0 and exist2(b,w,ind+1,v,x-1,y) ) || (y>0 and exist2(b,w,ind+1,v,x,y-1) ) ;
            if(res)return 1;
            v[x][y]=0;
            
        }

        return 0;
        
        
    }
    
    bool exist(vector<vector<char>>& b, string w) {
        
        int n=b.size();
        int l=w.size();
        if(n*l==0)return 0;
        int m=b[0].size();
        
        vector<vector<bool> > v(n,vector<bool>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(exist2(b,w,0,v,i,j) )return 1;
            }
        }
        
        return 0;
        

        
        
    }
};