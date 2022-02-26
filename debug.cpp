/*
 * Description: debug purpose
 * Date: 2021.09.12
 * Author: 觉不醒的王子殿下
 */
#include <algorithm>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>

using namespace std;

class Solution {
private:
    using vvc = vector<vector<char>>;
    using vvi = vector<vector<int>>;
    using vpii = vector<pair<int, int>>;
    const int TARGET = 0x1ff;
    vvc ans;
    bool valid;
public:
    // bool check(vector<int>&row, vector<int> &col, vvi &win) {
    //     for (int i = 0; i < 9; i++) {
    //         if (col[i] != TARGET || row[i] != TARGET) {
    //             return false;
    //         }
    //     }
    //     for (int i = 0; i < 3; ++i) {
    //         for (int j = 0; j < 3; ++j) {
    //             if (win[i][j] != TARGET) {
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
    void backtrack(vvc &board, vpii &dots, int idx, vector<int>&row, vector<int>&col, vvi &win) {
        // if (check(row, col, win)) {
        //     ans = board;
        //     return;
        // }
        if (idx >= dots.size()) {
            valid = true;
            return;
        }
        int x = dots[idx].first;
        int y = dots[idx].second;
        for (int num = 0; num < 9 && !valid; ++num) {
            if (((row[x] >> num) & 1) || ((col[y] >> num) & 1) || ((win[x / 3][y / 3] >> num) & 1)) {
                continue;
            }
            board[x][y] = num + 1 + '0';
            row[x] |= (1 << num);
            col[y] |= (1 << num);
            win[x / 3][y / 3] |= (1 << num);
            backtrack(board, dots, idx + 1, row, col, win);
            row[x] &= ~(1 << num);
            col[y] &= ~(1 << num);
            win[x / 3][y / 3] &= ~(1 << num);
        }
    }
    void solveSudoku(vector<vector<char>>& board)
    {
        vector<int> row(9, 0);
        vector<int> col(9, 0);
        vector<vector<int>> win(3, vector<int>(3, 0));
        vector<pair<int, int>> dots;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch != '.') {
                    int num = ch - '0' - 1;
                    row[i] |= (1 << num);
                    col[j] |= (1 << num);
                    win[i / 3][j / 3] |= (1 << num);
                } else {
                    dots.emplace_back(make_pair(i, j));
                }
            }
        }
        valid = false;
        backtrack(board, dots, 0, row, col, win);
        // board = ans;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solution.solveSudoku(board);
    return 0;
}