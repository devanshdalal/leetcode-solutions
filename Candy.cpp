class Solution {
public:
    int candy(vector<int>& a) {
        
        
        int n = a.size();
        if(n<=1)return n;
        
        int ans = 1;
        int len = 1 ;
        int last = INT_MAX;
        int ht = 1;
        
        for(int i=1;i< n;i++){
            if(a[i]>a[i-1]){
                ht++;
                ans += ht;
                last = ht;
                len = 0 ;
            }else if(a[i]<a[i-1]){
                len++;
                if(len>=last){
                    len++;
                    last = INT_MAX;
                }
                ht=1;
                ans += len;
            }else{
                len = 1;
                ht=1;
                ans+=1;
                last=INT_MAX;
            }
        }
        
        return ans ;
        
    }
};