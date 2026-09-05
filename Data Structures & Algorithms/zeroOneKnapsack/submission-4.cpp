class Solution {
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
            int N = profit.size(), M = capacity;
            vector<vector<int>> cache(N, vector<int>(M + 1, -1));
            return memoHelper(0, profit, weight, capacity, cache);
        }
    int memoHelper(int i, vector<int>& profit, vector<int>& weight,
        int capacity, vector<vector<int>>& cache){
            if(i == profit.size()) return 0;

            if(cache[i][capacity] != -1){
                return cache[i][capacity];
            }

            cache[i][capacity] = memoHelper(i+1, profit, weight, capacity, cache);

            int newCap = capacity - weight[i];
            if(newCap >= 0){
                int p = profit[i] + memoHelper(i + 1, profit, weight, newCap, cache);
                cache[i][capacity] = max(cache[i][capacity], p);
            }
            return cache[i][capacity];
        }
};
