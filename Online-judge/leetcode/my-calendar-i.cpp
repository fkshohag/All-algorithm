# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/my-calendar-i/
 */

class MyCalendar {
private:
    vector<pair<int, int>>events;
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for (auto it: events) {
            if (start < it.second && end > it.first) {
                return false;
            }
        }
        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */