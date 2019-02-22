/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (52.86%)
 * Total Accepted:    335.7K
 * Total Submissions: 631.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

    }
    void backtrack(vector<vector<int>> &res, vector<int> &tmpList, vector<int> &nums) {
        if (tmpList.size() == nums.size()) {
            res.push_back(vector<int>(tmpList.begin(), tmpList.end()));
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (tmpList.count(nums[i] != 0)) continue;
                tmpList.push_back(nums[i]);
                backtrack(res, tmpList, nums);
                tmpList.pop_back();
            }
        }
    }
    
};
