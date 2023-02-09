// You are given an array of strings ideas that represents a list of names to be used in the process of naming a company. The process of naming a company is as follows:

// Choose 2 distinct names from ideas, call them ideaA and ideaB.
// Swap the first letters of ideaA and ideaB with each other.
// If both of the new names are not found in the original ideas, then the name ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) is a valid company name.
// Otherwise, it is not a valid name.
// Return the number of distinct valid names for the company.

// Example 1:

// Input: ideas = ["coffee","donuts","time","toffee"]
// Output: 6
// Explanation: The following selections are valid:
// - ("coffee", "donuts"): The company name created is "doffee conuts".
// - ("donuts", "coffee"): The company name created is "conuts doffee".
// - ("donuts", "time"): The company name created is "tonuts dime".
// - ("donuts", "toffee"): The company name created is "tonuts doffee".
// - ("time", "donuts"): The company name created is "dime tonuts".
// - ("toffee", "donuts"): The company name created is "doffee tonuts".
// Therefore, there are a total of 6 distinct company names.

// The following are some examples of invalid selections:
// - ("coffee", "time"): The name "toffee" formed after swapping already exists in the original array.
// - ("time", "toffee"): Both names are still the same after swapping and exist in the original array.
// - ("coffee", "toffee"): Both names formed after swapping already exist in the original array.
// Example 2:

// Input: ideas = ["lack","back"]
// Output: 0
// Explanation: There are no valid selections. Therefore, 0 is returned.

// Constraints:

// 2 <= ideas.length <= 5 * 104
// 1 <= ideas[i].length <= 10
// ideas[i] consists of lowercase English letters.
// All the strings in ideas are unique.

class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        long long disName = 0; // variable to store the count of distinct valid names
        // Create a vector of 26 unordered_sets, one for each letter of the alphabet
        vector<unordered_set<string>> arr(26);
        // Loop through the ideas
        for (string s : ideas)
        {
            // Add the idea to the corresponding unordered_set, excluding the first letter
            arr[s[0] - 'a'].insert(s.substr(1));
        }

        // Loop through the first 25 unordered_sets
        for (int i = 0; i < 25; i++)
        {
            // Loop through the remaining unordered_sets
            for (int j = i + 1; j < 26; j++)
            {
                // Create a temporary unordered_set to store the combined elements of the current two unordered_sets
                unordered_set<string> set;
                set.insert(arr[i].begin(), arr[i].end());
                set.insert(arr[j].begin(), arr[j].end());
                // Increment the count of distinct valid names by the number of elements that were added to the temporary set
                // (which are the elements that are unique to the two unordered_sets being combined)
                disName += (arr[i].size() - set.size()) * (arr[j].size() - set.size());
            }
        }
        // Multiply the count by 2 to account for the reverse order of the names
        return disName * 2;
    }
};