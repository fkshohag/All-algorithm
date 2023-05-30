# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/design-hashset/description/
 * Time complexity O(1)
 * Memory complexity O(1e6 + 1)
*/


class MyHashSet {
private:
    vector<int> bucket;
public:
    MyHashSet() {
        bucket.resize(1e6 + 1, 0);
    }
    
    void add(int key) {
        this->bucket[key] = 1;
    }
    
    void remove(int key) {
        this->bucket[key] = 0;
    }
    
    bool contains(int key) {
        return this->bucket[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */