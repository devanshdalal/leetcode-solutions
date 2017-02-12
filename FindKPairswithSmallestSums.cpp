#include <queue>

typedef struct data{
    int x,y,sum;
} T;

class mycomparison
{
public:
  mycomparison()
    {}
  bool operator() (const T& lhs, const T&rhs) const
  {
    return ( lhs.sum > rhs.sum );
  }
};



class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        
        
        priority_queue< T,std::vector<T>, mycomparison > pq;
        vector<pair<int, int>> ans;
        ans.reserve(k);
        
        int n=a.size();
        int m=b.size();
        if(n==0 or m==0 ) return ans;
        
        map<pair<int,int>,bool> mp;
        
        pq.push(data{0,0,a[0]+b[0]});
        while(k>0 and !pq.empty()){
            
            T tp = pq.top(); pq.pop();
            int &x=tp.x;
            int &y=tp.y;
            
            if(x<n-1 and mp.find(make_pair(x+1,y))==mp.end() ){
                pq.push( data{x+1,y,a[x+1]+b[y]} );
                mp[ make_pair(x+1,y) ]=1;
            }
            
            if(y<m-1 and mp.find(make_pair(x,y+1))==mp.end()){
                pq.push( data{x,y+1,a[x]+b[y+1]} );
                mp[ make_pair(x,y+1) ]=1;
            }
            
            ans.push_back(make_pair(a[x],b[y]) );
            
            k--;
        }
        
        return ans ;
        
        
    }
};