/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (45.32%)
 * Total Accepted:    208.8K
 * Total Submissions: 458K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
 */
// /**
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
//  */

#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levelOrder;
        queue<TreeNode *> Q;
        Q.push(root);
        while(!Q.empty()){
            int n = Q.size();
            vector<int> visit;
            while(n-- > 0){
                TreeNode *p = Q.front();
                visit.push_back(p->val);
                Q.pop();
                if (p->left) Q.push(p->left);
                if (p->right) Q.push(p->right);
            }
            levelOrder.push_back(visit);
        }
        
    }
};

