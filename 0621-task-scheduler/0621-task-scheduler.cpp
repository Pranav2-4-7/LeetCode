class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char , int> counts;

        for(char t : tasks) counts[t]++;

        priority_queue<int> maxHeap;

        for(auto const& [task , count] : counts){
            maxHeap.push(count);
        }

        queue<pair<int , int>> cooldownQueue;
        int time = 0;

        while(!maxHeap.empty()|| !cooldownQueue.empty()){
            time++ ;
        

        if(!maxHeap.empty()){
            int remainingCount = maxHeap.top() -1; 
            maxHeap.pop();
        
        if(remainingCount > 0){
            cooldownQueue.push({remainingCount , time + n});

        }
     }
     if(!cooldownQueue.empty() && cooldownQueue.front().second == time){
        maxHeap.push(cooldownQueue.front().first);
        cooldownQueue.pop();
     }
    }
    return time;
    }
};