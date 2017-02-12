class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> a(num+1,0);
        
        a[0]=0;
        for(int i=1;i<=num;i++){
            if(i&1){
                a[i]=a[ (i/2)*2 ]+1;
            }else{
                a[i]=a[i/2];
            }
        }
        return a;
    }
};