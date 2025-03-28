class Solution {
public:
   vector<string> fizzBuzz(int n) {
    vector<string> answer(n);

    for (int i = 1; i <= n; i++) {
        string result = "";

        if (i % 3 == 0) result += "Fizz";
        if (i % 5 == 0) result += "Buzz";
        if (result.empty()) result = to_string(i);

        answer[i - 1] = result;
    }

    return answer;
}
};