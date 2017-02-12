class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        vector<int> ans;
        int n=A.size();
        deque<pair<int,int> > dq;
        assert(n>=k);
        if(n==0)return ans;
        int cm=A[0];
        for(int i=0;i<k;i++){
            while( !dq.empty() and A[i]>=(dq.back()).second ){
                dq.pop_back();
            }
            dq.push_back(make_pair(i,A[i]) );
            cm=max(A[i],cm);
        }
        ans.push_back(cm);
        
        for(int i=k;i<n;i++){
            if(dq.front().first<=i-k)dq.pop_front();
            while( !dq.empty() and A[i]>=dq.back().second ){
                dq.pop_back();
            }
            // if(dq.empty() ){
                
            // }else{
            //     ans.push_back();
            // }
            dq.push_back(make_pair(i,A[i]) );
            ans.push_back(dq.front().second );
        }
        
        return ans;
        
        
    }
};