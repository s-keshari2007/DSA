class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        // Taking XOR with a number with itself gives 0
        // taking XOR with 0 gives the same number itself
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};