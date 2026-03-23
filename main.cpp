// Question 1 - Factorial 
#include <iostream>
using namespace std;

long long getFact(int x) {
    if (x <= 1) return 1;
    return x * getFact(x - 1);
}

int main() {
    int number;
    cin >> number;
    cout << getFact(number) << endl;
    return 0;
}

// Question 2 - Fibonacci 
#include <iostream>
using namespace std;

int fib(int pos) {
    if (pos <= 0) return 0;
    if (pos == 1) return 1;
    return fib(pos - 1) + fib(pos - 2);
}

int main() {
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        cout << fib(i) << " ";
    }
    cout << endl;
    return 0;
}

// Question 3 - Sum of Digits 
#include <iostream>
using namespace std;

int digitSum(int n) {
    if (n == 0) return 0;
    return n % 10 + digitSum(n / 10);
}

int main() {
    int input;
    cin >> input;
    cout << digitSum(input) << endl;
    return 0;
}

// Question 4 - Power  
#include <iostream>
using namespace std;

long long calculatePower(int x, int y) {
    if (y == 0) return 1;
    return x * calculatePower(x, y - 1);
}

int main() {
    int base, exponent;
    cin >> base >> exponent;
    cout << calculatePower(base, exponent) << endl;
    return 0;
}

// Question 5 - GCD  
#include <iostream>
using namespace std;

int gcd(int m, int n) {
    if (n == 0) return m;
    return gcd(n, m % n);
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    cout << gcd(num1, num2) << endl;
    return 0;
}

// Q1 - Largest element in array  
#include <iostream>
using namespace std;

int getLargest(int a[], int len) {
    int largest = a[0];
    for (int i = 1; i < len; i++) {
        if (a[i] > largest) largest = a[i];
    }
    return largest;
}

int main() {
    int size;
    cin >> size;
    int numbers[100];
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }
    cout << getLargest(numbers, size) << endl;
    return 0;
}

// Q2 - Insert element in array  
#include <iostream>
using namespace std;

void addAtPosition(int a[], int& len, int index, int num) {
    for (int i = len; i > index; i--) {
        a[i] = a[i - 1];
    }
    a[index] = num;
    len++;
}

int main() {
    int count, idx, value;
    cin >> count;
    int data[101];
    for (int i = 0; i < count; i++) {
        cin >> data[i];
    }
    cin >> idx >> value;
    addAtPosition(data, count, idx, value);
    for (int i = 0; i < count; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}
// Q3 - Delete element from array  
#include <iostream>
using namespace std;

void removeAt(int a[], int& len, int idx) {
    for (int i = idx; i < len - 1; i++) {
        a[i] = a[i + 1];
    }
    len--;
}

int main() {
    int size, position;
    cin >> size;
    int nums[100];
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    cin >> position;
    removeAt(nums, size, position);
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
// Q4 - Bubble Sort  
#include <iostream>
using namespace std;

void sortBubble(int a[], int len) {
    for (int pass = 0; pass < len - 1; pass++) {
        for (int i = 0; i < len - pass - 1; i++) {
            if (a[i] > a[i + 1]) {
                int swap = a[i];
                a[i] = a[i + 1];
                a[i + 1] = swap;
            }
        }
    }
}

int main() {
    int size;
    cin >> size;
    int numbers[100];
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }
    sortBubble(numbers, size);
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    return 0;
}

// Q5 - Linear Search 
#include <iostream>
using namespace std;

int searchLinear(int a[], int len, int value) {
    for (int i = 0; i < len; i++) {
        if (a[i] == value) return i;
    }
    return -1;
}

int main() {
    int count, searchKey;
    cin >> count;
    int data[100];
    for (int i = 0; i < count; i++) {
        cin >> data[i];
    }
    cin >> searchKey;
    cout << searchLinear(data, count, searchKey) << endl;
    return 0;
}

// Implement Stack using Array - Push, Pop, Display  
#include <iostream>
using namespace std;

const int SIZE = 100;

void insert(int stk[], int& tos, int num) {
    if (tos >= SIZE - 1) {
        cout << "Overflow!" << endl;
        return;
    }
    stk[++tos] = num;
}

void remove(int stk[], int& tos) {
    if (tos == -1) {
        cout << "Underflow!" << endl;
        return;
    }
    tos--;
}

void show(int stk[], int tos) {
    if (tos == -1) {
        cout << "Empty stack" << endl;
        return;
    }
    for (int i = tos; i >= 0; i--) {
        cout << stk[i] << " ";
    }
    cout << endl;
}

int main() {
    int stk[SIZE];
    int tos = -1;
    int opt, data;

    while (true) {
        cin >> opt;
        if (opt == 1) {
            cin >> data;
            insert(stk, tos, data);
        }
        else if (opt == 2) {
            remove(stk, tos);
        }
        else if (opt == 3) {
            show(stk, tos);
        }
        else {
            break;
        }
    }
    return 0;
}

// Implement Stack using Linked List  
#include <iostream>
using namespace std;

struct StackNode {
    int val;
    StackNode* link;
};

void add(StackNode*& head, int num) {
    StackNode* temp = new StackNode();
    temp->val = num;
    temp->link = head;
    head = temp;
}

void del(StackNode*& head) {
    if (head == nullptr) {
        cout << "Underflow" << endl;
        return;
    }
    StackNode* ptr = head;
    head = head->link;
    delete ptr;
}

void print(StackNode* head) {
    if (head == nullptr) {
        cout << "Empty" << endl;
        return;
    }
    StackNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->link;
    }
    cout << endl;
}

int main() {
    StackNode* head = nullptr;
    int ch, x;

    while (true) {
        cin >> ch;
        if (ch == 1) {
            cin >> x;
            add(head, x);
        }
        else if (ch == 2) {
            del(head);
        }
        else if (ch == 3) {
            print(head);
        }
        else {
            break;
        }
    }

    while (head != nullptr) {
        StackNode* t = head;
        head = head->link;
        delete t;
    }
    return 0;
}

// Implement Queue using Array - Enqueue, Dequeue  
#include <iostream>
using namespace std;

const int SIZE = 100;

void addRear(int q[], int& r, int& f, int num) {
    if (r == SIZE - 1) {
        cout << "Overflow" << endl;
        return;
    }
    if (f == -1) f = 0;
    q[++r] = num;
}

void removeFront(int q[], int& f, int& r) {
    if (f == -1 || f > r) {
        cout << "Underflow" << endl;
        return;
    }
    f++;
    if (f > r) {
        f = -1;
        r = -1;
    }
}

void showQueue(int q[], int f, int r) {
    if (f == -1) {
        cout << "Empty queue" << endl;
        return;
    }
    for (int i = f; i <= r; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
}

int main() {
    int q[SIZE];
    int front = -1, rear = -1;
    int opt, val;

    while (true) {
        cin >> opt;
        if (opt == 1) {
            cin >> val;
            addRear(q, rear, front, val);
        }
        else if (opt == 2) {
            removeFront(q, front, rear);
        }
        else if (opt == 3) {
            showQueue(q, front, rear);
        }
        else {
            break;
        }
    }
    return 0;
}

// Implement Circular Queue using Array  
#include <iostream>
using namespace std;

const int CAP = 100;

void addToCircular(int q[], int& r, int& f, int x) {
    if ((r + 1) % CAP == f) {
        cout << "Full" << endl;
        return;
    }
    if (f == -1) f = 0;
    r = (r + 1) % CAP;
    q[r] = x;
}

void removeFromCircular(int q[], int& f, int& r) {
    if (f == -1) {
        cout << "Empty" << endl;
        return;
    }
    if (f == r) {
        f = -1;
        r = -1;
    } else {
        f = (f + 1) % CAP;
    }
}

void printCircular(int q[], int f, int r) {
    if (f == -1) {
        cout << "Empty circular queue" << endl;
        return;
    }
    int i = f;
    do {
        cout << q[i] << " ";
        if (i == r) break;
        i = (i + 1) % CAP;
    } while (true);
    cout << endl;
}

int main() {
    int q[CAP];
    int front = -1, rear = -1;
    int ch, val;

    while (true) {
        cin >> ch;
        if (ch == 1) {
            cin >> val;
            addToCircular(q, rear, front, val);
        }
        else if (ch == 2) {
            removeFromCircular(q, front, rear);
        }
        else if (ch == 3) {
            printCircular(q, front, rear);
        }
        else {
            break;
        }
    }
    return 0;
}

// Implement Queue using Linked List  
#include <iostream>
using namespace std;

struct QNode {
    int val;
    QNode* link;
};

void addRearLL(QNode*& head, QNode*& tail, int num) {
    QNode* temp = new QNode();
    temp->val = num;
    temp->link = nullptr;

    if (tail == nullptr) {
        head = tail = temp;
    } else {
        tail->link = temp;
        tail = temp;
    }
}

void removeFrontLL(QNode*& head, QNode*& tail) {
    if (head == nullptr) {
        cout << "Underflow" << endl;
        return;
    }
    QNode* ptr = head;
    head = head->link;
    if (head == nullptr) tail = nullptr;
    delete ptr;
}

void printLL(QNode* head) {
    if (head == nullptr) {
        cout << "Empty queue" << endl;
        return;
    }
    QNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->link;
    }
    cout << endl;
}

int main() {
    QNode* front = nullptr;
    QNode* rear = nullptr;
    int opt, x;

    while (true) {
        cin >> opt;
        if (opt == 1) {
            cin >> x;
            addRearLL(front, rear, x);
        }
        else if (opt == 2) {
            removeFrontLL(front, rear);
        }
        else if (opt == 3) {
            printLL(front);
        }
        else {
            break;
        }
    }

    while (front != nullptr) {
        QNode* t = front;
        front = front->link;
        delete t;
    }
    return 0;
}

// Singly Linked List - Create, Insert Beginning, Insert End, Delete  
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

void addFront(ListNode*& start, int num) {
    ListNode* node = new ListNode();
    node->val = num;
    node->next = start;
    start = node;
}

void addLast(ListNode*& start, int num) {
    ListNode* node = new ListNode();
    node->val = num;
    node->next = nullptr;

    if (start == nullptr) {
        start = node;
        return;
    }

    ListNode* ptr = start;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = node;
}

void removeNode(ListNode*& start, int target) {
    if (start == nullptr) return;

    if (start->val == target) {
        ListNode* temp = start;
        start = start->next;
        delete temp;
        return;
    }

    ListNode* curr = start;
    while (curr->next != nullptr && curr->next->val != target) {
        curr = curr->next;
    }

    if (curr->next == nullptr) return;

    ListNode* temp = curr->next;
    curr->next = temp->next;
    delete temp;
}

void printList(ListNode* start) {
    ListNode* ptr = start;
    while (ptr != nullptr) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    ListNode* start = nullptr;
    int opt, x;

    while (true) {
        cin >> opt;
        if (opt == 1) {
            cin >> x;
            addFront(start, x);
        }
        else if (opt == 2) {
            cin >> x;
            addLast(start, x);
        }
        else if (opt == 3) {
            cin >> x;
            removeNode(start, x);
        }
        else if (opt == 4) {
            printList(start);
        }
        else {
            break;
        }
    }

    while (start != nullptr) {
        ListNode* temp = start;
        start = start->next;
        delete temp;
    }
    return 0;
}

// Binary Tree - Creation, Traversals, Node Count  
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode();
    node->val = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printPostorder(TreeNode* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

int getNodeCount(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + getNodeCount(root->left) + getNodeCount(root->right);
}

int main() {
    // Sample tree (you can change or accept user input)
    TreeNode* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
    root->right->right = newNode(60);

    cout << "Preorder Traversal  : ";
    printPreorder(root);
    cout << endl;

    cout << "Inorder Traversal   : ";
    printInorder(root);
    cout << endl;

    cout << "Postorder Traversal : ";
    printPostorder(root);
    cout << endl;

    cout << "Number of nodes     : " << getNodeCount(root) << endl;

    return 0;
}

// Binary Search Tree - Insert, Search, Delete  
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode();
    node->val = val;
    node->left = node->right = nullptr;
    return node;
}

TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) {
        return newNode(key);
    }
    if (key < root->val) {
        root->left = insert(root->left, key);
    } else if (key > root->val) {
        root->right = insert(root->right, key);
    }
    return root;
}

bool find(TreeNode* root, int key) {
    if (root == nullptr) return false;
    if (root->val == key) return true;
    return (key < root->val) 
           ? find(root->left, key) 
           : find(root->right, key);
}

TreeNode* getMinValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

TreeNode* remove(TreeNode* root, int key) {
    if (root == nullptr) return root;

    if (key < root->val) {
        root->left = remove(root->left, key);
    }
    else if (key > root->val) {
        root->right = remove(root->right, key);
    }
    else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = getMinValueNode(root->right);
        root->val = temp->val;
        root->right = remove(root->right, temp->val);
    }
    return root;
}

void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    TreeNode* root = nullptr;
    int opt, x;

    while (true) {
        cin >> opt;
        if (opt == 1) {         // Insert
            cin >> x;
            root = insert(root, x);
        }
        else if (opt == 2) {    // Search
            cin >> x;
            cout << (find(root, x) ? "Yes" : "No") << endl;
        }
        else if (opt == 3) {    // Delete
            cin >> x;
            root = remove(root, x);
        }
        else if (opt == 4) {    // Inorder traversal
            printInorder(root);
            cout << endl;
        }
        else {
            break;
        }
    }

    return 0;
}

// Min Heap Implementation + Heap Sort  
#include <iostream>
#include <vector>
using namespace std;

void minHeapify(vector<int>& heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

void buildMinHeap(vector<int>& heap) {
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(heap, n, i);
    }
}

void insertMinHeap(vector<int>& heap, int val) {
    heap.push_back(val);
    int idx = heap.size() - 1;
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent] > heap[idx]) {
            swap(heap[parent], heap[idx]);
            idx = parent;
        } else {
            break;
        }
    }
}

void heapSortMin(vector<int>& arr) {
    buildMinHeap(arr);
    int n = arr.size();
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

void display(const vector<int>& v) {
    for (int num : v) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> heap;
    int opt, num, size;

    while (true) {
        cin >> opt;
        if (opt == 1) {             // Insert into Min Heap
            cin >> num;
            insertMinHeap(heap, num);
        }
        else if (opt == 2) {        // Show current min heap
            display(heap);
        }
        else if (opt == 3) {        // Heap Sort using Min Heap
            heapSortMin(heap);
            display(heap);
        }
        else {
            break;
        }
    }
    return 0;
}

// Graph using Adjacency Matrix + DFS + BFS  
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class GraphAdjMatrix {
private:
    int numVertices;
    int** matrix;

public:
    GraphAdjMatrix(int n) {
        numVertices = n;
        matrix = new int*[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[n];
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    ~GraphAdjMatrix() {
        for (int i = 0; i < numVertices; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void connect(int from, int to) {
        matrix[from][to] = 1;
        matrix[to][from] = 1;  // undirected
    }

    void depthFirst(int startVertex) {
        vector<bool> seen(numVertices, false);
        cout << "DFS: ";
        stack<int> stk;
        stk.push(startVertex);
        seen[startVertex] = true;

        while (!stk.empty()) {
            int curr = stk.top();
            stk.pop();
            cout << curr << " ";

            for (int next = numVertices - 1; next >= 0; next--) {
                if (matrix[curr][next] && !seen[next]) {
                    seen[next] = true;
                    stk.push(next);
                }
            }
        }
        cout << endl;
    }

    void breadthFirst(int start) {
        vector<bool> visited(numVertices, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        cout << "BFS: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int i = 0; i < numVertices; i++) {
                if (matrix[node][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    void showGraph() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << matrix[i][j] << "  ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, m, a, b, src;
    cin >> n;
    GraphAdjMatrix graph(n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph.connect(a, b);
    }

    cin >> src;
    graph.depthFirst(src);

    cin >> src;
    graph.breadthFirst(src);

    graph.showGraph();

    return 0;
}
