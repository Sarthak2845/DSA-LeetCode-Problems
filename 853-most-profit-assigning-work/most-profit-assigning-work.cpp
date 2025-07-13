class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int l = difficulty.size();
        int n = worker.size();
        

        vector<pair<int, int>> jobs;
        for (int i = 0; i < l; i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        

        sort(jobs.begin(), jobs.end());
        

        sort(worker.begin(), worker.end());

        int i = 0, j = 0;
        int maxProfit = 0;
        int best = 0; 
        int total = 0;


        while (j < n) {

            while (i < l && jobs[i].first <= worker[j]) {
                best = max(best, jobs[i].second); 
                i++;
            }
            total += best; 
            j++;
        }

        return total;
    }
};
