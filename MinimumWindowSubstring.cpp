#include<unordered_map>

class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> m;
        unordered_map<char,int> p;
        int total=0;
        
        for(int i=0;i<t.length();i++){
            std::unordered_map<char,int>::iterator it=m.find( t[i] );
            if( it!=m.end() ){
                it->second++;
            }else{
                m[t[i]]=1;
                total++;
                p[t[i]]=0;
            }
        }
        
        
        int n=s.length();
        
        int i=0,j=0;
        
        std::string ans="" ;
        {
            std::unordered_map<char,int>::iterator it=m.find( s[i] );
            std::unordered_map<char,int >::iterator jt=p.find( s[i] );
            if(it!=m.end()){
                jt->second++;
                if( it->second == jt->second  ){
                    total--;
                }   
            }
        }
        
        for(;i<n and i<=j;){
            
            if(total==0){
                if( ans=="" or j-i+1<ans.length() ){
                    ans = s.substr(i,j-i+1);
                }
                
                std::unordered_map<char,int>::iterator it=m.find( s[i] );
                std::unordered_map<char,int >::iterator jt=p.find( s[i] );
                if(it!=m.end()){
                    jt->second--;
                    if( it->second-1 == jt->second  ){
                        total++;
                    }   
                }
                
                i++;
            }else{
                
                if(j==n)break;
                
                std::unordered_map<char,int>::iterator it=m.find( s[j+1] );
                std::unordered_map<char,int>::iterator jt=p.find( s[j+1] );
                if( it!=m.end() ){
                    jt->second++;
                    if( it->second == jt->second  ){
                        total--;
                    }   
                }
                
                j++;
            }   
        }
        
        
        return ans;
           
        
    }
};