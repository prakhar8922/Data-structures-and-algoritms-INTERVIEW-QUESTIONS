// Design and implement a data structure for a Least Frequently Used (LFU) cache.

// Implement the LFUCache class:

// LFUCache(int capacity) Initializes the object with the capacity of the data structure.
// int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
// void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
// To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

// When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

// The functions get and put must each run in O(1) average time complexity.

// Example 1:

// Input
// ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, 3, null, -1, 3, 4]

// Explanation
// // cnt(x) = the use counter for key x
// // cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
// LFUCache lfu = new LFUCache(2);
// lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
// lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
// lfu.get(1);      // return 1
//                  // cache=[1,2], cnt(2)=1, cnt(1)=2
// lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
//                  // cache=[3,1], cnt(3)=1, cnt(1)=2
// lfu.get(2);      // return -1 (not found)
// lfu.get(3);      // return 3
//                  // cache=[3,1], cnt(3)=2, cnt(1)=2
// lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
//                  // cache=[4,3], cnt(4)=1, cnt(3)=2
// lfu.get(1);      // return -1 (not found)
// lfu.get(3);      // return 3
//                  // cache=[3,4], cnt(4)=1, cnt(3)=3
// lfu.get(4);      // return 4
//                  // cache=[4,3], cnt(4)=2, cnt(3)=3

// Constraints:

// 0 <= capacity <= 104
// 0 <= key <= 105
// 0 <= value <= 109
// At most 2 * 105 calls will be made to get and put.

class LFUCache
{
    int maxsize;
    int size;
    int minfreq;
    unordered_map<int, pair<int, int>> keynode;      // key to {value,freq}
    unordered_map<int, list<int>::iterator> keylist; // it maps a key (integer) to its position (list iterator) in a frequency list stored in another unordered map freqkeylt.
    unordered_map<int, list<int>> freqkeylt;         // maps a frequency (integer) to a list of keys that have been accessed with that frequency.

public:
    LFUCache(int capacity)
    {
        maxsize = capacity;
        size = 0;
    }

    int get(int key)
    {
        if (keynode.count(key) == 0)
            return -1;
        freqkeylt[keynode[key].second].erase(keylist[key]); // this line of code is removing the key from its current frequency list in the unordered_map "freqkeylt" before updating its frequency.
        keynode[key].second++;
        freqkeylt[keynode[key].second].push_back(key);         // updates the frequency of the key in the cache and moves it to the corresponding frequency list.
        keylist[key] = --freqkeylt[keynode[key].second].end(); // This line of code maps the key to the iterator of the last element of the list stored at the frequency value of the key in the freqkeylt map
        if (freqkeylt[minfreq].size() == 0)
            minfreq++;
        return keynode[key].first;
    }

    void put(int key, int value)
    {
        if (maxsize <= 0)
            return;
        int storedval = get(key);
        if (storedval != -1)
        {
            keynode[key].first = value;
            return;
        }
        if (size >= maxsize)
        {
            keynode.erase(freqkeylt[minfreq].front());
            keylist.erase(freqkeylt[minfreq].front());
            freqkeylt[minfreq].pop_front();
            size--;
        }

        // add the new key to the cache
        keynode[key] = {value, 1};
        freqkeylt[1].push_back(key);
        keylist[key] = --freqkeylt[1].end();
        minfreq = 1;
        size++;
    }
};
