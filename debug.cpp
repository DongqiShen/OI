/*
 * Description: debug purpose
 * Date: 2021.09.12
 * Author: 觉不醒的王子殿下
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>
#include <unordered_set>

using namespace std;

typedef struct Trie{
    vector<Trie*> next;
    string word;
    Trie(){
        next.resize(26);
        word = "";
    }

};

class Solution
{
private:
    unordered_set<string> strs;
    vector<vector<int>> path = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    void insert(Trie* trie, string word){
        int n = word.size();
        for(int i = 0; i < n; ++i){
            int ch = word[i] - 'a';
            if(trie->next[ch] == nullptr){
                Trie *node = new Trie();
                trie->next[ch] = node;
            }
            trie = trie->next[ch];
        }
        trie->word = word;
    }
    void dfs(vector<vector<char>>& board, int i, int j, Trie* trie, vector<vector<int>>& visited){
        int n = board.size();
        int m = board[0].size();
        int ch = board[i][j] - 'a';
        if(trie == nullptr){
            return;
        }
        if(trie->next[ch] != nullptr && !trie->word.empty()){
            strs.insert(trie->word);
        }
        for(int k = 0; k < 4; ++k){
            int x = i + path[i][0];
            int y = j + path[i][1];
            if(x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]){
                visited[x][y] = 1;
                dfs(board, x, y, trie->next[ch], visited);
                visited[x][y] = 0;
            }
        }
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie *trie = new Trie();
        int n_words = words.size();
        for(int i = 0; i < n_words; ++i){
            insert(trie, words[i]);
        }
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        visited[0][0] = 1;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                vector<vector<int>> visited(n, vector<int>(m, 0));
                visited[i][j] = 1;
                dfs(board, i, j, trie, visited);
            }
        }
        
        vector<string> ans(strs.begin(), strs.end());
        return ans;
    }
};

int main()
{
    Solution solutuon;
    //vector<vector<char>> board = {["o", "a", "a", "n"], [ "e", "t", "a", "e" ], [ "i", "h", "k", "r" ], [ "i", "f", "l", "v" ]};
    return 0;
}