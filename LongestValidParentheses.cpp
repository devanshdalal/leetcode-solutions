class Solution {
public:

    bool pair(char c1,char c2){
        return c1=='(' and c2==')';
    }

    int longestValidParentheses(string a) {
        
        int n = a.length();
        
        if(n<=1)return 0;
        
        int ans =0 ;
        
        int d[n];
        
        d[0]=0;
        for(int i=1;i<n;i++){
            if(a[i]=='('){
                d[i]=0;
            }else{
                int j=i-2-d[i-1];
                if(j+1<0) d[i]=0;
                else if(a[j+1]=='('){
                    d[i]=(j>=0?d[j]:0)+i-j;
                }else{
                    d[i]=0;
                }
            }
            ans = max(ans,d[i]);
            
        }
        
        return ans;
        
    }
};