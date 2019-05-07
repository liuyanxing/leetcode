/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (30.11%)
 * Total Accepted:    268.8K
 * Total Submissions: 870.5K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
class Solution {
public:
    bool foundWord(int i, int j, vector<vector<char>>& board, string word, int k) {
        if (board[i][j] != word[k] || i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || k == word.size()) {
            return false;
        }
        if (k == word.size() - 1 && board[i][j] == word[k]) {
            return true;
        }
        
        return foundWord(i+1, j, board, word, k+1)  || foundWord(i - 1, j, board, word, k + 1) || foundWord(i, j+1, board, word, k+1) || foundWord(i, j-1, board, word, k + 1);
                
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (foundWord(i, j, board, word, 0)) {
                    return true;
                }
            }
        }
        return false;
        
    }
};

