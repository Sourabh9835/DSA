class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int fnum = nums[i];
            int moreNeeded = target - fnum;
            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i};
            }
            mpp[fnum] = i;
        }
        return {-1, -1};
    }
};