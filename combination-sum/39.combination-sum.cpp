/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (46.14%)
 * Total Accepted:    303.2K
 * Total Submissions: 651.4K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int len = candidates.size();
        vector<int> tmp;
        backtrack(0, tmp, len, target, candidates, res);
        return res;
    }
    void backtrack(int start, vector<int> &tmp, int &len, int target, vector<int> &candidates, vector<vector<int>> &res) {
        if (target < 0) return;
        if (target == 0) {
           res.push_back(tmp);
           return;
        }
        for (int i = start; i < len; i++) {
            tmp.push_back(candidates[i]);
            backtrack(i, tmp, len, target - candidates[i], candidates, res);
            tmp.pop_back();
        }
    }
};

