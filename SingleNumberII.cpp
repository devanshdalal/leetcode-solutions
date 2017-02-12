class Solution {
public:
    int singleNumber(vector<int>& a) {
        
        
        int ones = 0;
        int twos = 0,threes=~0;
        int n = a.size();
        
        for(int i=0;i<n;i++){
            
            int x=~a[i],y=ones;
            
            ones = ( (~(ones|twos)) &a[i]) | (ones&x) ;
            
            twos = (twos&x) | (y&a[i]);
        }
        
        return ones;
        
        
    }
};