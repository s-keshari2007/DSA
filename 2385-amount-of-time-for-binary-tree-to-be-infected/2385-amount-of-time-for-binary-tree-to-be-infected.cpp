/**
 * Definition for a binary tree TreeNode.
 * struct TreeTreeNode {
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
    void markParents(TreeNode* root,unordered_map<TreeNode*, TreeNode*> &parent_track){
        // we we  will be doing a level order traversal
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current->left){
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }
    TreeNode* find(TreeNode* root, int n) {
    if (root == NULL || root->val == n) {
        return root;
    }
    
    TreeNode* leftResult = find(root->left, n);
    if (leftResult != NULL) {
        return leftResult;
    }
    
    return find(root->right, n);
}
    int amountOfTime(TreeNode* root, int target) {
        // code here
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track);
        
        TreeNode* newtarget = find(root,target);
        
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*>q;
        q.push(newtarget);
        visited[newtarget] = true;
        int samay = 0;
        while(!q.empty()){
            int size = q.size();
            samay++;
            for(int i = 0; i<size; i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        return samay-1; 
    }
};