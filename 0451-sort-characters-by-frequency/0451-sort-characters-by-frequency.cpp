class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequency of each character
        unordered_map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }
        
        // Step 2: Create buckets where bucket[i] stores characters with frequency i
        int n = s.length();
        vector<vector<char>> buckets(n + 1);
        for (const auto& [charKey, freq] : counts) {
            buckets[freq].push_back(charKey);
        }
        
        // Step 3: Iterate backwards from maximum frequency to 1 to build result
        string result = "";
        for (int freq = n; freq > 0; --freq) {
            for (char c : buckets[freq]) {
                result.append(freq, c); // Append character c repeated 'freq' times
            }
        }
        
        return result;
    }
};