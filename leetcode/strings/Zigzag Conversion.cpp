// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);

// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
// Example 3:

// Input: s = "A", numRows = 1
// Output: "A"

// Constraints:

// 1 <= s.length <= 1000
// s consists of English letters (lower-case and upper-case), ',' and '.'.
// 1 <= numRows <= 1000

class Solution
{
public:
    string convert(string s, int row)
    {
        if (row == 1)
        {
            return s;
        }
        // create a vector of strings to store each row of the zigzag pattern
        vector<string> nums(row);
        bool down = false;
        // initialize a variable to keep track of the current row
        int j = 0;
        // we keep on adding the character present in the string to the jth row in nums
        // the 0th index will store the 0th row of the zigzag pattern
        for (int i = 0; i < s.size(); i++)
        {
            // add the current character to the current row
            nums[j].push_back(s[i]);
            // if we reach the bottom row, change the direction
            if (j == row - 1)
            {
                down = false;
            }
            // if we reach the top row, change the direction
            else if (j == 0)
            {
                down = true;
            }
            // if the direction is downwards, move to the next row
            if (down == true)
            {
                j++;
            }
            // if the direction is upwards, move to the previous row
            else
                j--;
        }

        string ans = "";
        // concatenate all the rows in the vector to get the final result
        for (auto i : nums)
        {
            ans += i;
        }

        return ans;
    }
};
