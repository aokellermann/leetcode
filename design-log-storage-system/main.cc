#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class LogSystem {
private:
    multimap<long, int> m;
    unordered_set<int> s;

    unordered_map<string, long> g{
            {"Second", 0},
            {"Minute", 100},
            {"Hour",   10000},
            {"Day",    1000000},
            {"Month",  100000000},
            {"Year",   10000000000},
    };


    static long getTimestamp(const string &timestamp) {
        long place = 1;
        long ts = 0;
        for (auto it = timestamp.rbegin(); it != timestamp.rend(); ++it) {
            const auto& c = *it;
            if (c == ':') continue;
            ts += (c - '0') * place;
            place *= 10;
        }
        return ts;
    }

public:
    LogSystem() {

    }

    void put(int id, const string &timestamp) {
        if (s.emplace(id).second) {
            m.emplace(getTimestamp(timestamp), id);
        }
    }

    vector<int> retrieve(const string &start, const string &end, const string &granularity) {
        auto start_ts = getTimestamp(start);
        auto end_ts = getTimestamp(end);

        auto g_mod = g[granularity];
        if (g_mod != 0) {
            start_ts -= start_ts % g_mod;
            end_ts -= end_ts % g_mod;
            end_ts += g_mod - 1;
        }

        auto first = m.lower_bound(start_ts);
        auto last = m.upper_bound(end_ts);

        vector<int> v;
        for (auto it = first; it != last; ++it) {
            v.emplace_back(it->second);
        }

        return v;
    }
};
