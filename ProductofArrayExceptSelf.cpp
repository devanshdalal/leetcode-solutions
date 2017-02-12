class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        
        
        int n = a.size();
        vector<int> res(n,1);
        
        int prod=1;
        for(int i=0;i<n;i++){
            res[i]*=prod;
            prod*=a[i];
        }
        
        prod=1;
        for(int i=n-1;i>=0;i--){
            res[i]*=prod;
            prod*=a[i];
            // std::cout << res[i] << std::endl;
        }
        
        return res;
        
    }
};