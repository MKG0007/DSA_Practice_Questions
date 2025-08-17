/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        //  code here
        vector<int> ans;
        Node* temp = head;
        
        while(temp){
            ans.push_back(temp->data);
            temp = temp->next;
        }
        
        for(int i = 0 ; i<ans.size()/2 ; i++){
            if(ans[i] != ans[ans.size()-i-1]){
                return false;
            }
        }
        
        return true;
    }
};