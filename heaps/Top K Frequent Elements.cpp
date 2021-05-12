/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 10^5
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


*/

//My solution
class Solution {
public:
    typedef pair<int, int> custom_node;
    //order- freq,element
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue <custom_node> maxheap;
         unordered_map<int,int>f;//stores ele->freq
        
        for (int i = 0; i < nums.size(); i++){
		if(f.find(nums[i])==f.end()){
            //not found
            f[nums[i]]=1;
        }
           else{
     f[nums[i]]++;
           }
	}
        
        
        for (auto it = f.begin(); it!=f.end(); it++){
            int ele=it->first;
            int freq=it->second;
		maxheap.push({freq,ele});
            
	    }
        
        while(k--){
            custom_node c_max=maxheap.top();
            int curr_max=c_max.second;
            result.push_back(curr_max);
            maxheap.pop();
        }
        return result;
    }
};
