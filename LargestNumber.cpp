bool comp(string a,string b){
    return a+b<b+a;
}

class Solution {
public:
    
    string largestNumber(vector<int>& a) {
        
        vector<string> s;
        int n=a.size();
        bool nz=0;
        for(int i=0;i<n;i++){
            s.push_back( to_string(a[i]) );
            if(a[i]>0)nz=1;
        }
        
        if(!nz){
            return string("0");
        }
        
        sort(s.begin(),s.end(),comp);
        
        string ans="";
        for(int i=n-1;i>=0;i--){
            ans+=s[i];
        }
        
        
        return ans;
        
    }
};