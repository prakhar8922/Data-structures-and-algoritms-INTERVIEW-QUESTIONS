// 84. Largest Rectangle in Histogram
// Hard
// 13.6K
// 193
// Companies
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Example 1:

// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:

// Input: heights = [2,4]
// Output: 4

// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104

class Solution
{
public:
    // we take a stack & keep on adding the indexes in the stack till we get a increasing sequence. Once the sequence becomes decreasing we need to pop the element and find the area
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st; // push the indexes into the stack

        for (int i = 0; i <= n; i++)
        { // The reason why the code considers the case of i=n is to handle the case where all the elements in the given heights array are in increasing order.
            // By including the case of i=n, the loop will process the last element with height 0, which will trigger the while loop to pop all the elements from the stack and compute the area, resulting in the correct answer.
            int currHeight = i == n ? 0 : heights[i];
            // check if currHeight becomes greater then height[top] element of stack. we do a push because it's an increasing sequence
            // otherwise we do pop and find area, so for that we write a while loop
            while (!st.empty() && currHeight < heights[st.top()])
            {
                int top = st.top();
                st.pop(); // current element on which we are working
                // now we need width & area
                int width = st.empty() ? i : i - st.top() - 1; // width differ if we stack is empty or not empty after we pop the element
                int area = heights[top] * width;               // current height * width
                maxArea = max(area, maxArea);
            }
            // if it doesn't enter in while loop, it means it's an increasing sequence & we need to push index
            st.push(i);
        }
        return maxArea;
    }
};

// class Solution:
//     def largestRectangleArea(self, heights: List[int]) -> int:
//         n=len(heights)
//         maxarea=0
//         st=[]
//         for i in range(n+1):
//             currheight=heights[i] if i<n else 0
//             while st and currheight<heights[st[-1]]:
//                 top=st.pop()
//                 width=i if not st else i-st[-1]-1
//                 area=width*heights[top]
//                 maxarea=max(maxarea,area)
//             st.append(i)
//         return maxarea