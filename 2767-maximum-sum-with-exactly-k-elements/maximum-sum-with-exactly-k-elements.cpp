class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int n:nums){
            pq.push(n);
        }
        int score=0;
        while(k>0){
            int ele=pq.top();
            pq.pop();
            score+=ele;
            pq.push(ele+1);
            k--;
        }
        return score;
    }
};