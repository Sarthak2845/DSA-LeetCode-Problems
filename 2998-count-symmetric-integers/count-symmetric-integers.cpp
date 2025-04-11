class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            int len=s.length();
            if(len%2!=0) continue;
            int half=len/2;
            int sum1 = 0, sum2 = 0;
            for (int i = 0; i < half; i++) {
            sum1 += s[i] - '0';
        }

        for (int i = half; i < len; i++) {
            sum2 += s[i] - '0';
        }
         if (sum1 == sum2) cnt++;

        }
        return cnt;
    }
};