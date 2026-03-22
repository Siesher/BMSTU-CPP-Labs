#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::pair<std::string, int>> n_grams(std::pair<int, int> p, const std::string& str) {
        std::unordered_map<std::string, int> n_grams;
        size_t n_grams_s = p.second;
        size_t ptr_0 = 0;

        while (ptr_0 + n_grams_s <= str.size()) {
            std::string n_gram = str.substr(ptr_0, n_grams_s);
            if (n_gram.find(' ') == std::string::npos) {
                n_grams[n_gram]++;
            }
            ptr_0++;
        }

        std::vector<std::pair<std::string, int>> sortedByFreq(n_grams.begin(), n_grams.end());
        std::sort(sortedByFreq.begin(), sortedByFreq.end(), [](const auto& p1, const auto& p2) {
    return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first);
});

        return sortedByFreq;
    }
};

int main() {
    Solution sol;
    std::pair<int, int> p;
    std::cin >> p.first >> p.second;

    std::string word, str;
    for (int i = 0; i < p.first; ++i) {
        std::cin >> word;
        str += word;
        if (i < p.first - 1) {
            str += " ";
        }
    }

    auto result = sol.n_grams(p, str);
    for (const auto& p : result) {
        std::cout << p.first << " - " << p.second << std::endl;
    }

    return 0;
}
