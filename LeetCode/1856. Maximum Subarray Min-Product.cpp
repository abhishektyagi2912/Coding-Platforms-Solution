class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix_sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            long long sum = prefix_sum[i - 1] + nums[i - 1];
            prefix_sum[i] = sum;
        }

        vector<int> right(n);
        vector<int> left(n);
        stack<int> st1,st2;

        for (int i = 0; i < n; i++) {
            while (!st1.empty() && nums[i] <= nums[st1.top()]) {
                st1.pop();
            }

            if (st1.empty()) {
                left[i] = -1;
            } else {
                left[i] = st1.top();
            }

            st1.push(i);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st2.empty() && nums[i] <= nums[st2.top()]) {
                st2.pop();
            }

            if (st2.empty()) {
                right[i] = n;
            } else {
                right[i] = st2.top();
            }

            st2.push(i);
        }
        long long maxlen = 0;
        for (int i = 0; i < n; i++) {
            long long sum = prefix_sum[right[i]] - prefix_sum[left[i] + 1];
            maxlen = max(maxlen, sum * nums[i]);
        }
        return maxlen % 1000000007;

    }
};
