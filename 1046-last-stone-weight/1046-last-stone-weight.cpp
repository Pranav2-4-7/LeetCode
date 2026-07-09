class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> smartQueue(stones.begin(), stones.end());

        return runGame(smartQueue);
        }
private:
    int runGame(priority_queue<int>& q){
        if(q.empty()) return 0;

        if(q.size() == 1) return q.top();

        int y = q.top(); q.pop();
        int x = q.top(); q.pop();

        if ( x!= y){
            q.push(y-x);
        }
        return runGame(q);
    }
    
};