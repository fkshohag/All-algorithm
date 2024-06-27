class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }
    
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<pair<int, string>>> userVsTimeVsWebsite;
        for(int i = 0; i < username.size(); i++) {
            userVsTimeVsWebsite[username[i]].push_back({timestamp[i], website[i]});
        }

        map<vector<string>, int> patternToCount;

        for (auto& [user, sequence] : userVsTimeVsWebsite) {
            // sort based on timestamp then website name
            sort(sequence.begin(), sequence.end());
            set<vector<string>> patterns;
            int sequenceSize = sequence.size();

            for (int i = 0; i < sequenceSize; i++) {
                for (int j = i + 1; j < sequenceSize; j++) {
                    for (int k = j + 1; k < sequenceSize; k++) {
                        auto pattern = vector<string> ({sequence[i].second, sequence[j].second, sequence[k].second});
                        patterns.insert(pattern);
                    }
                }
            }
            for (const auto &p : patterns) {
                patternToCount[p]++;
            }
        }
        int maxCount = 0;
        vector<string> ans;
        for (const auto& [pattern, count] : patternToCount) {
            if (count > maxCount) {
                ans = pattern;
                maxCount = count;
            }
        }
        return ans;
    }
};