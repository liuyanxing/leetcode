/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 *
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
 *
 * algorithms
 * Medium (45.16%)
 * Total Accepted:    17.3K
 * Total Submissions: 37.9K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n2'
 *
 * We are given a binary tree (with root node root), a target node, and an
 * integer value K.
 * 
 * Return a list of the values of all nodes that have a distance K from the
 * target node.  The answer can be returned in any order.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
 * 
 * Output: [7,4,1]
 * 
 * Explanation: 
 * The nodes that are a distance 2 from the target node (with value 5)
 * have values 7, 4, and 1.
 * 
 * 
 * 
 * Note that the inputs "root" and "target" are actually TreeNodes.
 * The descriptions of the inputs above are just serializations of these
 * objects.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The given tree is non-empty.
 * Each node in the tree has unique values 0 <= node.val <= 500.
 * The target node is a node in the tree.
 * 0 <= K <= 1000.
 * 
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode *, TreeNode *> parents;
        buildConnect(root, parents);
        vector<int> res;
        queue<TreeNode *> Q;
        set<TreeNode*> visited;
        visited.insert(root);
        Q.push(target);
        K++;
        while(Q.size()){
            K--;
            for (int qSize = Q.size(); qSize > 0; qSize--) {
                TreeNode *node = Q.front();                
                visited.insert(node);
                if (K == 0) {
                    res.push_back(node->val);
                }
                Q.pop();
                if (node == NULL) continue;
                if (!visited.count(node->left) && node->left) {
                    Q.push(node->left);
                }
                if (!visited.count(node->right) && node->right) {
                    Q.push(node->right);
                }
                if (!visited.count(parents[node])) {
                    Q.push(parents[node]);
                }
            }
        }
        
        return res;
    }
    void buildConnect(TreeNode* root, unordered_map<TreeNode *, TreeNode *> &parents) {
        if (!root) return;
        if (root->left) {
            parents[root->left] = root;
            buildConnect(root->left, parents);
        }
        if (root->right) {
            parents[root->right] = root;
            buildConnect(root->right, parents);
        }
    }
};

