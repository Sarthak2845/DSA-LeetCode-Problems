class Solution {
public:
    int removePattern(string& s,string pattern,int score){
        stack<char>st;
        int res=0;
        for(char ch:s){
            if(!st.empty() && st.top()==pattern[0] && ch == pattern[1]){
                st.pop();
                res+=score;
            }
            else{
                st.push(ch);
            }
        }
        string rem = "";
        while (!st.empty()) {
            rem += st.top();
            st.pop();
        }
        reverse(rem.begin(), rem.end());
        s = rem;  
        return res;
    }
    int maximumGain(string s, int x, int y) {
        int total=0;
        if(x>y){
            total+=removePattern(s, "ab",x);
            total+=removePattern(s, "ba",y);
        }
        else{
            total+=removePattern(s,"ba",y);
            total+=removePattern(s,"ab",x);
        }
        return total;
    }
};