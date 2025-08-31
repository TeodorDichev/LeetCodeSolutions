#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }

private:
    struct Choice {
        int r = -1, c = -1;
        vector<int> cand;
        bool hasEmpty = false;
        bool contradiction = false;
    };

    bool backtrack(vector<vector<char>>& board) {
        Choice ch = chooseCell(board);
        if (ch.contradiction) return false;
        if (!ch.hasEmpty) return true;

        for (int v : ch.cand) {
            board[ch.r][ch.c] = char('0' + v);
            if (backtrack(board)) return true;
            board[ch.r][ch.c] = '.';
        }
        return false;
    }

    Choice chooseCell(vector<vector<char>>& board) {
        Choice best;
        int minSize = 10;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    best.hasEmpty = true;
                    vector<int> cand = getCandidates(board, i, j);
                    if (cand.empty()) {
                        best.contradiction = true;
                        return best;
                    }
                    if ((int)cand.size() < minSize) {
                        minSize = (int)cand.size();
                        best.r = i; best.c = j; best.cand = cand;
                        if (minSize == 1) return best;
                    }
                }
            }
        }
        return best;
    }

    vector<int> getCandidates(const vector<vector<char>>& board, int row, int col) {
        bool used[10] = {false};

        for (int j = 0; j < 9; ++j)
            if (board[row][j] != '.') 
                used[board[row][j] - '0'] = true;

        for (int i = 0; i < 9; ++i)
            if (board[i][col] != '.') 
                used[board[i][col] - '0'] = true;

        int br = (row / 3) * 3, bc = (col / 3) * 3;
        for (int di = 0; di < 3; ++di)
            for (int dj = 0; dj < 3; ++dj) {
                char c = board[br + di][bc + dj];
                if (c != '.') 
                    used[c - '0'] = true;
            }

        vector<int> out;
        for (int d = 1; d <= 9; ++d)
            if (!used[d]) out.push_back(d);
        return out;
    }
};
