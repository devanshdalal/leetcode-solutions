class Solution {
public:

    int maxProfit(vector<int>& a) {
        
        int n=a.size();
        
        int cmin=INT_MAX;
        int ans=0;
        for(int i=0; i<n;i++){
        
            if(  cmin<a[i]  ){
                ans+=a[i]-cmin;
                cmin=a[i];
            }
            
            cmin=min(cmin,a[i]);
        }
        
        
        
        return ans;
    }
};