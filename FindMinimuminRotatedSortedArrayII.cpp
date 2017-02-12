class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        if(n==1)return a[0];
        
        if(a[0]<a[n-1])return a[0];
        
        
        bool d=1;
        for(int i=1;i<n;i++){
            if(a[0]!=a[i]){
                d=0;
            }
        }
        if(d==1)return a[0];
        
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,a[i]);
        }
        
        return ans;
        
    }
};