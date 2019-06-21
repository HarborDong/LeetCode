class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:

        self.indegree = [0] * numCourses
        self.outdegree = {}
        self.res = []
        for pair in prerequisites:
            if pair[1] in self.outdegree:
                self.outdegree[pair[1]].append(pair[0])
            else:
                self.outdegree[pair[1]] = [pair[0]]
            self.indegree[pair[0]] += 1
        
        self.res = [i for i in range(numCourses) if self.indegree[i] == 0]

        start = 0; end = len(self.res)
        while start != end:
            if self.res[start] in self.outdegree:
                for j in self.outdegree[self.res[start]]:
                    self.indegree[j] -= 1
                    if self.indegree[j] == 0:
                        self.res.append(j)
                        end += 1
                    elif self.indegree[j] < 0:
                        return []
            start += 1
        
        if end == numCourses:
            return self.res
        else:
            return []
