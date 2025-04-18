class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string prev = countAndSay(n - 1);
        string result = "";
        int i = 0;
        while(i<prev.size()){
            int cnt=1;
            while (i + 1 < prev.length() && prev[i] == prev[i + 1]) {
            i++;
            cnt++;
        }
        result += to_string(cnt) + prev[i];
        i++;
        }
        return result;

    }
};