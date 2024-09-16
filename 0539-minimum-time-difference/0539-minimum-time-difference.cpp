class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        int n = timePoints.size();
        int ans = INT_MAX;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            string hrs = timePoints[i].substr(0, 2);
            string mint = timePoints[i].substr(3, 2);
           
            v.push_back(stoi(hrs) * 60 + stoi(mint));
        }
        sort(v.begin(), v.end());

        for (int i = 1; i < n; i++)
            ans = min(ans, v[i] - v[i - 1]);

        ans = min(ans, 1440 - v.back() + v[0]);

        return ans;
    }
};