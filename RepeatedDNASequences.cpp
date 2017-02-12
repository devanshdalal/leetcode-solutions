class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> res;
        int n=s.length();
        if(n<10)return res;
        vector<pair<string,int> > v;
        
        for(int i=0;i<n;i++){
            if(i+10<=n){
                string ss=s.substr(i,10);
                v.push_back(make_pair(ss,i) );
            }
        }
        
        sort(v.begin(),v.end());
    
        int m =v.size();
        // cout << m << endl;
        for(int i=0;i<m;){
            int j;
            for(j=i+1;j<m and v[i].first==v[j].first;j++);
            // if(v[j].second-v[i].second>=10){
            // if(j-i>=2)cout << i << j << endl;
            if(j-i>1)res.push_back(v[i].first);  
            // }
            i=j;
        }        

        return res ;
        
    }
};