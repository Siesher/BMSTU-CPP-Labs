#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> paths;

    string path_1;

    while(std::cin >> path_1){
        paths.push_back(path_1);
        }
    set<string> directories;
    size_t pos_0 = 0;
    for(const string& path : paths) {

        directories.insert(path.substr(pos_0, 1));
        
        size_t pos = 0;
        while ((pos = path.find('/', pos + 1)) != string::npos) {
            directories.insert(path.substr(0, pos + 1));
        }
    }

    for (const string& dir : directories) {
        cout << dir << endl;
    }

    return 0;
}
