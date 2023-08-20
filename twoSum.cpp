#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int size{nums.size()};
        std::vector<int> result;

        for(int i{0}; i<size; i++) {
            if(nums[i] + nums[i+1] == target) {
                result[0] = i;
                result[1] = i+1;
            }
        }

        return result;
    }
};

int main() {
    std::vector<int> myarr{2, 7, 11, 15};
    Solution so;
    std::vector<int> res = so.twoSum(myarr, 9);

    for (int i : res) {
        std::cout << i << ' ';
    }
    return 0;
}