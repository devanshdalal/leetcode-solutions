class Solution {
public:
    string frequencySort(string s) {
        
        
        std::map<char,int> m;
        int n = s.length();
        for(int i=0;i<n;i++){
            m[s[i]]=m[s[i]]+1;
        }
        
        std::vector<std::pair<int,char> > v;
        
        for(auto i=m.begin();i!=m.end();i++){
            v.push_back(std::make_pair(i->second,i->first));
        }
        
        sort(v.begin(),v.end());
        
        char res[n+1];
        res[n]='\0';
        int j=n-1;
        for(auto i:v){
            while(i.first>0){
                res[j--]=i.second;
                i.first--;
            }
        }
        std::cout << res << std::endl;
        return (std::string)(res);
        
        
    }
};