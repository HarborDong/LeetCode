/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraphHelper(UndirectedGraphNode *node, 
                                    unordered_map<int, UndirectedGraphNode *> &record) {
        if(node == NULL) return NULL;
        UndirectedGraphNode *ret = NULL;
        unordered_map<int, UndirectedGraphNode *> :: const_iterator iter =
            record.find(node->label);
        if(iter == record.end()) {
            ret = new UndirectedGraphNode(node->label);
            record[node->label] = ret;
        
            for(int i = 0; i < node->neighbors.size(); i++) {
                UndirectedGraphNode *neighbor = NULL;
                neighbor = cloneGraphHelper(node->neighbors[i], record);
                if(neighbor)
                    ret->neighbors.push_back(neighbor);
            }
        } else {
            ret = iter->second;
        }
        return ret;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        unordered_map<int, UndirectedGraphNode *> record;
        UndirectedGraphNode *ret = NULL;
        ret = cloneGraphHelper(node, record);

        return ret;
    }
};


