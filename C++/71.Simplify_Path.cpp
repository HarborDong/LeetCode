class Solution {
public:
    string simplifyPath(string path) {
        deque<string> fileQue;
        string file;
        string simplePath;
        string::iterator iter = path.begin();
        deque<string>::iterator iterQ;
        while(iter != path.end()) {
            if ((*iter == '/') || (iter == path.end() - 1)) {
                if((iter == path.end() - 1) && *iter != '/') {
                    file.push_back(*iter);
                }
                if(file.size() != 0) {
                    if(!file.compare(".")) {

                    } else if (!file.compare("..")) {
                        if(fileQue.size() != 0) {
                            fileQue.pop_back();
                        }
                    } else {
                        fileQue.push_back(file);
                    }
                    file.clear();
                }
            } else {
                file.push_back(*iter);
            }
            iter++;
        }
        
        iterQ = fileQue.begin();
        while(iterQ != fileQue.end()) {
            simplePath += "/";
            simplePath += *iterQ;
            iterQ++;
        }
        if(simplePath.length() == 0) simplePath += "/";
        return simplePath;
    }
};
