class Solution {
public:
    #include <iostream>
#include <string>


int secondsToRemoveOccurrences(string s) {
    int time = 0;
    bool changed = true;

    while (changed) {
        changed = false;
        string temp = s;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0' && s[i + 1] == '1') {

                temp[i] = '1';
                temp[i + 1] = '0';
                i++; 
                changed = true;
            }
        }
        if (changed) {
            time++;
            s = temp;
        }
    }

    return time;
}

};