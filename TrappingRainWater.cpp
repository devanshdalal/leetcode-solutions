class Solution {
public:
    int trap(vector<int>& h) {
        
        int n=h.size();
        if(n<=2)return 0;
        
        int maxl[n],maxr[n];
        
        maxl[0]=h[0];
        for(int i=1;i<n;i++){
            maxl[i]=max(h[i],maxl[i-1]);
        }
        
        maxr[n-1]=h[n-1];
        int ans=0;
        for(int i=n-2;i>=0;i--){
            maxr[i]=max(h[i],maxr[i+1]);
        }
        
        for(int i=1;i<n-1;i++){
            int level = min(maxl[i],maxr[i]);
            if(h[i]<level)ans+=level-h[i];
        }
        
        return ans;
        
    }
};