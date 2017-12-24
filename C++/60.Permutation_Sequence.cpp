class Solution {
public:
    /* method 1 backtracking
    void getPermutationHelper(string &str, int k, int start, int &time) {
        int index = start;
        char temp;
        if(index == str.size()) {
            time++;
            return ;
        }
        for(index = start; index < str.size(); index++) {
            temp = str[index];
            for(int i = index; i > start; i--) {
                str[i] = str[i-1];
            }
            str[start] = temp;
            getPermutationHelper(str, k, start + 1, time);
            if(time == k) return;
            temp= str[start];
            for(int i = start; i < index; i++) {
                str[i] = str[i+1];
            }
            str[index] = temp;
        }
    }
    string getPermutation(int n, int k) {
        string ret(n, 0);
        int time = 0;
        for(int i = 0; i < n; i++) {
            ret[i] = i + '1';
        }
        getPermutationHelper(ret, k, 0, time);
        return ret;     
    }*/
    /**
     * method 2 math
     * the kth permutation sequence is the kth bigger than the original sequence
     * the m bit in the front is constant, we have (n-m)! sequence. 
     */
    string getPermutation(int n, int k) {
        vector<int> number(n, 1);
        vector<int> factorial(n, 1);
        string str(n, 0);
        for(int i = 1; i < n; i++) {
            number[i] = i + 1;
            factorial[i] = factorial[i-1] * i;
        }
        if (k > factorial[n-1] * n || k < 1 || n < 1) return str;
        k -= 1;
        for(int i = n - 1; i >= 0; i--) {
            int index = k/ factorial[i];
            k = k % factorial[i] ;
            str[n - 1 - i] = number[index] + '0';
            number.erase(number.begin() +index);
        }

        return str;
    }
};
