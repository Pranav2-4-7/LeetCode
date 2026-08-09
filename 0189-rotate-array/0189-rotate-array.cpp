class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        vector<int> q1;
        vector<int> q2;

        for(int i = 0 ; i < n - k; i++ ){
            q1.push_back(nums[i]);
        }
        for(int i = n - k ; i < n ; i ++){
            q2.push_back(nums[i]);
        }

        for(int i = 0 ; i < q2.size(); i++){
            nums[i] = q2[i];
        }

        for(int i = 0 ; i < q1.size() ; i++){
            nums[k+i] = q1[i];
        }
    }
};