#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
private:
    using key = int;
    using value = int;
    using usage = int;

    struct kvp {
        key k;
        value v;
    };

    struct bucket {
        usage u;
        list<kvp> kvps;
    };

    list<bucket> buckets;

    struct locator {
        decltype(buckets)::iterator bucket;
        list<kvp>::iterator tb;
    };

    int capacity;
    int size;
    unordered_map<key, locator> m;

    void update(locator loc) {
        auto &[cur_bucket, cur_tb] = loc;
        const auto usage = cur_bucket->u + 1;

        const auto tar_bucket =
                cur_bucket == buckets.begin() || prev(cur_bucket)->u != usage
                ? buckets.insert(cur_bucket, bucket{usage})
                : prev(cur_bucket);

        tar_bucket->kvps.splice(tar_bucket->kvps.begin(), cur_bucket->kvps, cur_tb);

        if (cur_bucket->kvps.empty()) {
            buckets.erase(cur_bucket);
        }

        m[cur_tb->k].bucket = tar_bucket;
    }

    void evict() {
        if (size == capacity) {
            auto &bucket = buckets.back().kvps;
            const auto key = bucket.back().k;
            bucket.pop_back();
            if (bucket.empty()) buckets.pop_back();
            m.erase(key);
            --size;
        }
    }

public:
    LFUCache(int capacity) : capacity(capacity), size(0) {}

    int get(int key) {
        const auto it = m.find(key);
        if (it == m.end()) {
            return -1;
        }

        const auto &loc = it->second;
        update(loc);
        return loc.tb->v;
    }

    void put(int key, int value) {
        const auto it = m.find(key);
        if (it == m.end()) {
            evict();
            buckets.emplace_back(bucket{0, {kvp{key, value}}});
            const auto bucket = prev(buckets.end());
            const auto loc = locator{bucket, prev(bucket->kvps.end())};
            m.emplace(key, loc);
            update(loc);
            size++;
        } else {
            auto &loc = it->second;
            update(loc);
            loc.tb->v = value;
        }
    }
};
