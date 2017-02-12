#include<unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        
        unordered_map<int,int> b;
        
        int n=a.size();
        for(int i=0;i<n;i++){
            b[a[i]]++;
        }
        
        std::vector<std::pair<int, int>> pairs;
        
        for (auto itr = b.begin(); itr != b.end(); ++itr)
            pairs.push_back(*itr);
        
        sort(pairs.begin(), pairs.end(), [=](std::pair<int, int>& a, std::pair<int, int>& b)
        {
            return a.second > b.second;
        }
        );
        
        vector<int> ans(k,0);
        
        for(int i=0;i<k;i++){
            ans[i]=pairs[i].first;
        }
        return ans;
        
    }
};