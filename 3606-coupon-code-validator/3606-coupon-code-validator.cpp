class Solution {
public:

    bool check(string arr){
        int size = arr.size();
        if(size == 0) return false;

        for(int i = 0 ; i<size ; i++){
            char ch = tolower(arr[i]);
            if(ch>='a' && ch<= 'z' || ch>= '0' && ch<= '9' || ch == '_'){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool cline(string arr){
        if(arr == "electronics" || arr == "grocery" || arr == "pharmacy" || arr == "restaurant"){
            return true;
        }
        return false;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        vector<string> ans;
        int size = code.size();
        if(size == 0) return ans;
        unordered_map<string , int> m;
        m["electronics"] = 0;
        m["grocery"] = 1;
        m["pharmacy"] = 2;
        m["restaurant"] = 3;
        vector<multiset<string>> store(m.size());
        for(int i = 0 ; i<size ; i++){
            if(check(code[i]) && cline(businessLine[i]) && isActive[i]){

                store[m[businessLine[i]]].insert(code[i]);
            }
        }

        for(auto ele : store){
            for(auto e : ele){
                ans.push_back(e);
            }
        }
        return ans;
        
    }
};