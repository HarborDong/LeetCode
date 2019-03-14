visited = 1
visiting = 2
class Solution:
    def DFS(self, i: int) -> bool:
        if len(self.matrix[i]) == 0:
            self.course_status[i] = visited
            return True

        if self.course_status[i] == visiting:
            return False
        if self.course_status[i] == visited:
            return True
        
        self.course_status[i] = visiting
        for j in self.matrix[i]:
            if self.DFS(j) == False:
                return False
        self.course_status[i] = visited

        return True
    
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        self.matrix = [[] for i in range(numCourses)]

        self.visited_list = []
        self.visiting_list = []
        self.course_status = [0] * numCourses
        for i, j in prerequisites:
            if i == j:
                return False
            self.matrix[i].append(j)

        status = [0] * numCourses
        i = 0
        for i in range(numCourses):
            if self.DFS(i) == False:
                return False
        
        return True
            
            
        
        
