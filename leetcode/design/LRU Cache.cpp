// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

// Constraints:

// 1 <= capacity <= 3000
// 0 <= key <= 104
// 0 <= value <= 105
// At most 2 * 105 calls will be made to get and put.

class LRUCache
{
public:
    class node
    {
    public:
        int key, val;
        node *prev, *next;
        node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };
    unordered_map<int, node *> mp;
    int capacity;
    // two dummy nodes to keep track starting and ending point of list
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    // function to insert a node in the next to head [in front of our list or in front of dummy head node]
    void insert(node *currnode)
    {
        currnode->next = head->next;
        head->next->prev = currnode;
        head->next = currnode;
        currnode->prev = head;
        mp[currnode->key] = currnode;
    }
    // function to remove a node
    void remove(node *currnode)
    {
        mp.erase(currnode->key);
        currnode->next->prev = currnode->prev;
        currnode->prev->next = currnode->next;
    }

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        // if key is present , than update the node and return the value associated with the key
        //  for update first we remove the node and then add at start of list with the help of insert function
        if (mp.find(key) != mp.end())
        {
            node *currnode = mp[key]; // map assigns the location where that particular key was present in dll
            remove(currnode);
            insert(currnode);
            return currnode->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // if key is already present than we have to update it
        // similiary we first remove and then add node in front with the help of insert helper
        if (mp.find(key) != mp.end())
        {
            remove(mp[key]);
        }
        if (mp.size() == capacity)
        { // if size is full then we have to remove the least recently used node
            remove(tail->prev);
        }
        insert(new node(key, value));
    }
};
