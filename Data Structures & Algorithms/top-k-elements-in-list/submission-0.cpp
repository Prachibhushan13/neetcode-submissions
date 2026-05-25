class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: frequency count
        for (int x : nums) {
            freq[x]++;
        }

        // Step 2: insert in priority queue (max heap)
        priority_queue<pair<int, int>> pq;
        for (const auto &[num, f] : freq) {
            pq.push({f, num});
        }

        // Step 3: take top k
        vector<int> ans;
        ans.reserve(k);

        while (k--) {
            const auto &[f, num] = pq.top();
            ans.push_back(num);
            pq.pop();
        }

        return ans;
    }
};