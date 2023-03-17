// 443. String Compression
// Medium
// 3.3K
// 5.4K
// Companies
// Given an array of characters chars, compress it using the following algorithm:

// Begin with an empty string s. For each group of consecutive repeating characters in chars:

// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

// After you are done modifying the input array, return the new length of the array.

// You must write an algorithm that uses only constant extra space.

// Example 1:

// Input: chars = ["a","a","b","b","c","c","c"]
// Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
// Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
// Example 2:

// Input: chars = ["a"]
// Output: Return 1, and the first character of the input array should be: ["a"]
// Explanation: The only group is "a", which remains uncompressed since it's a single character.
// Example 3:

// Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
// Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
// Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".

// Constraints:

// 1 <= chars.length <= 2000
// chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int i = 0, j = 0;
        while (j < chars.size())
        { // While j is less than the size of the vector chars
            int cnt = 1;
            while (j < chars.size() - 1 && chars[j] == chars[j + 1])
            { // While j is less than the size of the vector chars minus 1 and the current character is equal to the next character
                j++;
                cnt++;
            }
            chars[i++] = chars[j++]; // Set the current character to the character at index j, and then increment both i and j

            if (cnt > 1)
            { // If the counter is greater than 1
                for (auto &ch : to_string(cnt))
                    chars[i++] = ch; // Convert the counter to a string and add each character of the string to the vector chars, starting at index i
            }
        }
        return i; // Return the final length of the compressed string
    }
};

class Solution:
    def compress(self, chars: List[str]) -> int:
        n=len(chars)
        i=0
        j=0
        while j<n:
            count=1
            while j<n-1 and chars[j]==chars[j+1]:
                count+=1
                j+=1

            chars[i]=chars[j]
            i+=1
            j+=1
            if count>1:
                for c in str(count):
                    chars[i]=c
                    i+=1    

        return i