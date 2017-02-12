void radsort(vector<int>& a){
        
    int n=a.size();
    
    for(long long base=1;base<=1000000000;base*=10){
        
        cout << "here \n" ;
        
        vector<int> v[10];
        for(int i=0;i<n;i++){
            // cout << (a[i]/base)%10 <<  " ";
            v[(a[i]/base)%10].push_back(a[i]);    
        }
        int k=0;
        for(int j=0;j<10;j++){
            for(int i=0;i<v[j].size();i++){
                a[k++]=v[j][i];
            }
        }
    }
        
}
    
    
class Solution {
public:
    
    

    int maximumGap(vector<int>& a) {
        
        int n=a.size();
        if(n<=1)return 0;
        
        // for(int i=0;i<n;i++){
        //     a[i]+=1000000000;
        // }
        
        radsort(a);
        
        // for(int i=0;i<n;i++){
        //     cout << a[i] << endl;
        // }
        
        int ans =0;
        for(int i=1;i<n;i++){
            ans = max(ans,a[i]-a[i-1]);
        }
        
        return ans ;
        
    }
};