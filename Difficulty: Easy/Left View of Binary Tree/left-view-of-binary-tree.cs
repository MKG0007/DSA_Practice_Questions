/*
public class Node {
    public int data;
    public Node left;
    public Node right;

    public Node(int key) {
        this.data = key;
        this.left = null;
        this.right = null;
    }
}
*/

class Solution {
    
    void leftView(List<int> ans , Node root , int level){
        if(root == null){
            return;
        }
        if(level == ans.Count){
            ans.Add(root.data);
        }
        leftView(ans , root.left , level+1);
        leftView(ans , root.right , level+1);
        
    }
    public List<int> leftView(Node root) {
        
        List<int> ans = new List<int>();
        if(root == null) return ans;
        
        leftView(ans , root , 0);
        
        return ans;
    }
}