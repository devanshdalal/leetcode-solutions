long long fact[10];
bool fa=0;

void facts(){
    fact[0]=1;
    for(int i=1;i<10;i++){
        fact[i]=fact[i-1]*i;
    }
    fa=1;
}

class Solution {
public:
    
    
    string getPermutation(int n, int k) {
        if(!fa)facts();
        
        string r="";
        if(n==1)return string("1");
        // if(k>fact[n])return r;
        
        vector<int> a;
        for(int i=1;i<=n;i++){
            a.push_back(i);
        }
        
        // k--;
        int rank=0;
        for(int i=1;i<=n;i++){
            int j=0;
            if(a.size()>0){
                for(j=0;j<a.size();j++){
                    if( fact[n-i]+rank>=k )break;
                    rank+=fact[n-i];
                }   
            }
            
            // cout << a.size() << " " << j << endl;
            
            r+=to_string(a[j]);
            
            a.erase(a.begin()+j);
            
            
        }
        
        return r;
        
        
    }
};