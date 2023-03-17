// 28. Find the Index of the First Occurrence in a String
// Medium
// 2K
// 122
// Companies
// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.

// Constraints:

// 1 <= haystack.length, needle.length <= 104
// haystack and needle consist of only lowercase English characters.

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size(), k = needle.size(); // n is the size of haystack, k is the size of needle
        if (k == 0)
            return 0; // if needle is empty, return 0
        for (int i = 0; i <= n - k; i++)
        { // loop through haystack
            int j = 0;
            while (j < k && haystack[i + j] == needle[j])
            { // check each character in needle with haystack
                j++;
            }
            if (j == k)
                return i; // if all characters in needle are found in haystack, return the starting index
        }
        return -1; // if needle is not found in haystack, return -1
    }
};