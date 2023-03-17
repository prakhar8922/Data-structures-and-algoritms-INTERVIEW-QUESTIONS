# 2582. Pass the Pillow
# Easy
# 132
# 4
# Companies
# There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

# For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.
# Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.


# Example 1:

# Input: n = 4, time = 5
# Output: 2
# Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
# Afer five seconds, the pillow is given to the 2nd person.
# Example 2:

# Input: n = 3, time = 2
# Output: 3
# Explanation: People pass the pillow in the following way: 1 -> 2 -> 3.
# Afer two seconds, the pillow is given to the 3rd person.


# Constraints:

# 2 <= n <= 1000
# 1 <= time <= 1000

class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        rounds = time//(n-1)
        hops = time % (n-1)
        ans = 0
        if rounds % 2 == 0:
            ans = 1+hops
        else:
            ans = n-hops
        return ans

# class Solution {
# public:
#     int passThePillow(int n, int time) {
#       int ans=0;
#       int rounds=time/(n-1);//each round involves n-1 passes of the pillow (since one person will always have the pillow at the start of each round).
#       int hops=time%(n-1);//the remaining time may not be enough to complete a full round, so we need to calculate how many passes can be made in the remaining time.
#       if(rounds%2==0){//pillow will be with the person who started the round plus the remaining hops
#           ans=1+hops;
#       }
#       else ans=n-hops;
#       return ans;
#     }

# };
