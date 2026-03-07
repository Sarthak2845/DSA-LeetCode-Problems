class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for(char c:address){
            if(isdigit(c)){
                res.push_back(c);
            }
            else{
                res+="[.]";
            }
        }
        return res;
    }
};