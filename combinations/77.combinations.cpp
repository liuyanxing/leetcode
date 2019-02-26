/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (45.55%)
 * Total Accepted:    184.8K
 * Total Submissions: 402.6K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(1, 0, k, n, tmp, res);
        return res;
    }
    void backtrack(int start, int cnt, int &k, int &n, vector<int> &tmp, vector<vector<int>> &res) {
        if (cnt == k) {
            res.push_back(tmp);
            return;
        }
        for (int i = start; i < n + 1; i++) {
            tmp.push_back(i);
            backtrack(i + 1, cnt + 1, k, n, tmp, res);
            tmp.pop_back();
        }
    }
};

