/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (38.77%)
 * Total Accepted:    219.9K
 * Total Submissions: 563.1K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> tmp;
        vector<vector<int>> res;
        backtrack(tmp, used, nums, res);
        return res;

    }
    void backtrack(vector<int> &tmp, vector<bool> &used, vector<int> &nums, vector<vector<int>> &res) {
        if (tmp.size() == nums.size()){
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] || (i > 0 && nums[i] == nums[i - 1]) && used[i - 1]) continue;
            used[i] = true; 
            tmp.push_back(nums[i]);
            backtrack(tmp, used, nums, res);
            tmp.pop_back();
            used[i] = false;
        }
    }
};
