#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(string a, string b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        for (int num : nums) {
            arr.push_back(to_string(num));
        }

        sort(arr.begin(), arr.end(), cmp);

        string result;
        for (string s : arr) {
            result += s;
        }

        if (result[0] == '0') return "0";

        return result;
    }
};