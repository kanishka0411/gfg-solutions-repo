class Solution {
  public:
    // Function to find a solved Sudoku.
    bool isSafe(vector<vector<int>>&mat,int row,int col,int num){
        for(int i=0;i<9;i++){
            if(mat[row][i]==num) return false;
        }
        for(int j=0;j<9;j++){
            if(mat[j][col]==num) return false;
        }
        
        int srow=3*(row/3);
        int scol=3*(col/3);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(mat[srow+i][scol+j]==num) return false;
            }
        }
        
        return true;
    }
    bool solve(vector<vector<int>>&mat){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(mat[row][col]==0){
                    for(int i=1;i<=9;i++){
                        if(isSafe(mat,row,col,i)){
                            mat[row][col]=i;
                            if(solve(mat)) return true;
                            mat[row][col]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat);
        
    }
};