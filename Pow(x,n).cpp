class Solution {
public:

    double binexp(double x, int n){
        
        double res=1;
        while(n>0){
            if(n&1){
                res*=x;
            }
            x=(x*x);
            n>>=1;
        }
        
        return res;
    }

    double myPow(double x, int n) {
        
        if(x==1 or x==0)return x;
        if(n==0)return 1.0;
        if(n==INT_MIN)return myPow(1.0/(x*x),-(n/2));
        if(n<0)return myPow(1.0/x,-n);
        
        return binexp(x,n);
        
    }
};