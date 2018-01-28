class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.size() == 0) return 0;
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        queue<string> wordqueue;
        queue<int> levelqueue;
        if(!wordset.count(endWord)) return 0; 
        wordqueue.push(beginWord);
        levelqueue.push(1);
        while(wordqueue.size()) {
            string top = wordqueue.front();
            int level = levelqueue.front();
            //cout << "level: " << level << " top " << top << endl;
            if(top == endWord) {
                return level;
            }
            for(int i = 0; i < top.length(); i++) {
                char ch = top[i];
                for(char j = 'a'; j <='z'; j++)
                {
                    if(j == ch) continue;
                    top[i] = j;
                    if(wordset.count(top)) {
                        wordqueue.push(top);
                        levelqueue.push(level + 1);
                        wordset.erase(top);
                    }
                }
                top[i] = ch;
            }
            wordqueue.pop();
            levelqueue.pop();
        }
        return 0;
    }
};
