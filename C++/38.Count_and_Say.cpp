class Solution {
public:
    string countAndSay(int n) {
        string res({'1'});
        string temp({0});
        int i = 1, j = 0, count = 0;

        for(; i < n; i++) {
            temp = res;  
            res.clear();
            j = 0;
            while(j < temp.length()) {
                count = 1;
                while(temp[j] == temp[j + count] && temp[j]) {
                    count++;
                }
	       /****************************************
		* change res = res + to_string(count) + temp[j]
		* to res = res + (to_string(count) + temp[j])
		* the performance of function increase 50%.
		*/	
                res = res + (to_string(count) + temp[j]);
                j += count;
             }
        }
        return res;
    }
};
