
/*
Given an array arr of size n containing elements, find the next greater element for each element in the array in the order of their appearance.

Input: arr = [1, 3, 2, 4]
Output: [3, 4, 4, -1]

Constraints:
  1 ≤ n ≤ 105
  0 ≤ arr[i] ≤ 109
*/

class Solution {
public:
// Optimal Approach
// loop + stl (monotonic stack)
    vector<int> nextLargerElement(vector<int> arr) {
        int n = arr.size();  // size of the array
        
        // stack to maintain the list of greater elements in decreasing order.
        stack<int>st;

        // To store next greater emement.
        vector<int>ans(n);

        // Iterating in the arr from back.
        for(int i = n-1;i>=0;i--){
            
            /* if top of the stack is less than arr[i] then pop it out 
            untill top greater than arr[i] achieve */
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }

            /* if stack is  empty store -1 in ans 
            i.e no next greater element exist */
            if(st.empty()){
                ans[i]=-1;
            }
            // store next greater element
            else{
                ans[i]  = st.top();
                st.push(arr[i]);
            }
            // Push current element into the stack.
            st.push(arr[i]);
        }
        return ans;
    }
};
