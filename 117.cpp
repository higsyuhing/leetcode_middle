/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void helper(Node *node, vector<Node *>& array, int level){
        if (node == NULL)
            return; 
        
        // curr, right, left. 
        if (level == array.size()){
            array.push_back(node); 
        }
        else{
            node->next = array[level]; 
            array[level] = node; 
        }
        helper(node->right, array, level+1); 
        helper(node->left, array, level+1); 
    }

    Node* connect(Node* root) {
        vector<Node *> array; 
        helper(root, array, 0); 
        return root; 
    }
};

/*
//Another version with two while loops, but with same performance, and the meaning is clearer...
public class Solution {
    public void connect(TreeLinkNode root) {
        if (root == null) return;
        TreeLinkNode dummy = new TreeLinkNode(0);
        TreeLinkNode p = dummy;
        TreeLinkNode head = root;
        while (head != null) { //if the head of the traverse layer is not null, then traverse that layer...
            TreeLinkNode node = head;
            while (node != null) {
                if (node.left != null) {
                    p.next = node.left;
                    p = p.next;
                }
                if (node.right != null) {
                    p.next = node.right;
                    p = p.next;
                }
                node = node.next;
            }
            //after traversed to the end of current layer, move to the next layer
            head = dummy.next;
            dummy.next = null;
            p = dummy;
        }
    }
}
*/
