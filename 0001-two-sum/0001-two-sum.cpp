class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>v(nums);
        sort(v.begin(),v.end());

        int i=0,j=n-1;
        int left,right;
        while(i<j){
            if(v[i]+v[j]==target){
                left=v[i];
                right=v[j];
                break;
            }
            else if(v[i]+v[j]>target)j--;
            else i++;
        }
        int idx1=-1,idx2=-1;
        for(int i=0;i<n;i++){
              if(left==nums[i] || right==nums[i]){
                if(idx1==-1)idx1=i;
                else idx2=i;
              }
        }
        if(idx1==-1 || idx2==-1)return {};
        return {idx1,idx2};
        
        
    }
};