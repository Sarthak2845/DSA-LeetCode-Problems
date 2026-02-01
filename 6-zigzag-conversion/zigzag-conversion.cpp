class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.size()) return s;
        int currRow=0;
        vector<string>output(numRows);
        bool goingDown=false;
        for(char c:s){
            output[currRow].push_back(c);
            if(currRow==0 || currRow==numRows-1){
                goingDown=!goingDown;
            }
            currRow+= goingDown? 1 : -1; 
        }
        string result;
        for (string &row : output)
            result += row;

        return result;
    }
};