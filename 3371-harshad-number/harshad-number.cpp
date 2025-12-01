class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int res=0;
        int original = x;
        while(x!=0){
            int digi=x%10;
            res+=digi;
            x=x/10;
        }
        if(original%res==0) return res;
        return -1;
    }
};