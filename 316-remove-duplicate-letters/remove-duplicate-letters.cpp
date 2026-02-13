class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> visited(26, 0);
        vector<int> lastIndex(26);

        for (int i = 0; i < s.size(); i++)
            lastIndex[s[i] - 'a'] = i;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (visited[c - 'a'])
                continue;

            while (!st.empty() &&
                   st.top() > c &&
                   lastIndex[st.top() - 'a'] > i) {
                
                char topChar = st.top();
                st.pop();
                visited[topChar - 'a'] = 0;
            }

            st.push(c);
            visited[c - 'a'] = 1;
        }

        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
