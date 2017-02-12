class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        vector<vector<int> > ans;
        
        vector<pair<int,pair<int,int> > > p;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int s=nums[i]+nums[j];
                p.push_back( make_pair(s,make_pair(i,j)) );
            }
        }
        
        
        sort(p.begin(),p.end());
        int m = p.size();
        
        for(int i=0,j=m-1;i<j;){
            
            int s=p[i].first+p[j].first;
            if(s==t){
                if(p[i].first==p[j].first){
                    for(int it=i;it<j;it++){
                        for(int jt=i+1;jt<j;jt++){
                            if( p[it].second.first!=p[jt].second.first and p[it].second.second!=p[jt].second.first and 
                            p[it].second.second!=p[jt].second.first and p[it].second.second!=p[jt].second.second  )
                            ans.push_back(vector<int>{nums[p[it].second.first],nums[p[it].second.second],nums[p[jt].second.first],nums[p[jt].second.second]});
                        }
                    }
                    break;
                }else{
                    int ni=i,nj=j;
                    for(;ni<j and p[i].first==p[ni].first ;ni++);
                    for(;i<nj and p[j].first==p[nj].first ;nj--);
                    for(int it=i;it<ni;it++){
                        for(int jt=j;jt>nj;jt--){
                            if( p[it].second.first!=p[jt].second.first and p[it].second.second!=p[jt].second.first and 
                            p[it].second.second!=p[jt].second.first and p[it].second.second!=p[jt].second.second  )
                            ans.push_back(vector<int>{nums[p[it].second.first],nums[p[it].second.second],nums[p[jt].second.first],nums[p[jt].second.second]});
                        }
                    }
                    i=ni;
                    j=nj;   
                }
                
            }else if(s<t){
                i++;
            }else{
                j--;
            }
            
            
        }
        
        for(int i=0;i<ans.size();i++){
            sort(ans[i].begin(),ans[i].end());
        }
        
        sort(ans.begin(),ans.end());
        
        ans.erase( std::unique( ans.begin(), ans.end() ), ans.end() );
        
        
        return ans ;
        
    }
};