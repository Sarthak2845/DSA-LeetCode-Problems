class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        set<char>st={'a','e','i','o','u'};
        int cnt=0;
        for(int i=left;i<=right;i++){
            string&word=words[i];
            if(!word.empty() && st.count(word.front()) && st.count(word.back())){
                cnt++;
            }
        }
        return cnt;
    }
};