/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 *
 * https://leetcode.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (74.06%)
 * Total Accepted:    50.8K
 * Total Submissions: 70.2K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * Given an array of integers A sorted in non-decreasing order, return an array
 * of the squares of each number, also in sorted non-decreasing order.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 10000
 * -10000 <= A[i] <= 10000
 * A is sorted in non-decreasing order.
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ret(A.size());
        int left = 0, right = A.size() - 1;
        int index = 0;
        while(right >= left){
            if ( abs(A[left]) > abs(A[right]) ) {
                ret[index] = A[left] * A[left];
                left++;
            } else {
                ret[index] = A[right] * A[right];
                right--;
            }
            index++;
        }
        return ret;
    }
};

