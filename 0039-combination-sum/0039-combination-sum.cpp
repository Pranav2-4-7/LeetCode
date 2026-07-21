class Solution {
public:
    void backtrack(int index, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result){
        if(target == 0){
            result.push_back(current);
            return;
        }
        if(target < 0 || index == candidates.size()){
            return;
        }
        current.push_back(candidates[index]);
        backtrack(index , target - candidates[index] , candidates , current , result);

        current.pop_back();
        backtrack(index + 1 , target , candidates , current , result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(0 , target, candidates , current , result );
        return result;
    }
};