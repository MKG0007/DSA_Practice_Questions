class Solution {
public:
void backtrack(vector<int>& freq, int& count) {
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            count++;
            freq[i]--;
            backtrack(freq, count);
            freq[i]++;
        }
    }
}

int numTilePossibilities(string tiles) {
    vector<int> freq(26, 0);
    for (char c : tiles) {
        freq[c - 'A']++;
    }
    int count = 0;
    backtrack(freq, count);
    return count;
}
};