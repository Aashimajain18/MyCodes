/*
Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

 

Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:

Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.
 

Constraints:

n == nums.length
1 <= n <= 10^4
-10^5 <= nums[i] <= 10^5
*/

//my solution
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0;
        for(int i=1;i<nums.size();i++){

            if(nums[i-1]>nums[i]){
                if(i>=2){
                    if(nums[i-2]>nums[i]){
                       nums[i]=nums[i-1];
                        cnt++;
                    }
                        else{
                      nums[i-1]=nums[i];
                        cnt++; 
                        }
                    }
                else{
                    nums[i-1]=nums[i];
                    cnt++;
                }
                   
                }
                
            }
                    if(cnt>1){
                return false;
            }
        
        return true;
    }
};

//logic:-
/*
This problem is like a greedy problem. When you find nums[i-1] > nums[i] for some i, you will prefer to change nums[i-1]'s value, 
since a larger nums[i] will give you more risks that you get inversion errors after position i. 
But, if you also find nums[i-2] > nums[i], then you have to change nums[i]'s value instead, or else you need to change both of nums[i-2]'s 
and nums[i-1]'s values.
*/


//another short solution with same logic
bool checkPossibility(vector<int>& nums) {
        int cnt = 0;                                                                    //the number of changes
        for(int i = 1; i < nums.size() && cnt<=1 ; i++){
            if(nums[i-1] > nums[i]){
                cnt++;
                if(i-2<0 || nums[i-2] <= nums[i])nums[i-1] = nums[i];                    //modify nums[i-1] of a priority
                else nums[i] = nums[i-1];                                                //have to modify nums[i]
            }
        }
        return cnt<=1;
    } 

