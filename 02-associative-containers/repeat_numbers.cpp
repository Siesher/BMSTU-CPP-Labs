#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

int main(){
    std::map<std::string, int> Nums;

    std::vector<int> nums;

    std::string line;

    std::getline(std::cin, line);

    std::istringstream iss(line);

    int num;
    while(iss >> num){
        nums.push_back(num);
    }

    for(size_t i = 0; i != nums.size(); ++i){
        if(Nums[std::to_string(nums[i])] == 1){
            std::cout << "YES" <<std::endl;
        }else{
            std::cout << "NO" << std::endl;
            ++Nums[std::to_string(nums[i])];
        }
        }
    }