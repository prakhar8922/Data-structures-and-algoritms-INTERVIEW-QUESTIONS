// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

// Example 1:

// Input: points = [[1,1],[2,2],[3,3]]
// Output: 3
// Example 2:

// Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4

// Constraints:

// 1 <= points.length <= 300
// points[i].length == 2
// -104 <= xi, yi <= 104
// All the points are unique.

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int maxpoint = 0;
        int n = points.size();
        if (n <= 2)
            return n;
        for (int i = 0; i < n; i++)
        {
            unordered_map<double, int> mp; // a map which will store the frequency of each slope {slope,freq}
            int temp_max = 0;
            // coordinates of first point
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++)
            { // we are taking j=i+1 because we dont want the points to be overlapping
                // coordinates of second point
                int x2 = points[j][0];
                int y2 = points[j][1];
                double num = y2 - y1;
                double den = x2 - x1;
                if (den == 0)
                { // line is perpendicular ,// if denominator will be zero then slope will be INT_MAX
                    mp[INT_MAX]++;
                    temp_max = max(temp_max, mp[INT_MAX]);
                }
                double slope = num / den;
                mp[slope]++;
                temp_max = max(temp_max, mp[slope]);
            }
            maxpoint = max(maxpoint, temp_max + 1); //+1 because we have to consider the point whose relative we are taking the other points
        }
        return maxpoint;
    }
};