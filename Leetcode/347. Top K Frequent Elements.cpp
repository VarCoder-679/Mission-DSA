class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> freq;

        for(auto& num: nums) {
            freq[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto& pair: freq) {
            pq.push({pair.second, pair.first});
        }

        while(k--) {
            int el = pq.top().second;
            pq.pop();
            ans.push_back(el);
        }

        return ans;
    }
};
