class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& a, int k, int t) {
        
        set<long long> s;
        
        int n = a.size();
        
        for(int i=0;i<n;i++){
            
            if( !s.empty() ){
                std::set<long long>::iterator it=s.lower_bound(a[i]);
                if(it==s.end()){ if(abs(a[i] - *s.rbegin()) <=t)return 1;}
                else if(it==s.begin() ) { if (abs( a[i] - *s.begin() )<=t)return 1;}
                else if (  abs( *it - a[i] )<=t  or  abs( *(--it) - a[i] )<=t  ) return true;
            }
            
            s.insert(a[i]);
            if(i-k>=0){
                s.erase(a[i-k]);
            }
            
        }
        
        return 0;
    }
};