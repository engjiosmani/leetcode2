#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

// Singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Valid parentheses
//Time complexity: O(n)
//Space complexity: O(n)
class stack1 {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (st.empty() && (c == ')' || c == ']' || c == '}')) {
                return false;
            }
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else {
                char left = st.top();
                if ((c == ')' && left != '(') || (c == ']' && left != '[') || (c == '}' && left != '{')) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

// Remove outermost parentheses
//Time complexity: O(n)
//Space complexity: O(n)
class stack2 {
public:
    string removeOuterParentheses(string S) {
        string res;
        int opened = 0;
        for (int i = 0; i < S.size(); ++i) {
            char c = S[i];
            if (c == '(' && opened++ > 0) res += c;
            if (c == ')' && opened-- > 1) res += c;
        }
        return res;
    }
};

// Maximum nesting depth of the parentheses
//Time complexity: O(n)
//Space complexity: O(1)
class stack3 {
public:
    int maxDepth(string s) {
        int depth = 0;
        int max = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') {
                depth++;
                if (max < depth)
                    max = depth;
            }
            else if (c == ')') {
                depth--;
            }
        }
        return max;
    }
};

// Number of students unable to eat lunch
//Time complexity: O(n)
//Space complexity: O(1)
class queue1 {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int student_count = students.size(), circular_st = 0, square_st = 0;
        for (int i = 0; i < students.size(); i++) {
            if (students[i] == 0) {
                circular_st++;
            }
            else {
                square_st++;
            }
        }
        for (int i = 0; i < sandwiches.size(); i++) {
            if (sandwiches[i] == 0) {
                if (circular_st > 0) {
                    student_count--;
                    circular_st--;
                }
                else {
                    return student_count;
                }
            }
            else {
                if (square_st > 0) {
                    student_count--;
                    square_st--;
                }
                else {
                    return student_count;
                }
            }
        }
        return student_count;
    }
};

// Number of recent calls
//Time complexity: O(n)
//Space complexity: O(n)
class queue2 {
public:
    queue<int> q;
    int ping(int t) {
        while (!q.empty() && t - q.front() > 3000) {
            q.pop();
        }
        q.push(t);
        return q.size();
    }
};

// Merge two sorted lists
//Time complexity: O(n)
//Space complexity: O(1)
class linkedlist1 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr || list2 == nullptr) return list1 != nullptr ? list1 : list2;
        ListNode head = 0;
        ListNode* cur = &head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            }
            else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 != nullptr ? list1 : list2;
        return head.next;
    }
};

// Remove duplicates from sorted list
//Time complexity: O(n)
//Space complexity: O(1)
class linkedlist2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* pre = head, * cur = head->next;
        while (cur) {
            pre->val == cur->val ? pre->next = cur->next : pre = cur;
            cur = cur->next;
        }
        return head;
    }
};

// Reverse linked list
//Time complexity: O(n)
//Space complexity: O(1)
class linkedlist3 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr, * cur = head, * next;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

// Middle of the linked list
//Time complexity: O(n)
//Space complexity: O(1)
class linkedlist4 {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        if (head == nullptr) {
            return nullptr;
        }
        else {
            while (p2 != nullptr && p2->next != nullptr) {
                p2 = p2->next->next;
                p1 = p1->next;
            }
            return p1;
        }
    }
};

// Intersection of two linked lists
//Time complexity: O(m+n)
//Space complexity: O(1)
class linkedlist5 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        if (p1 == nullptr || p2 == nullptr) {
            return nullptr;
        }
        while (p1 != nullptr && p2 != nullptr && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == p2) {
                return p1;
            }
            if (p1 == nullptr) {
                p1 = headB;
            }
            if (p2 == nullptr) {
                p2 = headA;
            }
        }
        return p1;
    }
};

// Rrange sum of BST
//Time complexity: O(n)
//Space complexity: O(log n)-O(n) it depends on the structure of the BST
class binarysearchtree1 {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        int current;
        if (root->val >= low && root->val <= high) {
            current = root->val;
        }
        else {
            current = 0;
        }

        int leftSum = rangeSumBST(root->left, low, high);
        int rightSum = rangeSumBST(root->right, low, high);

        return current + leftSum + rightSum;
    }
};

// Search in a binary search tree
//Time complexity: O(log n)
//Space complexity: O(1)
class binarysearchtree2 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr && root->val != val) {
            if (root->val > val) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        return root;
    }
};

// Minimum distance between BST nodes
//Time complexity: O(n)
//Space complexity: O(h)
class binarysearchtree3 {
public:
    int res = INT_MAX, prev = -1;
    int minDiffInBST(TreeNode* root) {
        if (root->left != nullptr) {
            minDiffInBST(root->left);
        }
        if (prev >= 0) {
            res = min(res, root->val - prev);
        }
        prev = root->val;
        if (root->right != nullptr) {
            minDiffInBST(root->right);
        }
        return res;
    }
};

// Two sum IV-input is a BST
//Time complexity: O(n)
//Space complexity: O(n)
class binarysearchtree4 {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        for (int i = 0, j = nums.size() - 1; i < j;) {
            if (nums[i] + nums[j] == k)return true;
            (nums[i] + nums[j] < k) ? i++ : j--;
        }
        return false;
    }
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
};

// Minimum absolute difference in BST
//Time complexity: O(n)
//Space complexity: O(log n)-O(n) it depends on the height of the BST
class binarysearchtree5 {
public:
    int min_dif = INT_MAX, val = -1;
    int getMinimumDifference(TreeNode* root) {
        if (root->left != nullptr)
            getMinimumDifference(root->left);
        if (val >= 0)
            min_dif = min(min_dif, root->val - val);
        val = root->val;
        if (root->right != nullptr)
            getMinimumDifference(root->right);
        return min_dif;
    }
};

// How many numbers are smaller than the current number
//Time complexity: O(nlogn)
//Space complexity: O(n)
class hashtable1 {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res = nums;
        unordered_map<int, int> m;
        sort(res.begin(), res.end());
        for (int i = nums.size() - 1; i >= 0; i--)
            m[res[i]] = i;
        for (int i = 0; i < nums.size(); i++)
            nums[i] = m[nums[i]];
        return nums;
    }
};

// Decode the message
//Time complexity: O(K+M)
//Space complexity: O(K+M)
class hashtable2 {
public:
    string decodeMessage(string key, string message) {
        string alphabet, res;
        unordered_map<char, char>map;
        for (char i = 'a'; i <= 'z'; i++) {
            alphabet.push_back(i);
        }
        int j = 0;
        for (int i = 0; i < key.length(); i++) {
            if (key[i] == ' ')
                continue;
            if (map.find(key[i]) == map.end()) {
                map[key[i]] = alphabet[j];
                j++;
            }
        }
        for (int i = 0; i < message.length(); i++) {
            if (message[i] == ' ')
                res.push_back(' ');
            else
                res.push_back(map[message[i]]);
        }
        return res;
    }
};

// Permutation difference between two strings
//Time complexity: O(n+m)
//Space complexity: O(c)
class hashtable3 {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> m;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]] = i;
        }
        for (int i = 0; i < t.size(); i++) {
            res += abs(i - m[t[i]]);
        }
        return res;
    }
};

// Count number of pairs with absolute difference K
//Time complexity: O(n)
//Space complexity: O(n)
class hashtable4 {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> pairs;
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            res += pairs[n + k] + pairs[n - k];
            pairs[n]++;
        }
        return res;
    }
};

// Number of arithmetic triplets
//Time complexity: O(n)
//Space complexity: O(n)
class hashtable5 {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        unordered_map<int, bool> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = true;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i] - diff] && m[nums[i] + diff])
                count++;
        }
        return count;
    }
};

void displayMenu() {
    cout << "Choose an option:" << endl;
    cout << "1. Valid parentheses" << endl;
    cout << "2. Remove outermost parentheses" << endl;
    cout << "3. Maximum nesting depth of the parentheses" << endl;
    cout << "4. Number of students unable to eat lunch" << endl;
    cout << "5. Number of recent calls" << endl;
    cout << "6. Merge two sorted lists" << endl;
    cout << "7. Remove duplicates from sorted list" << endl;
    cout << "8. Reverse linked list" << endl;
    cout << "9. Middle of the linked list" << endl;
    cout << "10. Intersection of two linked lists" << endl;
    cout << "11. Range sum of BST" << endl;
    cout << "12. Search in a binary search tree" << endl;
    cout << "13. Minimum Distance Between BST Nodes" << endl;
    cout << "14. Two sum IV-input is a BST" << endl;
    cout << "15. Minimum absolute difference in BST" << endl;
    cout << "16. How many numbers are smaller than the current number" << endl;
    cout << "17. Decode the message" << endl;
    cout << "18. Permutation difference between two strings" << endl;
    cout << "19. Count number of pairs with absolute difference K" << endl;
    cout << "20. Number of Arithmetic triplets" << endl;
    cout << "Enter your choice (1-20): ";
}

int main() {
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        switch (choice) {
        case 1: {
            stack1 s1;
            string s;
            cout << "Enter a string: ";
            cin >> s;
            cout << "Valid parentheses: " << (s1.isValid(s) ? "true" : "false") << endl;
            break;
        }
        case 2: {
            stack2 s2;
            string s;
            cout << "Enter a string: ";
            cin >> s;
            cout << "Outer parentheses removed: " << s2.removeOuterParentheses(s) << endl;
            break;
        }
        case 3: {
            stack3 s3;
            string s;
            cout << "Enter a string: ";
            cin >> s;
            cout << "Maximum nesting depth: " << s3.maxDepth(s) << endl;
            break;
        }
        case 4: {
            queue1 q1;
            vector<int> students, sandwiches;
            int n, m;
            cout << "Enter the number of students: ";
            cin >> n;
            cout << "Enter the students' preferences (0 for circular and 1 for square sandwiches): ";
            for (int i = 0; i < n; ++i) {
                int student;
                cin >> student;
                students.push_back(student);
            }
            cout << "Enter the number of sandwiches: ";
            cin >> m;
            cout << "Enter the type of sandwiches (0 for circular and 1 for square sandwiches): ";
            for (int i = 0; i < m; ++i) {
                int sandwich;
                cin >> sandwich;
                sandwiches.push_back(sandwich);
            }
            cout << "Number of students unable to eat lunch: " << q1.countStudents(students, sandwiches) << endl;
            break;
        }
        case 5: {
            queue2 q2;
            vector<int> times;
            int t;
            cout << "Enter the number of times: ";
            cin >> t;
            cout << "Enter the times: ";
            for (int i = 0; i < t; ++i) {
                int time;
                cin >> time;
                cout << "Number of recent calls: " << q2.ping(time) << endl;
            }
            break;
        }
        case 6: {
            linkedlist1 l1;
            ListNode* list1 = nullptr;
            ListNode* list2 = nullptr;
            cout << "Enter elements for the first list (space-separated, -1 to stop): ";
            int val;
            while (true) {
                cin >> val;
                if (val == -1) break;
                ListNode* newNode = new ListNode(val);
                if (list1 == nullptr) {
                    list1 = newNode;
                }
                else {
                    ListNode* temp = list1;
                    while (temp->next != nullptr) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
            }

            cout << "Enter elements for the second list (space-separated, -1 to stop): ";
            while (true) {
                cin >> val;
                if (val == -1) break;
                ListNode* newNode = new ListNode(val);
                if (list2 == nullptr) {
                    list2 = newNode;
                }
                else {
                    ListNode* temp = list2;
                    while (temp->next != nullptr) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
            }
            ListNode* mergedList = l1.mergeTwoLists(list1, list2);
            cout << "Merged list: ";
            while (mergedList != nullptr) {
                cout << mergedList->val << " ";
                mergedList = mergedList->next;
            }
            cout << endl;
            break;
        }
        case 7: {
            linkedlist2 l2;
            ListNode* head = nullptr;
            cout << "Enter elements for the linked list (space-separated, -1 to stop): ";
            int val;
            while (true) {
                cin >> val;
                if (val == -1) break;
                ListNode* newNode = new ListNode(val);
                if (head == nullptr) {
                    head = newNode;
                }
                else {
                    ListNode* temp = head;
                    while (temp->next != nullptr) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
            }
            ListNode* uniqueList = l2.deleteDuplicates(head);
            cout << "Unique list: ";
            while (uniqueList != nullptr) {
                cout << uniqueList->val << " ";
                uniqueList = uniqueList->next;
            }
            cout << endl;
            break;
        }
        case 8: {
            linkedlist3 l3;
            ListNode* head = nullptr;
            cout << "Enter elements for the linked list (space-separated, -1 to stop): ";
            int val;
            while (true) {
                cin >> val;
                if (val == -1) break;
                ListNode* newNode = new ListNode(val);
                if (head == nullptr) {
                    head = newNode;
                }
                else {
                    ListNode* temp = head;
                    while (temp->next != nullptr) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
            }
            ListNode* reversedList = l3.reverseList(head);
            cout << "Reversed list: ";
            while (reversedList != nullptr) {
                cout << reversedList->val << " ";
                reversedList = reversedList->next;
            }
            cout << endl;
            break;
        }
        case 9: {
            linkedlist4 l4;
            ListNode* head = nullptr;
            cout << "Enter elements for the linked list (space-separated, -1 to stop): ";
            int val;
            while (true) {
                cin >> val;
                if (val == -1) break;
                ListNode* newNode = new ListNode(val);
                if (head == nullptr) {
                    head = newNode;
                }
                else {
                    ListNode* temp = head;
                    while (temp->next != nullptr) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
            }
            ListNode* middleNode = l4.middleNode(head);
            if (middleNode != nullptr) {
                cout << "Middle node value: " << middleNode->val << endl;
            }
            else {
                cout << "Middle node not found." << endl;
            }
            break;
        }
        case 10: {
            linkedlist5 l5;
            ListNode* headA = nullptr;
            ListNode* headB = nullptr;
            cout << "Enter elements for the first linked list (space-separated, -1 to stop): ";
            int val;
            while (true) {
                cin >> val;
                if (val == -1) break;
                ListNode* newNode = new ListNode(val);
                if (headA == nullptr) {
                    headA = newNode;
                }
                else {
                    ListNode* temp = headA;
                    while (temp->next != nullptr) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
            }

            cout << "Enter elements for the second linked list (space-separated, -1 to stop): ";
            while (true) {
                cin >> val;
                if (val == -1) break;
                ListNode* newNode = new ListNode(val);
                if (headB == nullptr) {
                    headB = newNode;
                }
                else {
                    ListNode* temp = headB;
                    while (temp->next != nullptr) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
            }
            ListNode* intersectionNode = l5.getIntersectionNode(headA, headB);
            if (intersectionNode != nullptr) {
                cout << "Intersection node value: " << intersectionNode->val << endl;
            }
            else {
                cout << "No intersection node found." << endl;
            }

            break;
        }
        case 11: {
            binarysearchtree1 b1;
            TreeNode* root = nullptr;
            int low, high;
    
            cout << "Enter the range: ";
            cin >> low >> high;
            cout << "Sum of values in the range: " << b1.rangeSumBST(root, low, high) << endl;
            break;
        }
        case 12: {
            binarysearchtree2 b2;
            TreeNode* root = nullptr;
            int val;
            cout << "Enter the root value of the BST: ";
            int rootValue;
            cin >> rootValue;
            root = new TreeNode(rootValue);
            cout << "Enter the value to search for: ";
            cin >> val;
            TreeNode* node = b2.searchBST(root, val);
            if (node != nullptr) {
                cout << "Node found with value: " << node->val << endl;
            }
            else {
                cout << "Node not found." << endl;
            }
            break;
        }
        case 13: {
            binarysearchtree3 b3;
            TreeNode* root = nullptr;
            cout << "Enter the root value of the BST: ";
            int rootValue;
            cin >> rootValue;
            root = new TreeNode(rootValue);
            cout << "Minimum distance between nodes: " << b3.minDiffInBST(root) << endl;
            break;
        }
        case 14: {
            binarysearchtree4 b4;
            TreeNode* root = nullptr;
            int k;
            cout << "Enter the root value of the BST: ";
            int rootValue;
            cin >> rootValue;
            root = new TreeNode(rootValue);
            cout << "Enter the value of k: ";
            cin >> k;
            cout << (b4.findTarget(root, k) ? "True" : "False") << endl;
            break;
        }
        case 15: {
            binarysearchtree5 b5;
            TreeNode* root = nullptr;
            cout << "Enter the root value of the BST: ";
            int rootValue;
            cin >> rootValue;
            root = new TreeNode(rootValue);
            cout << "Minimum absolute difference: " << b5.getMinimumDifference(root) << endl;
            break;
        }
        case 16: {
            hashtable1 h1;
            vector<int> nums;
            int n;
            cout << "Enter the size of the array: ";
            cin >> n;
            cout << "Enter the elements of the array: ";
            for (int i = 0; i < n; ++i) {
                int num;
                cin >> num;
                nums.push_back(num);
            }
            vector<int> result = h1.smallerNumbersThanCurrent(nums);
            cout << "Result: ";
            for (int num : result) {
                cout << num << " ";
            }
            cout << endl;
            break;
        }
        case 17: {
            hashtable2 h2;
            string key, message;
            cout << "Enter the key: ";
            cin >> key;
            cout << "Enter the message: ";
            cin >> message;
            cout << "Decoded message: " << h2.decodeMessage(key, message) << endl;
            break;
        }
        case 18: {
            hashtable3 h3;
            string s, t;
            cout << "Enter the first string: ";
            cin >> s;
            cout << "Enter the second string: ";
            cin >> t;
            cout << "Permutation difference: " << h3.findPermutationDifference(s, t) << endl;
            break;
        }
        case 19: {
            hashtable4 h4;
            vector<int> nums;
            int n, k;
            cout << "Enter the size of the array: ";
            cin >> n;
            cout << "Enter the elements of the array: ";
            for (int i = 0; i < n; ++i) {
                int num;
                cin >> num;
                nums.push_back(num);
            }
            cout << "Enter the value of k: ";
            cin >> k;
            cout << "Number of pairs with absolute difference " << k << ": " << h4.countKDifference(nums, k) << endl;
            break;
        }
        case 20: {
            hashtable5 h5;
            vector<int> nums;
            int n, diff;
            cout << "Enter the size of the array: ";
            cin >> n;
            cout << "Enter the elements of the array: ";
            for (int i = 0; i < n; ++i) {
                int num;
                cin >> num;
                nums.push_back(num);
            }
            cout << "Enter the difference: ";
            cin >> diff;
            cout << "Number of arithmetic triplets: " << h5.arithmeticTriplets(nums, diff) << endl;
            break;
        }
        default:
            cout << "Invalid choice! Please enter a number between 1 and 20." << endl;
            break;
        }
        char cont;
        cout << "Do you want to continue (y/n)? ";
        cin >> cont;
        if (cont != 'y' && cont != 'Y') break;
    }
    return 0;
}
