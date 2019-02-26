/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (50.40%)
 * Total Accepted:    327.2K
 * Total Submissions: 644.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        backtrack(0, tmp, nums, res);
        return res;
    }
    void backtrack(int start, vector<int> &tmp, vector<int>& nums, vector<vector<int>> &res) {
        res.push_back(tmp);
        for (int i = start; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtrack(i + 1, tmp, nums, res);
            tmp.pop_back();
        }
    }
};
