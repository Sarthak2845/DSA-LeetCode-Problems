class Solution {
public:
    char kthCharacter(int k) {
        vector<int>word;
        word.push_back(0);
        while(word.size()<k){
            int currSize=word.size();
            for(int i=0;i<currSize;i++){
                    word.push_back((word[i]+1)%26);
            }
        }
         return 'a' + word[k - 1];
    }
};