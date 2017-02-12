class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n=a.size();
        // long long ans = INT_MIN;
        
        int ans = INT_MIN, max_ending_here = 1, min_ending_here=1;
        
        for(int i=0;i<n;i++){
            
            if(a[i]==0){
                max_ending_here = 1;
                min_ending_here=0;
                ans = max(ans,a[i]);
            }else if(a[i]>0){
                max_ending_here = a[i]*max_ending_here;
                min_ending_here = min(min_ending_here*a[i],1);
                ans = max(ans,max_ending_here);
            }else{
                int tmp= max_ending_here;
                max_ending_here = max(a[i],min_ending_here*a[i]);
                min_ending_here = tmp*a[i];
                ans = max(ans,max_ending_here);
                max_ending_here = max(1,max_ending_here);
            }
            
            // long long p=1;
            // for(int j=i;j<n;j++){
            //     p*=a[j];
            //     ans = max(ans,p);
            // }
            
        }
        return ans; 
    }
};