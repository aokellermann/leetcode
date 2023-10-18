#include <string>
#include <vector>
#include <map>
#include <variant>

using namespace std;


class FileSystem {
private:
    struct node {
        bool file;
        string name;
        variant<string, map<string, node>> data;
    };

    node root;

private:
    node &get(const string &path, bool createPaths = false, bool createFile = false) {
        auto* n = &root;
        if (path == "/") return *n;
        size_t i = 0;
        while (i++ != string::npos) {
            auto end = path.find('/', i);
            const auto f = path.substr(i, end - i);
            if (createPaths) {
                n = &std::get<1>(n->data).emplace(f, node{false, f, map<string, node>()}).first->second;
            } else if (createFile && end == string::npos) {
                n = &std::get<1>(n->data).emplace(f, node{true, f, string()}).first->second;
            } else {
                n = &std::get<1>(n->data)[f];
            }
            i = end;
        }
        return *n;
    }

public:
    FileSystem() : root{false, "/", map<string, node>()} {}

    vector<string> ls(const string &path) {
        const auto &n = get(path);

        if (n.file) {
            return {n.name};
        } else {
            const auto &files = std::get<1>(n.data);
            vector<string> v;
            v.reserve(files.size());
            for (const auto &item: files) v.emplace_back(item.first);
            return v;
        }
    }

    void mkdir(const string &path) {
        get(path, true);
    }

    void addContentToFile(const string &filePath, const string &content) {
        auto &n = get(filePath, false, true);
        std::get<0>(n.data).append(content);
    }

    string readContentFromFile(const string &filePath) {
        return std::get<0>(get(filePath).data);
    }
};
