class Solution {
public:
    string reverseWords(string s) {
        string word;
        string res;
        for(char ch:s){
            if(isspace(ch)){
                reverse(word.begin(),word.end());
                res+=word;
                res+=ch;
                word.clear();
            }
            else{
            word+=ch;
            }
        }
        reverse(word.begin(),word.end());
        res+=word;
        return res;
    }
};