class Solution {
public:
    int singleNumber(vector<int>& a) {
        
        int s=0;
        for(int i=0;i<a.size();i++){
            s^=a[i];
        }
        
        return s;
        
    }
};