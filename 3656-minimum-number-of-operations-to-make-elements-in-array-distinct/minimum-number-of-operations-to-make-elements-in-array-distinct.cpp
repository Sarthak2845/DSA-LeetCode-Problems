class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int i=0,operation=0;
        while(i<nums.size()){
            set<int>st;
            bool dupFound=false;
            for(int j=i;j<nums.size();j++){
                if(st.count(nums[j])){
                    operation+=1;
                    i+=3;
                    dupFound=true;
                    break;
                }
                st.insert(nums[j]);
            }
            if(!dupFound) break;
        }
    return operation;
    }
};