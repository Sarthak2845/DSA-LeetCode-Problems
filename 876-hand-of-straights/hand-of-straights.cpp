class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> freq;
        for (int card : hand) freq[card]++;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto& [card, count] : freq) {
            minHeap.push(card);
        }

        while (!minHeap.empty()) {
            int start = minHeap.top();

            for (int i = 0; i < groupSize; i++) {
                int curr = start + i;
                if (freq[curr] == 0) return false; // missing number
                freq[curr]--;
                if (freq[curr] == 0) {
                    if (curr != minHeap.top()) return false; 
                    minHeap.pop();
                }
            }
        }
        return true;
    }
};
