class NumMatrix {
public:
    int n,m;
    vector<vector<int>> a;
    NumMatrix(vector<vector<int>> &b) {
        int n=b.size(),m=0;
        if(n>0)m=b[0].size();
        a=vector<vector<int> >(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=0;j<m;j++){
                s+=b[i][j];
                a[i][j]=(i>0?a[i-1][j]:0)+s;
            }
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
        
        return a[r2][c2] + (r1>0 and c1>0?a[r1-1][c1-1]:0) - (r1>0?a[r1-1][c2]:0) - (c1>0?a[r2][c1-1]:0);  
        
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);