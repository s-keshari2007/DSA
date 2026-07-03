/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // doing the question with the BFS approach...can also be done with inorder or preorder
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr == NULL) s.append("#,");
            else s.append(to_string(curr->val) + ",");
            if(curr != NULL){
                q.push(curr->left); // this time we even are adding NULL pointer to queue to show the in the string
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    // Edge case: empty string means no tree at all
    if(data.size() == 0) return NULL;

    // Wrap the encoded string in a stringstream so we can
    // extract comma-separated tokens one at a time using getline
    stringstream s(data);
    string str;

    // First token in the string is always the root's value
    getline(s, str, ',');// this functin will consume the inbetween commas 
    TreeNode *root = new TreeNode(stoi(str)); // stoi: convert string -> int

    // Use a queue to rebuild the tree level by level (BFS),
    // matching the order in which it was originally serialized
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {

        // Take the next node whose children we need to attach
        TreeNode *node = q.front();
        q.pop();

        // ---- Process LEFT child ----
        getline(s, str, ','); // read next token up to the next comma
        if(str == "#") {
            // "#" means no left child
            node->left = NULL;
        }
        else {
            // Create the left child, link it, and queue it
            // so its own children get processed later
            TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        // ---- Process RIGHT child ----
        getline(s, str, ','); // read next token
        if(str == "#") {
            // "#" means no right child
            node->right = NULL;
        }
        else {
            // Create the right child, link it, and queue it
            TreeNode* rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }

    // All nodes reconstructed and linked; return the tree's root
    return root;
}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));