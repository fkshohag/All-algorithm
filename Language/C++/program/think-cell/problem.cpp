#include <map>
#include <iostream>

template<typename K, typename V>
class interval_map {
    friend void IntervalMapTest();
    V m_valBegin;
    std::map<K,V> m_map;
public:
    // constructor associates whole range of K with val
    interval_map(V const& val)
    : m_valBegin(val)
    {}

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        if (!(keyBegin < keyEnd)) return;

        auto itBegin = m_map.lower_bound(keyBegin);

        if (itBegin != m_map.begin() && (--itBegin)->second == val) {
            itBegin = m_map.erase(itBegin);
        }


        auto itEnd = m_map.lower_bound(keyEnd);
        if (itEnd != m_map.begin() && (--itEnd)->second == val) {
            ++itEnd;
        }


        m_map.erase(itBegin, itEnd);
        m_map[keyBegin] = val;
        if (m_map.begin()->second == m_valBegin) m_map.erase(m_map.begin());
    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        auto it = m_map.upper_bound(key);
        if(it == m_map.begin()) {
            return m_valBegin;
        } else {
            return (--it)->second;
        }
    }
};

void IntervalMapTest() {
    interval_map<int, char> M('A');
    M.assign(1, 3, 'B');
    M.assign(3, 5, 'A');

    for (int i = -2; i <= 5; ++i) {
        std::cout << i << " -> " << M[i] << std::endl;
    }
}

int main() {
    IntervalMapTest();
    return 0;
}
