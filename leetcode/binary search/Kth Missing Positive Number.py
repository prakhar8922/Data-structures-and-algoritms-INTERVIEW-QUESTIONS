# 1539. Kth Missing Positive Number
# Easy
# 4.2K
# 291
# Companies
# Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

# Return the kth positive integer that is missing from this array.


# Example 1:

# Input: arr = [2,3,4,7,11], k = 5
# Output: 9
# Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
# Example 2:

# Input: arr = [1,2,3,4], k = 2
# Output: 6
# Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.


# Constraints:

# 1 <= arr.length <= 1000
# 1 <= arr[i] <= 1000
# 1 <= k <= 1000
# arr[i] < arr[j] for 1 <= i < j <= arr.length


# Follow up:

# Could you solve this problem in less than O(n) complexity?

class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        n = len(arr)
        low, high = 0, n-1
        while low <= high:
            mid = low+(high-low)//2
            if arr[mid]-(mid+1) < k:
                low = mid+1
            else:
                high = mid-1

        return low+k

#     If there were no missing positive values, every index would've contained a value equal to it (Assuming 1 based indexing) as the order is strictly increasing.
#     If this difference of missing positive values is lesser than required number of missing positives, that means our current index value is not big enough to provide us values where we can look for our K'th missing positive. So we must look for a bigger value that may contain our K'th missing positive. So we adjust the left boundary to
# left = mid to look for a bigger difference.

# If the difference is bigger than required number of missing positives that means our current index value can potentially give us an answer, so we narrow down the search space to
# right = mid

# Now when left gets equal to right. We have exhausted missing numbers equal to the index, the remaining missing positives will be given by left + k or right + k.
