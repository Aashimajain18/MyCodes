/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int t=target;
        vector<int>ans;
        ans.push_back(-1);
        ans.push_back(-1);
        if(n==1){
            if(nums[0]==t){
                ans[0]=0;
                ans[1]=0;
                return ans;
            }
        }
        int s=0,e=n-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]>t){
                e=mid-1;
            }
            else if(nums[mid]<t){
                s=mid+1;
            }
            else{
                //nums[mid]=t
                int temp=mid;
                while(temp-1>=0 && nums[temp-1]==t ){
                    temp--;
                }
                ans[0]=temp;
                 while( mid+1<n && nums[mid+1]==t){
                    mid++;
                }
                ans[1]=mid;
                break;
            }
        }
        return ans;
    }
};
