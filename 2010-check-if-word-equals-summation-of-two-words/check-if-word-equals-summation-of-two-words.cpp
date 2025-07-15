class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        string st1 = "", st2 = "", st3 = "";
        for (char ch : firstWord)
            st1 += to_string(ch - 'a');
        
        for (char ch : secondWord)
            st2 += to_string(ch - 'a');

        for (char ch : targetWord)
            st3 += to_string(ch - 'a');
        int sum=stoi(st1) + stoi(st2);
        return sum==stoi(st3);
    }
};