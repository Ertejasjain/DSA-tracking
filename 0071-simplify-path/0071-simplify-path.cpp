#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string dir;

        // Split the path by '/'
        while (getline(ss, dir, '/')) {
            // Ignore empty parts (from consecutive slashes) and current directory '.'
            if (dir.empty() || dir == ".") {
                continue;
            }
            // Move up to parent directory if possible
            if (dir == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                // Valid directory or file name (including "..." or "....")
                stack.push_back(dir);
            }
        }

        // Reconstruct the canonical path
        string result;
        for (const string& d : stack) {
            result += "/" + d;
        }

        // Return "/" if the stack was empty (e.g., input was "/../" or "/")
        return result.empty() ? "/" : result;
    }
};
