class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]]++;
        int right = sqrt(maxVal);
        for (int i = minVal; i <= maxVal; i++) {
            int val = i;
            int cnt = 0;
            while (val <= maxVal) {
                if (mp.find(val) != mp.end()) {
                    cnt++;
                    ans = max(ans, cnt);
                    mp[val]--;
                    if (mp[val] == 0)
                        mp.erase(val);
                    if(val<=1000)val =val * val;
                    else break;
                } else
                    break;
            }
        }
        if (ans > 1)
            return ans;
        return -1;
    }
};