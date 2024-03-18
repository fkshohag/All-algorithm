/*
Task Description
interval_map<K,V> is a data structure that efficiently associates intervals of keys of type K with values of type V. Your task is to implement the assign member function of this data structure, which is outlined below.
interval_map<K, V> is implemented on top of std::map. In case you are not entirely sure which functions std::map provides, what they do and which guarantees they provide, we provide an excerpt of the C++ standard here: 
Each key-value-pair (k,v) in the std::map means that the value v is associated with the interval from k (including) to the next key (excluding) in the std::map.
Example: the std::map (0,'A'), (3,'B'), (5,'A') represents the mapping
0 -> 'A'
1 -> 'A'
2 -> 'A'
3 -> 'B'
4 -> 'B'
5 -> 'A'
6 -> 'A'
7 -> 'A'
... all the way to numeric_limits<int>::max()
The representation in the std::map must be canonical, that is, consecutive map entries must not have the same value: ..., (0,'A'), (3,'A'), ... is not allowed. Initially, the whole range of K is associated with a given initial value, passed to the constructor of the interval_map<K,V> data structure.
Key type K
besides being copyable and assignable, is less-than comparable via operator<
is bounded below, with the lowest value being std::numeric_limits<K>::lowest()
does not implement any other operations, in particular no equality comparison or arithmetic operators
Value type V
besides being copyable and assignable, is equality-comparable via operator==
does not implement any other operations
*/

#include <map>
#include <limits>
#include <ctime>

template<typename K, typename V>
class interval_map {
	std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        m_map.insert(m_map.end(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val ) {

			if (!(keyBegin < keyEnd)) return;

			std::pair<K,V> beginExtra;
			std::pair<K,V> endExtra;
			bool beginHasExtra = false;
			bool endHasExtra = false;

			typename std::map<K,V>::const_iterator itBegin;
			itBegin = m_map.lower_bound(keyBegin);
			if ( itBegin!=m_map.end() && keyBegin < itBegin->first ) {
				if (itBegin != m_map.begin()) {
					beginHasExtra = true;
					--itBegin;
					beginExtra = std::make_pair(itBegin->first, itBegin->second);
				}
				// openRange for erase is prevIterator
				// insert (prevIterator->first, prevIterator->second) as well!
			}

			typename std::map<K,V>::const_iterator itEnd;
			itEnd = m_map.lower_bound(keyEnd);
			if ( itEnd!=m_map.end() && keyEnd < itEnd->first ) {
				endHasExtra = true;
				typename std::map<K,V>::const_iterator extraIt = itEnd;
				--extraIt;
				endExtra = std::make_pair(keyEnd, extraIt->second);
				// closeRange for erase is this iterator
				// insert (keyEnd, prevIterator->second) as well!
			}

			// 4 canonical conflicts:
			//	 beginExtra w/ mid
			//	 before-mid w/ mid (beginHasExtra==false)
			//	 mid w/ endExtra
			//	 mid w/ after-mid (endHasExtra==false)

			bool insertMid = true;
			if (beginHasExtra) {
				if (beginExtra.second == val)
					insertMid = false;
			} else {
				if (itBegin != m_map.begin()) {
					typename std::map<K,V>::const_iterator beforeMid = itBegin;
					--beforeMid;
					if (beforeMid->second == val)
						insertMid = false;
				}
			}


			if (endHasExtra) {
				if ( (insertMid && endExtra.second == val) || (!insertMid && endExtra.second == beginExtra.second) )
					endHasExtra = false;
			} else {
				if ( (insertMid && itEnd!=m_map.end() && itEnd->second == val) || (!insertMid && itEnd!=m_map.end() && itEnd->second == beginExtra.second) )
					itEnd = m_map.erase(itEnd);
			}

			itBegin = m_map.erase(itBegin, itEnd);
			if (beginHasExtra)
				itBegin = m_map.insert(itBegin, beginExtra);
			if (insertMid)
				itBegin = m_map.insert(itBegin, std::make_pair(keyBegin, val));
			if (endHasExtra)
									m_map.insert(itBegin, endExtra);

// INSERT YOUR SOLUTION HERE
    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }
};