1. Monotonic stack: Find next greater element:

void printNGE(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    for (int i = 1; i < n; i++) {
        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }
        while (s.empty() == false && s.top() < arr[i]) {
            cout << s.top() << " --> " << arr[i] << endl;
            s.pop();
        }
        s.push(arr[i]);
    }
    while (s.empty() == false) {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}
3. Devide and Conquer
    QuickSelect: Find the Kth largest in array unsorted
Way 1: Similar quickSort, implement quickSelect: 
    int partition(int arr[], int l, int r) 
    { 
        int i = l; 
        for (int j = l; j <= r - 1; j++) { 
            if (arr[j] <= arr[r) { 
                swap(arr[i], arr[j]); 
                i++; 
            } 
        } 
        swap(arr[i], arr[r]); 
        return i; 
    } 
        
    int kthSmallest(int arr[], int l, int r, int k) 
    { 
        if (k > 0 && k <= r - l + 1) { 
            int pivot = partition(arr, l, r);  
            if (pivot - l == k - 1) 
                return arr[pivot]; 
            if (pivot - l > k - 1)  
                return kthSmallest(arr, l, pivot - 1, k); 
            return kthSmallest(arr, pivot + 1, r, k - pivot + l - 1); 
        } 
        return INT_MAX; 
    }

Way 2: more efficient
    1. Choose pivot and partition orginal array in to 3 array: left < pivot, mid = pivot, right > pivot
    2.     Check if k <= size of array Right --> call recursive array Right
           Check if k > size of array Right + array Mid --> call recursive array Left
           Check if k == size of array Right + array Mid --> return pivot

4. Advance Tree
n: the number of nodes
depth (level) is the length of this node to root
h: the height of the tree is maximum depth
Full Tree:
    The number of leaf = the number of non leaf + 1
    L = N + 1
Perfect Tree: 
    h = log(n+1)
    n = 2^(h+1) - 1 maximun number of nodes
    2^h leaf nodes
    left = 2i + 1, right = 2i + 2
 -->searching: log(n) time complexity if tree is balance
preOrder, postOrder, inOrder:
--> with BST: all the nodes left is less than this node. All the nodes right is bigger than this node --> using inOrder to find Kth smallest element in BST

7. Trie
Trie (also know as Prefix Tree) is a tree-based data structure to store and retrieve keys from a dataset of strings.
Template for trie:

class TrieNode {
    public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
            isEndOfWord = false;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    int charToIndex(char ch) {
        return ch - 'a';
    }

    void insert(string word) {
        TrieNode* curNode = root;
        for(auto i : word) {
            int idx = charToIndex(i);
            if(curNode->children[idx] == NULL) {
                curNode->children[idx] = new TrieNode();
            }
            curNode = curNode->children[idx];
        }
        curNode->isEndOfWord = true;
    }

    TrieNode* searchIdx(string word) {
        TrieNode* curNode = root;
        for(auto i : word) {
            int idx = charToIndex(i);
            if(curNode->children[idx] == NULL) {
                return NULL;
            }
            curNode = curNode->children[idx];
        }
        return curNode;
    }

    bool search(string word) {
        TrieNode* lastNode = searchIdx(word);
        return lastNode != NULL && lastNode->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* lastNode = searchIdx(prefix);
        return lastNode != NULL;
    }
};
5. Heap
// Custom comparison functor for priority_queue: that compares strings based on length, and in case of equal lengths it will be lexicographical order,
struct CompareStrings {
    bool operator()(const std::string& a, const std::string& b) const {
        if (a.length() == b.length()) {
            return a > b; // If same length, sort lexicographically (using > for min-heap)
        } else {
            return a.length() > b.length(); // Otherwise, sort by length (using > for min-heap)
        }
    }
};

int main() {
    std::priority_queue<std::string, std::vector<std::string>, CompareStrings> pq;
}

// Custom comparison function for sorting strings: To achieve sorting by string length and in case of equal lengths lexicographical order
bool compareStrings(const std::string& a, const std::string& b) {
    if (a.length() == b.length()) {
        return a < b; // If same length, sort lexicographically
    } else {
        return a.length() < b.length(); // Otherwise, sort by length
    }
}
