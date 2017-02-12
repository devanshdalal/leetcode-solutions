/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool comp(Interval x,Interval y){
    if(x.start<y.start)return 1;
    if(x.start==y.start and x.end<y.end)return 1;
    return 0;
} 
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& a) {
        
        sort(a.begin(),a.end(),comp);
        
        vector<Interval> res;
        int n=a.size();
        
        for(int i=0;i<n;){
            
            int last=a[i].end,j;
            for(j=i+1;j<n and a[j].start<=last;j++){
                last=max(a[j].end,last);
            }
            Interval xx;
            xx.start=a[i].start;
            xx.end=last;
            
            res.push_back(xx);
            
            i=j;
        }
        
        
        return res;
        
        
    }
};