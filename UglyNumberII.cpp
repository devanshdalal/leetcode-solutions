#incldue<queue>

class Solution {
public:
    int nthUglyNumber(int n) {
        
        
        priority_queue< long long , vector<long long> , std::greater<long long>  > pq;
        
        
        map<long long,bool> m;
        
        
        m[1]=1;
        pq.push(1);
        
        int i=1;
        while(i!=n){
            auto tp = pq.top(); pq.pop();
            
            long long c2 = 2*tp ;
            if(!m[c2]){
                m[c2]=1;
                pq.push(c2);
            }
            
            c2 = 3*tp ;
            if(!m[c2]){
                m[c2]=1;
                pq.push(c2);
            }
            
            c2 = 5*tp ;
            if(!m[c2]){
                m[c2]=1;
                pq.push(c2);
            }
            
            i++;
        }
        
        int ans = pq.top();
        return ans;
        
    }
};