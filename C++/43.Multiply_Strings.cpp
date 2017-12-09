class Solution {
public:

    void vector2Str(vector<int> &result, string &res){
        int i = result.size() - 1;
        for( ; i >= 0; i--) {
            if(result[i] != 0) {
                break;
            } 
        }
        for( ; i >= 0; i--) {
            res += to_string(result[i]);
        }
        if(res.size() == 0) res = "0";
        return;
    }

    string multiply(string num1, string num2) {
        vector<int> result(num1.length() + num2.length(), 0);
        string res;
        int num1len = num1.length(), num2len = num2.length();
        for(int i = num2len - 1; i >= 0; i--) {
            if(num2[i] == 0) continue;
         
            for(int j = num1len - 1; j >= 0; j--) {
                int index = num1len + num2len -i -j -2;
                result[index] += (num2[i] - '0') * (num1[j] - '0');;
                result[index + 1] += result[index] /10;
                result[index] = (result[index] % 10);
            }
        }
        vector2Str(result, res);
        return res;
    }
};
