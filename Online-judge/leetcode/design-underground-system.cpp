# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/design-underground-system/description/
 * Time complexity O(1)
 * Memory complexity O(p+s^2)
*/

class UndergroundSystem {
    // id -> checkIn station, inTime
    unordered_map<int, pair<string, int>> checkInStation;
    // route -> total time, count 
    unordered_map<string, pair<int, int>> jounery;

public:
    UndergroundSystem() {

    }
    
    void checkIn(int id, string stationName, int t) {
        checkInStation[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto cIn = checkInStation[id];
        checkInStation.erase(id);
        string route = cIn.first + "_" + stationName;
        jounery[route].first += t - cIn.second;
        jounery[route].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation;
        auto travel = jounery[route];
        return (double) travel.first / travel.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */