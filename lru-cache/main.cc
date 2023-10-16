#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;

    void update(list<pair<int, int>>::const_iterator it) {
        if (it != l.begin()) {
            l.splice(l.begin(), l, it);
        }
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        const auto it = m.find(key);
        if (it == m.end()) {
            return -1;
        }

        update(it->second);
        return l.front().second;
    }

    void put(int key, int value) {
        const auto it = m.find(key);
        if (it == m.end()) {
            if (m.size() == capacity) {
                m.erase(l.back().first);
                l.pop_back();
            }
            l.emplace_front(key, value);
            m.emplace(key, l.begin());
        } else {
            update(it->second);
            l.front().second = value;
        }
    }
};
