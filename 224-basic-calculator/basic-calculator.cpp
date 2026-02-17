class Solution {
public:
    int calculate(string s) {
        long long res = 0;
        long long num = 0;
        long long sign = 1;
        stack<long long> st;

        for(char c : s) {
            if(isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if(c == '+') {
                res += sign * num;
                num = 0;
                sign = 1;
            }
            else if(c == '-') {
                res += sign * num;
                num = 0;
                sign = -1;
            }
            else if(c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            else if(c == ')') {
                res += sign * num;
                num = 0;

                long long prevSign = st.top(); st.pop();
                long long prevRes  = st.top(); st.pop();

                res *= prevSign;
                res += prevRes;
            }
        }

        res += sign * num;
        return (int)res;
    }
};
