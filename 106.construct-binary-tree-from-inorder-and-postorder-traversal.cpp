/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (37.56%)
 * Total Accepted:    147.5K
 * Total Submissions: 381.2K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 */
class Solution {
public:
    int pInorder;
    int pPostorder;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, TreeNode* end) {
        if (pPostorder < 0) {
            return nullptr;
        }
        TreeNode* n = new TreeNode(postorder[pPostorder--]);
        if (inorder[pInorder] != n->val) {
            n->right = buildTree(inorder, postorder, n);
        }
        pInorder--;
        if (end == nullptr || inorder[pInorder] != end->val) {
            n->left = buildTree(inorder, postorder, end);
        }
        return n;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        pInorder = inorder.size() - 1;
        pPostorder = postorder.size() - 1;

        return buildTree(inorder, postorder, nullptr);
    }
};

