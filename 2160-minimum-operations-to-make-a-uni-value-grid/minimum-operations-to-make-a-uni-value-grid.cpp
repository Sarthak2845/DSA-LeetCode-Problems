class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> values;
        
        for (auto& row : grid)
            for (int num : row)
                values.push_back(num);
        

        int remainder = values[0] % x;  
        for (int num : values) {
            if (num % x != remainder)  
                return -1;
        }
        sort(values.begin(), values.end());
        int median = values[values.size() / 2];

        int operations = 0;
        for (int num : values) {
            operations += abs(num - median) / x;  
        }

        return operations;
    }
};
