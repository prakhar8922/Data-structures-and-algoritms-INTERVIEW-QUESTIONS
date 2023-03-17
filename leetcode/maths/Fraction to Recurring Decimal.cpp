// 166. Fraction to Recurring Decimal
// Medium
// 1.9K
// 3.4K
// Companies
// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// If multiple answers are possible, return any of them.

// It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

// Example 1:

// Input: numerator = 1, denominator = 2
// Output: "0.5"
// Example 2:

// Input: numerator = 2, denominator = 1
// Output: "2"
// Example 3:

// Input: numerator = 4, denominator = 333
// Output: "0.(012)"

// Constraints:

// -231 <= numerator, denominator <= 231 - 1
// denominator != 0

class Solution
{
public:
    string fractionToDecimal(int num, int den)
    {
        if (num == 0)
            return "0"; // special case of numerator being zero

        string ans;
        if ((num < 0 and den > 0) or (num > 0 and den < 0)) // handle sign of the result
            ans.push_back('-');
        num = abs(num);
        den = abs(den); // convert both numerator and denominator to positive

        long long rem = num % den;
        long long quotient = num / den;
        ans += to_string(quotient); // add the quotient to the answer string

        if (rem == 0) // check if there is no remainder, which means the fraction is already a terminating decimal
            return ans;

        ans += '.';                 // add the decimal point for non-terminating decimals
        unordered_map<int, int> mp; // create a hash table to keep track of remainders

        while (rem)
        {
            if (mp.find(rem) != mp.end())
            {                         // if the current remainder has been seen before, we have a repeating decimal
                int pos = mp[rem];    // get the position in the string where the repeating block starts
                ans.insert(pos, "("); // insert an opening bracket at that position
                ans += ')';           // add a closing bracket at the end
                break;
            }
            else
            {
                mp[rem] = ans.size();       // add the current remainder to the hash table with its position in the string
                rem *= 10;                  // multiply the remainder by 10 for the next step
                quotient = rem / den;       // compute the next quotient
                rem = rem % den;            // compute the next remainder
                ans += to_string(quotient); // add the next quotient to the string
            }
        }

        return ans;
    }
};

// class Solution:
//     def fractionToDecimal(self, numerator: int, denominator: int) -> str:
//         # Handle edge cases
//         if numerator == 0:
//             return "0"
//         if denominator == 0:
//             return ""

//         # Initialize result and check for negative sign
//         result = ""
//         if (numerator < 0) ^ (denominator < 0):
//             result += "-"
//         numerator, denominator = abs(numerator), abs(denominator)

//         # Integer part of the result
//         result += str(numerator // denominator)

//         # Check if there is a fractional part
//         if numerator % denominator == 0:
//             return result

//         result += "."

//         # Use a dictionary to store the position of each remainder
//         remainder_dict = {}
//         remainder = numerator % denominator

//         # Keep adding the remainder to the result until it repeats or the remainder becomes 0
//         while remainder != 0 and remainder not in remainder_dict:
//             remainder_dict[remainder] = len(result)
//             remainder *= 10
//             result += str(remainder // denominator)
//             remainder %= denominator

//         # Check if there is a repeating part
//         if remainder in remainder_dict:
//             result = result[:remainder_dict[remainder]] + "(" + result[remainder_dict[remainder]:] + ")"

//         return result
