/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

bool comp(Point a,Point b){
    return a.x<b.x or (a.x==b.x and a.y<b.y);
}
 
class Solution {
public:
    int maxPoints(vector<Point>& p){ 
        
        int n=p.size();
        
        sort(p.begin(),p.end(),comp);
        vector<pair<int,int> > r;
        vector<int > count;
        
        //p.erase(std::unique(p.begin(),p.end()) , p.end()  );
        for(int i=0;i<n;){
            int j;
            for(j=i+1;j<n and p[i].x==p[j].x and p[i].y==p[j].y;j++);
            r.push_back(make_pair(p[i].x,p[i].y) );
            count.push_back(j-i);
            i=j;
        }
        
        n=r.size();
        if(n==0)return 0;
        if(n==1)return count[0];
        // if(n==1)return 1;
        
        int ans =2;
        for(int i=0;i<n;i++){
            unordered_map<double,int> m;
            int vertical =0;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(r[i].first!=r[j].first){
                    double slope = double(r[j].second-r[i].second)/double(r[j].first-r[i].first);
                    m[slope]+=count[j];
                }else{
                    vertical+=count[j];
                }
            }
            for(auto it=m.begin();it!=m.end();it++){
                ans = max(ans,count[i]+it->second);
            }
            ans = max(ans,count[i]+vertical);
        }
        
        return ans ;
    }
};