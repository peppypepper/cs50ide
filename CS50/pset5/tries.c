//tries is the better version of hash table. like an upside down tree, every key output is guaranteed to be unique

typedef struct _trie
{
    char university[20];
    struct _strie* paths[10]; //10 pointers at every node, malloc a new node every time you need to start a new branch, reuse branches if already there
}
trie;

// when searching for things. We just need to follow the key, node by node until we find the data. If you reach a dead end before the data, you can say the data does not exist,
// that pointer points to nothing.
// the downside of tries is it's a memory hog. But it's the most efficient data structure we have