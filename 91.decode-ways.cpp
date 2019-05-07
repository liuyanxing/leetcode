/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (21.72%)
 * Total Accepted:    252.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */
#include <string>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        return decodes(s, 0);
    }
    int decodes(string s, int p) {
        int n = s.size();
        if (p == n) {
            return 1;
        }
        if (s[p] == '0') {
            return 0;
        }
        
        int res = decodes(s, p + 1);
        if (p < n - 1 && (s[p] == '1' || (s[p] == '2' && s[p+1] < '7'))) {
            res += decodes(s, p + 2);
        }
        
        return res;
    }
};

