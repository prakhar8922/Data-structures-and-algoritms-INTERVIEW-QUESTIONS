// 433. Minimum Genetic Mutation
// Medium
// 2.5K
// 260
// Companies
// A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

// Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

// For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
// There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

// Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

// Note that the starting point is assumed to be valid, so it might not be included in the bank.

// Example 1:

// Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
// Output: 1
// Example 2:

// Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
// Output: 2

// Constraints:

// 0 <= bank.length <= 10
// startGene.length == endGene.length == bank[i].length == 8
// startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].
// Accepted
// 119.1K
// Submissions
// 226.7K
// Acceptance Rate
// 52.5%

class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        queue<string> q;           // Create a queue to perform BFS
        unordered_set<string> vis; // Keep track of visited genes
        q.push(startGene);         // Push the start gene into the queue
        vis.insert(startGene);     // Mark start gene as visited
        int ans = 0;               // Initialize the answer to 0
        while (!q.empty())
        {                      // Continue until the queue is empty
            int sz = q.size(); // Get the current size of the queue (level of BFS)
            for (int i = 0; i < sz; i++)
            {                          // Process all genes at the current level
                auto node = q.front(); // Get the gene at the front of the queue
                q.pop();               // Remove the gene from the queue
                if (node == endGene)   // If the gene is the target gene, return the answer
                    return ans;
                for (auto ch : "ACGT")
                { // Try all possible mutations for each character in the gene
                    for (int j = 0; j < node.size(); j++)
                    {
                        string neighbour = node;
                        neighbour[j] = ch; // Create a mutated neighbour gene

                        // Check if the neighbour gene is in the bank and not visited before
                        if (!vis.count(neighbour) && find(bank.begin(), bank.end(), neighbour) != bank.end())
                        {
                            q.push(neighbour);     // Push the neighbour gene into the queue
                            vis.insert(neighbour); // Mark the neighbour gene as visited
                        }
                    }
                }
            }
            ans++; // Increment the answer as we move to the next level
        }

        return -1; // Return -1 if there is no valid mutation sequence to reach the end gene
    }
};