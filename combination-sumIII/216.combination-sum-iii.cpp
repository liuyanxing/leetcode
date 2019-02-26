/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (50.14%)
 * Total Accepted:    112.8K
 * Total Submissions: 223.7K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;        
        backtrack(1, tmp, n, n, k, res);
        return res;
    }
    void backtrack(int start, vector<int> &tmp, int remain, int &n, int &k, vector<vector<int>> &res) {
        if (remain == 0 && tmp.size() == k) {
            res.push_back(tmp);
            return;
        }
        if (remain < 0) {
            return;
        }
        for (int i = start; i <= 9; i++) {
            tmp.push_back(i);
            backtrack(i + 1, tmp, remain - i, n, k, res);
            tmp.pop_back();
        }
    }
};

