#include <bits/stdc++.h>

using namespace std;

 

class Solution {

public:

    bool isVowel(char ch) {

        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';

    }

    int countBalanced(vector<string>& arr) {

        int n = arr.size();

        vector<int> balance(n); 

        for (int i = 0; i < n; ++i) {

            int vowels = 0, consonants = 0;

            for (char ch : arr[i]) {

                if (isVowel(ch)) vowels++;

                else consonants++;

            }

            balance[i] = vowels - consonants;

        }

        unordered_map<int, int> freq;

        freq[0] = 1; 

        int res = 0, sum = 0;

        for (int i = 0; i < n; ++i) {

            sum += balance[i];

            res += freq[sum]; // if sum was seen before, all ranges between previous and current index are balanced

            freq[sum]++;

        }

        return res;

    }

};