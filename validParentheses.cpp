#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    map<char,char> brackets{
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
    vector<char> bufferBrackets{};

    for(unsigned int i{0}; i < s.size(); i++) {
        if(brackets[s[i]]) {
            if(bufferBrackets.size() != 0 && bufferBrackets.back() == brackets[s[i]]) bufferBrackets.pop_back();
            else return false;
        } 
        else bufferBrackets.push_back(s[i]);
    }

    return bufferBrackets.empty();
  }
};

int main() {
    Solution so{};
    cout << so.isValid("()");

    return 0;
}