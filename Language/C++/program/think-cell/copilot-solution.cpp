#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <limits>
#include <iterator>


template <typename K, typename V>
class interval_map {
    std::map<K, V> m_map;

public:
    // Constructor associates the whole range of K with the given initial value.
    interval_map(const V& initial_value) {
        m_map.emplace(std::numeric_limits<K>::lowest(), initial_value);
    }

    // Assign value `val` to the interval [keyBegin, keyEnd).
    void assign(const K& keyBegin, const K& keyEnd, const V& val) {
        if (!(keyBegin < keyEnd))
            return;  // Invalid interval

        auto nextInterval = --m_map.upper_bound(keyEnd);
        auto inserted1 = m_map.end();
        auto inserted2 = m_map.end();

        if (nextInterval->second == val)
            ++nextInterval;
        else if (nextInterval->first < keyEnd) {
            const V& nextValue = nextInterval->second;
            ++nextInterval;
            inserted1 = nextInterval = m_map.emplace_hint(nextInterval, keyEnd, nextValue);
        }

        try {
            auto prevInterval = nextInterval;
            --prevInterval;

            if (keyBegin < prevInterval->first)
                prevInterval = --m_map.upper_bound(keyBegin);

            if (!(prevInterval->second == val)) {
                if (prevInterval->first < keyBegin) {
                    ++prevInterval;
                    inserted2 = prevInterval = m_map.emplace_hint(prevInterval, keyBegin, val);
                } else {
                    auto beforePrev = prevInterval;
                    --beforePrev;

                    if (beforePrev != m_map.end() && beforePrev->second == val)
                        prevInterval = beforePrev;
                    else {
                        auto hint = m_map.erase(prevInterval);
                        inserted2 = prevInterval = m_map.emplace_hint(hint, keyBegin, val);
                    }
                }
            }

            m_map.erase(++prevInterval, nextInterval);
        } catch (...) {
            if (inserted1 != m_map.end())
                m_map.erase(inserted1);
            if (inserted2 != m_map.end())
                m_map.erase(inserted2);
            throw;
        }
    }

    // a print function for debugging
	void show() {
		std::cout << "show" << std::endl;
		for(auto entry : m_map) {
			std::cout << entry.first << entry.second << std::endl;
		}
	}
};

int main(int argc, char* argv[])
{
  // TODO: test interval map with different stl algorithm methods
  // TODO: make 4 spaces tab
  // interval_map<ThinkCellKey<unsigned int>, char> imap {'a'};
  interval_map<unsigned int, char> imap {'A'};

  // imap.assign(3, 5, 'B');
  // imap.assign(5, 7, 'C');
  // imap.assign(2, 7, 'D');


  // imap.assign(8, 10, 'k');

  imap.assign(8, 12, 'k');
  imap.assign(2, 12, 'k');
  imap.assign(2, 12, 'b');
  imap.assign(5, 12, 'b');
  imap.assign(4, 10, 'b');
  imap.assign(4, 12, 'b');
  imap.assign(8, 13, 'a');
  imap.assign(6, 9, 'j');


  // imap.assign(4, 4, 'j'); // its ok 
	// imap.assign(0, 10, 'e');
	// imap.assign(0, 10, 'e');

  // imap.assign(2,6, 'B');
  // imap.assign(3,10, 'C');
  // imap.assign(4, 7, 'B');
  // imap.assign(3, 5, 'B');
  imap.show();
  return 0;
}