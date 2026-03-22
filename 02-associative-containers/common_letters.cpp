#include <string>
#include <iostream>
#include <set>
#include <unordered_set>

class Solution{
    public:
    std::set<char> com_let(const std::unordered_set<std::string>& strs){
        std::set<char> common_chars;
        std::set<char> common_chars_1;
        if(strs.empty()){
            return common_chars_1;
        }
        for(const auto& str : strs){
            for(const char& c : str){
                auto[iter, has_been_ins] = common_chars.insert(c);
                if(!has_been_ins){
                    common_chars_1.insert(c);
                }
            }
        }
        for(const auto& str : strs){
            for(auto iter = common_chars_1.begin(); iter != common_chars_1.end();){
                if(str.find(*iter) == std::string::npos){
                    iter = common_chars_1.erase(iter);
                } else {
                    ++iter;
        }
    }
}
        return common_chars_1;
    }
};

int main(){
    Solution sol;
    std::string str;
    std::unordered_set<std::string> strs;

    while(std::getline(std::cin, str)){
        strs.insert(str);
        if(str.empty()){
            break;
        }
    }
    if(strs.size() > 0 && strs.begin()->empty()) {
        strs.erase(strs.begin());
    }

    std::set<char> common_chars = sol.com_let(strs);

    for(const auto& c : common_chars){
        std::cout << c;
    }

    return 0;
}