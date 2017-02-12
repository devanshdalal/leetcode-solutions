// trim from start
static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}

bool BothAreSpaces(char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); }

class Solution {
public:
    void reverseWords(string &s) {
        
        trim(s);
        
        std::reverse(s.begin(),s.end());
        
        int n=s.length();
        for(int i=0;i<n;){
            int j;
            for(j=i;j<n and s[j]!=' ';j++);
            
            std::reverse(s.begin()+i,s.begin()+j);
            
            i=j+1;
        }
        
        

        std::string::iterator new_end = std::unique(s.begin(), s.end(), BothAreSpaces);
        s.erase(new_end, s.end()); 
        
    }
};