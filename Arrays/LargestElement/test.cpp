class Solution {
    public:
      int largest(vector<int> &arr) {
          // code here
          int largest=arr[0];
          int largeI=0;
          for(int i=0;i<arr.size();i++){
              if(arr[i]>arr[largeI]){
                  largeI=i;
                  largest=arr[i];
              }
          }
          return largest;
      }
  };
  