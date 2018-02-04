/**
 * 总感觉这题的测试用例没有完全覆盖
 * [4,5,3,1,4]
 * [5,4,3,4,2]
 * 我的答案是-1,然后希望答案是4.
 * 题目的思路就是找连续余量为正的序列
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int tank = 0;
        int begin = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += (gas[i] - cost[i]);
            if (tank < 0)
            {
                begin = i + 1;
                tank = 0;
            }
        }
        
        return (totalGas >= totalCost ? begin : -1);
    }
}
