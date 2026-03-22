#include <string>
#include <map>
#include <iostream>
#include <vector>

class Solution {
    public:
    std::map<int, std::string> book(int num, const std::vector<std::string>& pages){
        std::map<int, std::string> result;
        for(int i = 0; i != num; ++i){
            int ptr_0 = pages[i].size();
            while(pages[i][ptr_0] != ' '){
                --ptr_0;
            }
            int n {std::stoi(pages[i].substr(ptr_0, pages[i].size()))};
            if(result[n].find(pages[i].substr(0, ptr_0)) != std::string::npos){
                continue;
            }else{
            result[n] += pages[i].substr(0, ptr_0) + ' ';
            }
        }
        for(auto& page : result){
            page.second.pop_back();
        }
        return result;
    }
};

int main(){

    Solution s;

    size_t num;

    std::cin >> num;

    std::vector<std::string> pages;

    std::string page;

    std::getline(std::cin, page);

    while(std::getline(std::cin, page)){
        pages.push_back(page);
        if(pages.size() == num){
            break;
        }
    }
    auto result = s.book(5, pages);
    for(auto& p : result){
        std::cout << p.first << " " << p.second << std::endl;
    }
    return 0;
}