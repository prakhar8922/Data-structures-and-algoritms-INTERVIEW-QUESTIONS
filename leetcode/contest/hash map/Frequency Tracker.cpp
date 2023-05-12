// 2671. Frequency Tracker
// Medium
// 152
// 13
// Companies
// Design a data structure that keeps track of the values in it and answers some queries regarding their frequencies.

// Implement the FrequencyTracker class.

// FrequencyTracker(): Initializes the FrequencyTracker object with an empty array initially.
// void add(int number): Adds number to the data structure.
// void deleteOne(int number): Deletes one occurence of number from the data structure. The data structure may not contain number, and in this case nothing is deleted.
// bool hasFrequency(int frequency): Returns true if there is a number in the data structure that occurs frequency number of times, otherwise, it returns false.

// Example 1:

// Input
// ["FrequencyTracker", "add", "add", "hasFrequency"]
// [[], [3], [3], [2]]
// Output
// [null, null, null, true]

// Explanation
// FrequencyTracker frequencyTracker = new FrequencyTracker();
// frequencyTracker.add(3); // The data structure now contains [3]
// frequencyTracker.add(3); // The data structure now contains [3, 3]
// frequencyTracker.hasFrequency(2); // Returns true, because 3 occurs twice

// Example 2:

// Input
// ["FrequencyTracker", "add", "deleteOne", "hasFrequency"]
// [[], [1], [1], [1]]
// Output
// [null, null, null, false]

// Explanation
// FrequencyTracker frequencyTracker = new FrequencyTracker();
// frequencyTracker.add(1); // The data structure now contains [1]
// frequencyTracker.deleteOne(1); // The data structure becomes empty []
// frequencyTracker.hasFrequency(1); // Returns false, because the data structure is empty

// Example 3:

// Input
// ["FrequencyTracker", "hasFrequency", "add", "hasFrequency"]
// [[], [2], [3], [1]]
// Output
// [null, false, null, true]

// Explanation
// FrequencyTracker frequencyTracker = new FrequencyTracker();
// frequencyTracker.hasFrequency(2); // Returns false, because the data structure is empty
// frequencyTracker.add(3); // The data structure now contains [3]
// frequencyTracker.hasFrequency(1); // Returns true, because 3 occurs once

// Constraints:

// 1 <= number <= 105
// 1 <= frequency <= 105
// At most, 2 * 105 calls will be made to add, deleteOne, and hasFrequency in total.
// Accepted
// 11.4K
// Submissions
// 42.9K
// Acceptance Rate
// 26.6%

class FrequencyTracker
{
public:
    unordered_map<int, int> mp, mp2; // here mp stores the freq of each element and mp2 stores the number of unique elements with given frequency(mp2[3]=5 denotes there are 5unique elements with freq 5 )
    FrequencyTracker()
    {
    }

    void add(int number)
    {
        // check if the number already exists in the map
        if (mp.find(number) != mp.end())
        {
            // if the number exists, decrement its current frequency in the frequency map
            mp2[mp[number]]--;
        }
        // increment the frequency of the number in the number map
        mp[number]++;
        // increment the frequency of the new frequency of the number in the frequency map
        mp2[mp[number]]++;
    }

    void deleteOne(int number)
    {
        // check if the number exists in the map and its frequency is greater than zero
        if (mp.find(number) != mp.end() && mp[number] > 0)
        {
            // decrement the frequency of the number's current frequency in the frequency map
            mp2[mp[number]]--;
            // decrement the frequency of the number in the number map
            mp[number]--;
            // increment the frequency of the new frequency of the number in the frequency map
            mp2[mp[number]]++;
        }
    }

    bool hasFrequency(int frequency)
    {
        // check if the given frequency exists in the frequency map
        return (mp2[frequency] > 0);
    }
};