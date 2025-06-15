class Solution {
public:
    string replaceAll(string s,char x, char y){
        for(char& ch: s) if(ch==x) ch=y;
        return s;
    }


    int maxDiff(int num) {
        string mx=to_string(num),mn=to_string(num),s=to_string(num);

        int j=0;
        while(j<mx.size()-1 && mx[j]=='9') j+=1;
        mx=replaceAll(mx,mx[j],'9');

        for(int i=0;i<mn.size();i++){
            if(i==0){
                if(mn[i]!='1'){
                    mn=replaceAll(mn,mn[0],'1');
                    break;
                }
            }else{
                if(mn[i]!='0' && mn[i]!=mn[0]){
                    mn=replaceAll(mn,mn[i],'0');
                    break;
                }
            }
        }

        
        return stoi(mx)-stoi(mn);
    }
};