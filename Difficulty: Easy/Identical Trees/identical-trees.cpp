/* A binary tree node


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check if two trees are identical.
    bool check(Node* r1 , Node* r2){
        if(r1 == NULL || r2 == NULL){
            return true;
        }
        
        if(r1->data != r2->data) return false;
        if(check(r1->left , r2->left) == false) return false;
        if(check(r1->right , r2->right) == false) return false;
                return true;
    }
    bool isIdentical(Node *r1, Node *r2) {
        
        return check(r1 , r2);
    }
};