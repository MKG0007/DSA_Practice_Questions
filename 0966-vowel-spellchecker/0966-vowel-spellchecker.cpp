class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());

        
        unordered_map<string, string> lower_map, vowel_map;
        
        for (const string &word : wordlist) {
            string lower = toLower(word);


            if (lower_map.find(lower) == lower_map.end()) {
                lower_map[lower] = word;
            }
            
            string voweless = replaceVowels(lower);
            if (vowel_map.find(voweless) == vowel_map.end()) {
                vowel_map[voweless] = word;
            }
        }
        
        vector<string> result;
        result.reserve(queries.size());
        
        for (const string &query : queries) {
            if (exact.find(query) != exact.end()) {
                result.push_back(query);
                continue;
            }
            
            string lower_query = toLower(query);
            auto it_lower = lower_map.find(lower_query);
            if (it_lower != lower_map.end()) {
                result.push_back(it_lower->second);
                continue;
            }
            
            string voweless_query = replaceVowels(lower_query);
            auto it_vowel = vowel_map.find(voweless_query);
            if (it_vowel != vowel_map.end()) {
                result.push_back(it_vowel->second);
                continue;
            }
            
            result.push_back("");
        }
        
        return result;
    }
    
private:
    string toLower(const string &s) {
        string res = s;
        for (char &c : res) {
            c = tolower(c);
        }
        return res;
    }
    
    string replaceVowels(const string &s) {
        string res = s;
        for (char &c : res) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '#';
            }
        }
        return res;
    }
};