/*
Given an array of integers arr of size n, calculate the sum of the minimum value in each (contiguous) subarray of arr. 
Since the result may be large, return the answer modulo 109 +7.

Examples:
  Input: arr = [3, 1, 2, 5]
  Output: 18

Constraints:
  1 <= arr.length <= 105
  1 <= arr[i] <= 106
  
*/


/*
  Optimal Approach:
  Pattern : loop + Stl 
  Intitution : find the no of times an element act as mini element in all possible subarry.
  Formula for sum : sum = sum + freq_i*arr[i];  f
  Formula for frequency of element : req_i = (curr_idx - prev_smaller_ele_idx) * (next_smaller_ele_idx -  curr_idx)
*/

class Solution {
   public:
    vector<int> findNextSmallerElement(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n);
        vector<int> st;

        for (int i = n - 1; i >= 0; i--) {
            int currEle = arr[i];

            while (st.size() && arr[st.back()] >= currEle) {
                st.pop_back();
            }
            if (!st.size()) {
                ans[i] = n;
            } else {
                ans[i] = st.back();
            }
            st.push_back(i);
        }

        return ans;
    }
    vector<int> findPrevSmallerElement(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n);
        vector<int> st;

        for (int i = 0; i < n; i++) {
            int currEle = arr[i];

            while (st.size() && arr[st.back()] > currEle) {
                st.pop_back();
            }
            if (!st.size()) {
                ans[i] = -1;
            } else {
                ans[i] = st.back();
            }
            st.push_back(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        int sum = 0, mod = (int)1e9 + 7;

        vector<int> prevSmaller = findPrevSmallerElement(arr);
        vector<int> nextSmaller = findNextSmallerElement(arr);

        for (int i = 0; i < n; i++) {
            long long frequency = (i - prevSmaller[i]) * (nextSmaller[i] - i);
            int val = (frequency*arr[i]) % mod;
            sum = (sum + val) % mod;
        }
        return sum;
    }
};
