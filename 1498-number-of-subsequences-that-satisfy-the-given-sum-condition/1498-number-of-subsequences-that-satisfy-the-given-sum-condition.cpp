class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int res =  0;
        int mod = 1e9 + 7;
        vector<int> pre = {1};
        for(int i = 0; i < nums.size(); i++)
        pre.push_back((pre.back() << 1) % mod);

        sort(nums.begin(), nums.end());

        for(int i = 0, j = nums.size() - 1; i <= j; i++){

            while(j>= 0 && nums[i] + nums[j] > target) --j;

            if(j >= i){
                int pw = pre[j - i];
                res = (res + pw) % mod;
            }
        }
        return res;
    }
};