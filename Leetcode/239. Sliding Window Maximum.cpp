class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Deque to store indices of useful elements
        deque<int> dq;
        // Vector to store results
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices out of the current window from the front
            if (!dq.empty() && dq.front() == (i - k)) {
                dq.pop_front();
            }
            // Remove elements from the back while they are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            // Add current element's index to the deque
            dq.push_back(i);
            // Once the first window is formed, add the maximum (front of deque) to the result
            if (i >= (k - 1)) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
