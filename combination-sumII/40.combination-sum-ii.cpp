/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (39.71%)
 * Total Accepted:    199.7K
 * Total Submissions: 498.8K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);
        backtrack(0, target, tmp, used, candidates, res);
        return res;
    }
    void backtrack(int start, int target, vector<int> &tmp, vector<bool> &used, vector<int> &candidates, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(tmp);
            return;
        }
        if (target < 0) return;
        for (int i = start; i < candidates.size(); i++) {
            if ((i > start && candidates[i] == candidates[i-1])) continue;
            tmp.push_back(candidates[i]);
            used[i] = true;
            backtrack(i + 1, target - candidates[i], tmp, used, candidates, res);
            used[i] = false;
            tmp.pop_back();
        }

    }
};

