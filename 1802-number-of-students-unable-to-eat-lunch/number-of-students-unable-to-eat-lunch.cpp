class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0, 0};
        for (int s : students) {
            count[s]++;
        }
        for(int c:sandwiches){
            if(count[c]==0){
                return count[0]+count[1];
            }
            count[c]--;
        }
        return 0;
    }
};