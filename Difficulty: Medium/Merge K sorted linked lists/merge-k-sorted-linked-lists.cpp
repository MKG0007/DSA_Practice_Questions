/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            Node* head=arr[i];
            while(head!=NULL){
                
                
                ans.push_back(head->data);
                head=head->next;
            }
        }
        sort(ans.begin(),ans.end());
        
        
        Node* dummy=new Node(-1);
        Node* curr=dummy;
        for(int i=0;i<ans.size();i++){
            curr->next=new Node(ans[i]);
            curr=curr->next;
        }
        return dummy->next;
    }
};