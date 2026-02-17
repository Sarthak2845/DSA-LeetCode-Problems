class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        long long last = 0;
        long long res = 0;
        char op = '+';

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];

            if(isdigit(c))
                num = num * 10 + (c - '0');

            if((!isdigit(c) && c != ' ') || i == s.size() - 1) {

                if(op == '+') {
                    res += last;
                    last = num;
                }
                else if(op == '-') {
                    res += last;
                    last = -num;
                }
                else if(op == '*') {
                    last = last * num;
                }
                else if(op == '/') {
                    last = last / num;
                }

                op = c;
                num = 0;
            }
        }

        res += last;
        return (int)res;
    }
};
