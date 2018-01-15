class Solution {
/**
 * num[n] = ∑num[i] * num[n - i - 1]
 */
public:
    int numTrees(int n) {
        vector<int> record(n + 1, 0);
        record[0] = 1;
        for(int index = 1; index <= n; index++) {
            for(int left = 0; left < index; left++){
                record[index] += record[left]*record[index - left - 1];
            }
        }
        if(n == 0)
            return 0;
        else
            return record[n];
   }
};
