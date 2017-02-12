class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        
        vector<int > v;
        int n=a.size();
        if(n==0) return v;
        int m=a[0].size();
        
        int l=0,r=m-1;
        int u=0,d=n-1;
        
        while( l<=r and u<=d ){
            //
            for(int i=l;i<=r;i++){
                v.push_back(a[u][i]);
            }
            u++;
            
            if(u>d)break;
            
            //
            for(int i=u;i<=d;i++){
                v.push_back(a[i][r]);
            }
            r--;
            
            if(l>r)break;
            //
            for(int i=r;i>=l;i--){
                v.push_back(a[d][i]);
            }
            d--;
            
            if(u>d)break;
            
            for(int i=d;i>=u;i--){
                v.push_back(a[i][l]);
            }
            l++;
            
            
            
            
        }
        
        return v;
        
        
    }
};