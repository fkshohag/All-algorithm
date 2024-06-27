# include <bits/stdc++.h>
using namespace std;

// Tree strcuture
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Compare {
    bool operator() (const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
    }
};


// Node class for linkList
struct Node {
	int data;
	Node* nextPtr;

	Node() : data(0), nextPtr(nullptr) {}
	Node(int x) : data(x), nextPtr(nullptr) {} 
	Node(int x , Node* ptr) : data(x), nextPtr(ptr) {}
};


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (!intervals.size()) return 0;
        // sort 2D array based on index
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] < v2[0];
        });
        return 1;
    }
};


int main() {

    // vector 
    vector<int> dp(100, 2); // set 2 for all the value
    vector<int> v(100, 2); // set 2 for all the value
    sort(dp.begin(), dp.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    reverse(v.begin(), v.end());

    cout << *max_element(v.begin(), v.end()) << endl;
    cout << *min_element(v.begin(), v.end()) << endl;
    cout << accumulate(v.begin(), v.end(), 0);

    cout << dp[0];
    vector <vector<int>> graph(100, vector<int>());
    graph[0].push_back(3);

    cout << graph[0][0];
    // cout << dp[0];

    vector<pair<int, int>> edge;

    edge.push_back({2, 3});
    cout << edge[0].first;

    // unordered map
    unordered_map<string, int> mp;
    mp.insert({"shohag", 2});
    cout << mp["shohag"];

    for (auto i : mp) {
        cout << " " << i.first << " ";
    }

    unordered_set<int> s;
    s.insert(1);
    s.insert(4);

    for (auto i : s) {
        cout << i << " ";
    }

    // priority queue (max heap)
    priority_queue<int> pq;
    pq.push(4);
    pq.push(10);
    // min heap
    priority_queue<int, vector<int>, greater<int>> pqmin;
    priority_queue<vector<int>, vector<vector<int>>, Compare> pqminCustom;
    pqmin.push(3);
    pqmin.push(1);
    cout << pqmin.top();
    cout <<endl << pq.top();

    // stack
    stack<int> st;
    st.push(3);
    st.push(5);
    cout << st.top();

    // type conversation
    string x = "3534534";
    int y = stoi(x);
    cout << endl << y;
    string ss = to_string(y);
    cout <<endl << ss;
}