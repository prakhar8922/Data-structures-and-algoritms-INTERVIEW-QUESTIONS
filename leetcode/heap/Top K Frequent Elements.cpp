// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.

// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        for (auto it : nums)
        {
            mp[it]++;
        }
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        while (k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<vector<int>>eleFreq(nums.size()+1);// This vector will act as a bucket where elements will be grouped based on their frequencies.
        vector<int>ans;
        for(auto&it:nums){
            mp[it]++;
        }
        for(auto&it:mp){// Add the element it.first to the bucket eleFreq at index it.second. By doing this, elements with the same frequency are grouped together.
            eleFreq[it.second].push_back(it.first);
        }
        for(int i=nums.size();i>=0;i--){
            for(auto&num:eleFreq[i]){//Within each frequency bucket, iterate over each element num. This ensures that elements with higher frequencies are considered first.
                ans.push_back(num);
                k--;
                if(k==0)return ans;
            }
        }
        return {};
    }
};