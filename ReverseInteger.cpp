class Solution {
public:
    int reverse(int x) {
        int sign=x>0;
        
        // if()
        
        x=abs(x);
        long long ans=0;
        while(x>0){
            ans=ans*10;
            ans+=x%10;
            x/=10;
        }
        
        return  (ans>INT_MAX?0:(2*sign-1)*ans);
        
    }
};