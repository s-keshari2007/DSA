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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        stack<TreeNode*>  s;

        while(curr != NULL){
            if(curr->left != NULL){
                if(curr->right != NULL){
                s.push(curr->right);
                }
                curr->right = curr->left;
                curr->left = NULL;

                curr = curr->right;

            }
            else{
                if(!s.empty() && curr->right == NULL){
                    TreeNode* helper = s.top();
                    s.pop();

                    curr->right = helper;
                    curr->left = NULL;
                    curr = curr->right;
                }
                else {
                    curr = curr->right;
                }
                
            }
        }
    }
};