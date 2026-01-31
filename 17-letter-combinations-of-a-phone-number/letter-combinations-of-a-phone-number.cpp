class Solution {
public:
    void solve(string digits,vector<string>&ans, string map[],int index,string output){
        if(index>=digits.size()){
            ans.push_back(output);
            return;
        }
        int num=digits[index]-'0';
        string val=map[num];
        for(int i=0;i<val.size();i++){
            output.push_back(val[i]);
            solve(digits,ans,map,index+1,output);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0) return ans;
        string output="";
        int index=0;
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,ans,map,index,output);
        return ans;
    }
};