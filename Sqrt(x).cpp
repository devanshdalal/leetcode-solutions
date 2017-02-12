class Solution {
public:
    int mySqrt(int x) {
        
        if(x<=1)return x;
        double x0=x,x1;
        
        
        while(1){
            
            x1=(x0+x/x0)/2.0;
            
            if(abs(x0-x1)<1){
                return x1;
            }
            x0=x1;
        }
        
    }
};