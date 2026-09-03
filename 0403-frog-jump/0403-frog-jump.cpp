class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> mp;
        for (int stone : stones) {
            mp[stone] = {};          // pre-seed real stone positions only
        }
        mp[stones[0]].insert(0);     // start: 0 jumps to reach the first stone

        for (int stone : stones) {
            // copy current jump sizes so inserting into mp[stone] itself
            // (the jumpSize-1 case landing back on `stone`) is never UB
            vector<int> jumps(mp[stone].begin(), mp[stone].end());

            for (int jumpSize : jumps) {
                for (int next : {jumpSize - 1, jumpSize, jumpSize + 1}) {
                    if (next <= 0) continue;                 // must jump forward
                    int target = stone + next;
                    auto it = mp.find(target);
                    if (it != mp.end()) {                    // only if target is a real stone
                        it->second.insert(next);
                    }
                }
            }
        }

        return !mp[stones.back()].empty();
    }
};