class Solution {
public:
    static bool cmp(vector<string> a,vector<string> b){
        return stoi(a[1])!=stoi(b[1])?stoi(a[1])<stoi(b[1]):a[0]=="OFFLINE"?true:false; 
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), cmp);
        vector<int>ans(numberOfUsers, 0), tmp(numberOfUsers, 1);
        
        unordered_map<int, int>mp;
        for(auto it : events){
            string type = it[0];
            int tt = stoi(it[1]);
            if(type =="OFFLINE"){
                int ids = stoi(it[2]);
                if(ids>=0 && ids<numberOfUsers){
                    mp[ids] = tt +60;
                    tmp[ids] = 0;
                }
            }
            for(int i = 0; i<numberOfUsers; i++){
                if(tmp[i]==0 && mp[i]<=tt){
                    tmp[i] = 1;
                }
            }
            if(type== "MESSAGE"){
                string str = it[2];
                vector<int>st;
                if(str =="ALL"){
                    for(int i =0; i<numberOfUsers; i++){
                        st.push_back(i);
                    }
                }
                else if(str =="HERE"){
                    for(int i = 0; i<numberOfUsers; i++){
                        if(tmp[i]){
                            st.push_back(i);
                        }
                    }
                }
                else{
                    stringstream ss(str);
                    string str;
                    while(ss>>str){
                        int ids = stoi(str.substr(2));
                        if(ids>=0 && ids<numberOfUsers){
                            st.push_back(ids);
                        }
                    }
                }
                for(auto it : st){
                    ans[it]++;
                }
            }
        }
        return ans;
    }
};