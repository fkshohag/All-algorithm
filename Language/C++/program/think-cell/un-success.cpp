#include <iostream>
#include <map>
#include <limits>

template <typename K, typename V>
class interval_map {
public:
    explicit interval_map(V const &val) : m_valBegin(val) {}

    void assign(K const &keyBegin, K const &keyEnd, V const &val) {
        if (keyEnd <= keyBegin)
            return;

        auto iteratorBegin = m_map.lower_bound(keyBegin);
        auto iteratorEnd = m_map.lower_bound(keyEnd);

        if (iteratorBegin != m_map.begin()) {
            auto iteratorPrev = iteratorBegin;
            --iteratorPrev;

            if (iteratorPrev->second == val)
                iteratorBegin = iteratorPrev;
        }

        if (iteratorEnd != m_map.end() && iteratorEnd->second == val) {
            ++iteratorEnd;
        }

        // Preserve the current key-value pair at keyEnd
        if (keyEnd != std::numeric_limits<K>::max()) {
            V prevValue = interval_map<K, V>::operator[](keyEnd);
            if (prevValue != val)
                m_map[keyEnd] = prevValue;
        }

        m_map.erase(iteratorBegin, iteratorEnd);
        m_map[keyBegin] = val;
    }

    V const &operator[](K const &key) const {
        auto iterator = m_map.upper_bound(key);

        if (iterator == m_map.begin())
            return m_valBegin;

        return (--iterator)->second;
    }

private:
    friend void IntervalMapTest();

    V m_valBegin{};
    std::map<K, V> m_map{};
};

void IntervalMapTest() {
    interval_map<int, char> interval('A');

    interval.assign(1, 3, 'B');
    interval.assign(3, 4, 'A');

    std::cout << "Test case 1:" << std::endl;
    for (int i = -2; i <= 5; ++i) {
        std::cout << i << " -> " << interval[i] << std::endl;
    }

    std::cout << "-------" << std::endl;

    interval.assign(-1, 1, 'C');

    std::cout << "Test case 2:" << std::endl;
    for (int i = -2; i <= 5; ++i) {
        std::cout << i << " -> " << interval[i] << std::endl;
    }

    std::cout << "-------" << std::endl;

    interval.assign(0, 2, 'D');
    interval.assign(2, 5, 'E');

    std::cout << "Test case 3:" << std::endl;
    for (int i = -2; i <= 5; ++i) {
        std::cout << i << " -> " << interval[i] << std::endl;
    }
}

int main() {
    IntervalMapTest();
    return 0;
}