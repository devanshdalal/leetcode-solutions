class Solution {
public:
    int maxProfit(vector<int>& a) {
        
        
        int n=a.size();
        
        
        int ans = 0 ;
        int max_so_far=INT_MIN;
        int min_so_far=INT_MAX;
        int d[n];
        for(int i=0;i<n;i++){
            
            d[i]=max(i>0?d[i-1]:0,a[i]-min_so_far);
            
            min_so_far=min(min_so_far,a[i]);
        }
        
        int real_ans=0;
        for(int i=n-1;i>0;i--){
            
            if(max_so_far!=INT_MIN and max_so_far-a[i]>ans ){
                ans =  max_so_far-a[i];
            }
            
            real_ans = max(real_ans,ans+d[i]);
            
            max_so_far = max(max_so_far,a[i]);
        }
        
        
        return real_ans;
    }
};