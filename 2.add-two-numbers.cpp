/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (30.37%)
 * Total Accepted:    821.1K
 * Total Submissions: 2.7M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* c1 = l1; 
       ListNode* c2 = l2; 
       ListNode* sentinel = new ListNode(0); 
       ListNode* d = sentinel;
       int sum = 0;
       while(c1 || c2){
           sum /= 10;
           if (c1) {
               sum = sum + c1->val;
               c1 = c1->next;
           }
           if (c2) {
               sum = sum + c2->val;
               c2 = c2->next;
           }
           d->next = new ListNode(sum % 10);
           d = d->next;
       }
       if (sum / 10 == 1) {
           d->next = new ListNode(1);
       }
       return sentinel->next;
    }
};

