/*
Given an array of integers asteroids, where each integer represents an asteroid in a row, 
determine the state of the asteroids after all collisions. In this array, the absolute value 
represents the size of the asteroid, and the sign represents its direction (positive meaning 
right and negative meaning left). All asteroids move at the same speed. 

Input: asteroids = [2, -2]
Output: []

Constraints:
·  2 <= asteroids.length <= 105
·  -106 <= asteroids[i] <= 106
·  asteroids[i] != 0
*/

// loop + stl
// TC : O(n)
// SC : O(n)
class Solution {
   public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
      // vector to store ans
        vector<int> ans;
        int n = asteroids.size();

      // traversing the list of asteroid 
        for (int i = 0; i < n; i++) {
          // if asteroid is movin in positive direction push it into vector.
            if (asteroids[i] > 0) {
                ans.push_back(asteroids[i]);
            } else {
              // pop the vector till vector become empty or negative asteroid or higher positive asteroid is achieved at back
                while (ans.size() != 0 && ans.back() > 0 &&
                       ans.back() < abs(asteroids[i])) {
                    ans.pop_back();
                }
              /* if back of the vector contain same size but opposite sign asteroid pop
              it out and continue to next step becaue it(-ve asteroid) also get destroyed.*/
                if (ans.size() != 0 && ans.back() == abs(asteroids[i])) {
                    ans.pop_back();
                    continue;
                }
              // if back contain higher asteroid so the negative one is destroyed
                if (ans.size() != 0 && ans.back() > 0) continue;
              /* push the negative asteroid because it is not destroyed in the process
              so consider it as a answer */
                ans.push_back(asteroids[i]);
            }
        }

        return ans;
    }
};
