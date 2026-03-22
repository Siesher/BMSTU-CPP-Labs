#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::map<char, int>> letterCounts;
    std::string word;

    while (std::cin >> word) {
        std::map<char, int> currentWordCount;
        for (char c : word) {
            currentWordCount[c]++;
        }
        letterCounts.push_back(currentWordCount);
    }

    for (char c = 'a'; c <= 'z'; c++) {
        bool isCommon = true;
        for (const auto& counts : letterCounts) {
            if (counts.find(c) == counts.end()) {
                isCommon = false;
                break;
            }
        }
        if (isCommon) {
            std::cout << c;
        }
    }

    return 0;
}
