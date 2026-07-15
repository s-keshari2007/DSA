/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //TC = O((logN)^2) SC = O(logN)
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int lh = findheightLeft(root);
        int rh = findheightRight(root);

        // the tree is a complete tree
        if(lh == rh) return (1 << lh) - 1; //using bit manipulation

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findheightLeft(TreeNode* node){
        int ht = 0;
        while(node){
            ht++;
            node = node->left;
        }

        return ht;
    }
    int findheightRight(TreeNode* node){
        int ht = 0;
        while(node){
            ht++;
            node = node->right;
        }
        return ht;
    }
};