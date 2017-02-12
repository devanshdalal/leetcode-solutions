class Solution {
public:
    int canCompleteCircuit(vector<int>& g, vector<int>& c) {
        
        
        int n=g.size();
        if(n==0)return -1;
        
        int i=0,has=0;
        for(;i<n;){
            
            int j;
            for(j=0;j<n;j++){
                int tmp=(i+j)%n;
                has+=g[tmp]-c[tmp];
                if(has<0)break;
            }
            has=0;
            if(j==n)return i;
            i=(i+j+1);
            
        }
        
        return -1;
        
    }
};