// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         // this solution gives TLE
//         // int count = 0;
//         // int n =nums.size();
//         // unordered_set<int> st;
//         // for(int i = 0; i < n; i++){
//         //     for(int j = i; j < n; j++){
//         //         if(st.find(nums[j]) == st.end()){
//         //             st.insert(nums[j]);
//         //         }
//         //         if(st.size() > k) break;

//         //         if(st.size() == k) count++;
//         //     }
//         //     st.clear();
//         // }     

//         // return count;
//     }
// };
class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int,int> freq;
        int left = 0, count = 0;
        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            while (freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
};