class Solution {
public:

    // vector<int> ans;
    vector<int> graph[100000];
    int v[100000];
    bool flag=0;

    void dfs(int x){
        v[x]=101;
        for(int i=0;i<graph[x].size();i++){
            int y=graph[x][i];
            if(!v[y]){
                dfs(y);
            }else if(v[y]==101){
                flag=1;
                return;
            }
        }
        v[x]=1;
        // ans.push_back(x);
    }

    bool canFinish(int n, vector<pair<int, int>>& p) {
        
        fill(v,v+n,0);
        // ans.clear();
        flag=0;
        fill(graph,graph+n,vector<int>());
        
        for(int i=0;i<p.size();i++){
            graph[p[i].second].push_back(p[i].first);
        }
        
        for(int i=0;i<n;i++){
            if(!v[i]){
                dfs(i);
                if(flag)return 0;
            }
        }
        
        return 1;
        // std::reverse(ans.begin(),ans.end());
        // return ans;
        
        
    }
};