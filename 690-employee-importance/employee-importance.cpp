/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*>mp;
        int total=0;
        for(auto e:employees){
            mp[e->id]=e;
        }
        queue<int>q;
        q.push(id);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            Employee* emp=mp[curr];
            total+=emp->importance;
            for(int sub:emp->subordinates){
                q.push(sub);
            }
        }
        return total;
    }
};