class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        std::sort(people.begin(), people.end());  // Sort people by weight
        int left = 0, right = people.size() - 1;
        int boats = 0;

        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;  // Pair the lightest and heaviest person
            }
            right--;  // The heaviest person always boards
            boats++;  // Increase the boat count
        }

        return boats;
    }
};