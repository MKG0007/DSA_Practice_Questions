class Solution{
  public:
    int findmaximum(string &s,int start,int end){
        char maxi=s[start];
        int index=start;
        for(int i=start+1;i<end;i++){
            if(maxi<=s[i]){
                maxi=s[i];
                index=i;
            }
        }
        return index;
    }
    string largestSwap(string &s){
        // code here
        int maxi=findmaximum(s,0,s.length());
        if(s[maxi]==s[0]){
            for(int i=1;i<s.length();i++){
                int maxii=findmaximum(s,i,s.length());
                if(s[maxii]==s[i]) continue;
                else{
                    swap(s[maxii],s[i]);
                    break;
                }
            }
        }
        else swap(s[0],s[maxi]);
        return s;
    }
};

