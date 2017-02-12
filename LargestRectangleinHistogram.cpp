class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        
        
        int n = a.size();
        if(n==0)return 0;
        if(n==1)return a[0];
        
        stack<pair<int,int> > s;
        int left[n],right[n];
        
        for(int i=0;i<n;i++){
            
            while(!s.empty() and s.top().first>=a[i]){
                s.pop();
            }
            
            if(s.empty()){
                left[i]=0;
            }else{
                left[i]=s.top().second+1;
            }
            
            s.push( make_pair(a[i],i) );
        }
        
        while(!s.empty())s.pop();
        
        for(int i=n-1;i>=0;i--){
            
            while(!s.empty() and s.top().first>=a[i]){
                s.pop();
            }
            
            if(s.empty()){
                right[i]=n-1;
            }else{
                right[i]=s.top().second-1;
            }
            
            s.push( make_pair(a[i],i) );
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max( (right[i]-left[i]+1)*a[i] ,ans);
        }
        
        return ans ;
        
    }
};