class Solution {
public:

    int largestRectangleArea1(vector<int>& a) {
        
        
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


    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        if(n==0)return 0;
        int m=matrix[0].size();
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                matrix[i][j]=matrix[i][j]=='1';
                // cout << a[i][j] << endl;
            }
        }
        
        
        vector< vector<int> > d(n,vector<int>(m,0));
        int ans=0;
        
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(matrix[i][j]==1)
                    d[i][j]=(i==n-1?1:d[i+1][j]+1);
            }
            
            ans=max(ans,largestRectangleArea1(d[i]));
            
        }
        
        
        
        return ans;        
    }
};
