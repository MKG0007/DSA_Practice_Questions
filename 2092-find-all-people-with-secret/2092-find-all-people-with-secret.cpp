class Solution {
public:
    int find(int x, vector<int>& p) {
        return p[x] == x ? x : p[x] = find(p[x], p);
    }

    void unite(int a, int b, vector<int>& p) {
        int pa = find(a, p), pb = find(b, p);
        if (pa != pb) p[pb] = pa;
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        sort(meetings.begin(), meetings.end(),
             [](auto& a, auto& b) { return a[2] < b[2]; });

        vector<int> parent(n), know(n, 0);
        iota(parent.begin(), parent.end(), 0);

        know[0] = know[firstPerson] = 1;

        for (int i = 0; i < meetings.size(); ) {
            int t = meetings[i][2];
            vector<int> temp;

            int j = i;
            while (j < meetings.size() && meetings[j][2] == t) {
                unite(meetings[j][0], meetings[j][1], parent);
                temp.push_back(meetings[j][0]);
                temp.push_back(meetings[j][1]);
                j++;
            }

            for (int x : temp)
                if (know[x])
                    know[find(x, parent)] = 1;

            for (int x : temp)
                know[x] |= know[find(x, parent)];

            for (int x : temp)
                parent[x] = x;

            i = j;
        }

        vector<int> res;
        for (int i = 0; i < n; i++)
            if (know[i]) res.push_back(i);
        return res;
    }
};