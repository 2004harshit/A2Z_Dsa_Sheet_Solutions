/*
Given a circular integer array arr, return the next greater element for every element in arr.
The next greater element for an element x is the first element greater than x that we come across 
while traversing the array in a clockwise manner.
If it doesn't exist, return -1 for that element element.
Sample : 
  Input: arr = [3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9]
  Output: [10, -1, 6, 6, 2, 6, 7, 7, 9, 9, 10]
Constraints:
  1 ≤ n≤ 105
  0 ≤ arr[i] ≤ 109
*/

class Solution {
   public:
    // Optimal Approach
    // loop + stl (monotonic stack)
    vector<int> nextGreaterElements(vector<int> arr) {
        int n = arr.size();  // size of the array

        // stack to maintain the list of greater elements in decreasing order.
        stack<int> st;

        // To store next greater emement.
        vector<int> ans(n);

        // Iterating in the arr from back.
        for (int i = 2 * n - 1; i >= 0; i--) {
            /* if top of the stack is less than arr[i] then pop it out
            untill top greater than arr[i] achieve */
            while (!st.empty() && st.top() <= arr[i%n]) {
                st.pop();
            }
            
            // if i is less tan n then only store ans.
            if (i % n < n) {
                /* if stack is  empty store -1 in ans
            i.e no next greater element exist */
                if (st.empty()) {
                    ans[i%n] = -1;
                }
                // store next greater element
                else {
                    ans[i%n] = st.top();
                }
            }
            // Push current element into the stack.
            st.push(arr[i%n]);
        }
        return ans;
    }
};
