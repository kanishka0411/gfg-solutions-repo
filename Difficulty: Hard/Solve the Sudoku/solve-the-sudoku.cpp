//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isValidMove(vector<vector<int>> &board, int row, int col, int num, 
                 vector<int> &rowMask, vector<int> &colMask, vector<int> &boxMask) {
    if ((rowMask[row] & (1 << num)) || 
        (colMask[col] & (1 << num)) || 
        (boxMask[row / 3 * 3 + col / 3] & (1 << num))) {
        return false;
    }
    return true;
}

bool sudokuSolverRec(vector<vector<int>> &board, int row, int col, 
                     vector<int> &rowMask, vector<int> &colMask, vector<int> &boxMask) {
    int size = board.size();

    if (row == size - 1 && col == size) 
        return true;
    if (col == size) {
        row++;
        col = 0;
    }

    if (board[row][col] != 0) 
        return sudokuSolverRec(board, row, col + 1, rowMask, colMask, boxMask);

    for (int num = 1; num <= size; num++) {
        if (isValidMove(board, row, col, num, rowMask, colMask, boxMask)) {
            board[row][col] = num;
            rowMask[row] |= (1 << num);
            colMask[col] |= (1 << num);
            boxMask[row / 3 * 3 + col / 3] |= (1 << num);

            if (sudokuSolverRec(board, row, col + 1, rowMask, colMask, boxMask))
                return true;

            board[row][col] = 0;
            rowMask[row] &= ~(1 << num);
            colMask[col] &= ~(1 << num);
            boxMask[row / 3 * 3 + col / 3] &= ~(1 << num);
        }
    }

    return false;
}

void solveSudoku(vector<vector<int>> &board) {
    int size = board.size();
    vector<int> rowMask(size, 0), colMask(size, 0), boxMask(size, 0);

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (board[row][col] != 0) {
                rowMask[row] |= (1 << board[row][col]);
                colMask[col] |= (1 << board[row][col]);
                boxMask[(row / 3) * 3 + col / 3] |= (1 << board[row][col]);
            }
        }
    }

    sudokuSolverRec(board, 0, 0, rowMask, colMask, boxMask);
}

};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends