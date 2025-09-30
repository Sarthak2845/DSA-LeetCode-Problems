class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);
        for (char& c : tasks) {
            mp[c - 'A']++;
        }

        priority_queue<int> pq;
        for (int freq : mp) {
            if (freq > 0) pq.push(freq);
        }

        int time = 0;
        while (!pq.empty()) {
            int cycle = n + 1; // max slots in one round
            vector<int> temp;

            int tasksExecuted = 0; 
            while (cycle > 0 && !pq.empty()) {
                int freq = pq.top();
                pq.pop();
                freq--;
                if (freq > 0) temp.push_back(freq);
                tasksExecuted++;
                cycle--;
            }

            for (int f : temp) pq.push(f);

            if (pq.empty()) {
                time += tasksExecuted; // no idle needed at the end
            } else {
                time += (n + 1); // full cycle including idles
            }
        }

        return time;
    }
};
