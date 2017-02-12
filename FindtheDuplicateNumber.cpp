class Solution {
public:
    int findDuplicate(vector<int>& a) {
        
        int n=a.size()-1;
        int l=1,r=n;
        while(l<r){
            int m=(l+r)/2;
            int s=0,count=0;
            for(int i=0;i<=n;i++){
                if(a[i]<=r and a[i]>=l ){
                    if(a[i]<=m)s++;
                    count++;
                }
            }
            
            if(s>count-s){
                r=m;
            }else{
                l=m+1;
            }
            
            
            
        }
        
        return l;
        
    }
};