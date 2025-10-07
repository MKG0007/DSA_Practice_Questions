class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> lakeDay;
        set<int> dry;
        int n = rains.size();
        vector<int> res(n, 1);

        for (int i = 0; i < n; ++i) {


            int lake = rains[i];
            if (lake == 0) {
                dry.insert(i);
            } else {
                res[i] = -1;
                if (lakeDay.count(lake)) {

                    
                    auto it = dry.upper_bound(lakeDay[lake]);
                    if (it == dry.end()) return {};
                    res[*it] = lake;
                    dry.erase(it);
                }
                lakeDay[lake] = i;
            }
        }
        return res;
    }
};