class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        if(n==1)return a[0];
        
        if(a[0]<a[n-1])return a[0];
        
        int l=0,r=n-1;
        while(l<r){
            int m=(l+r)/2;
            
            if( a[m]>a[l] ){
                l=m;
            }else if(a[m]<a[l]){
                r=m;
            }else{
                return a[m+1];
            }
            
            
        }
        
        return a[l];
        
        
    }
};