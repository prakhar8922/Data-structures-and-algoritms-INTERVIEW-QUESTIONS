// 341. Flatten Nested List Iterator
// Medium
// 4.2K
// 1.4K
// Companies
// You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.

// Implement the NestedIterator class:

// NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with the nested list nestedList.
// int next() Returns the next integer in the nested list.
// boolean hasNext() Returns true if there are still some integers in the nested list and false otherwise.
// Your code will be tested with the following pseudocode:

// initialize iterator with nestedList
// res = []
// while iterator.hasNext()
//     append iterator.next() to the end of res
// return res
// If res matches the expected flattened list, then your code will be judged as correct.

// Example 1:

// Input: nestedList = [[1,1],2,[1,1]]
// Output: [1,1,2,1,1]
// Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
// Example 2:

// Input: nestedList = [1,[4,[6]]]
// Output: [1,4,6]
// Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].

// Constraints:

// 1 <= nestedList.length <= 500
// The values of the integers in the nested list is in the range [-106, 106].

class NestedIterator
{
public:
    vector<int> res;
    int idx = 0;
    void flatten(vector<NestedInteger> &nestedList)
    {
        for (auto it : nestedList)
        { // iterate over each element of the input list
            if (it.isInteger())
            {                                   // if the element is an integer
                res.push_back(it.getInteger()); // add it to the result vector
            }
            else
            {                          // if the element is a list of NestedInteger objects
                flatten(it.getList()); // recursively call flatten on the nested list
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        flatten(nestedList);
    }

    int next()
    {
        return res[idx++];
    }

    bool hasNext()
    {
        return idx < res.size();
    }
};