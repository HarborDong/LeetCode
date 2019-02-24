class Solution:
    def islandDFS(self, i: int, j: int):
        if self.grid[i][j] == '0':
            return
        self.grid[i][j] = '0'
        if i > 0: self.islandDFS(i - 1, j)
        if i < self.row - 1: self.islandDFS(i + 1, j)
        if j > 0: self.islandDFS(i, j - 1)
        if j < self.col - 1: self.islandDFS(i, j + 1)
        
    def numIslands(self, grid: List[List[str]]) -> int:
        self.island_num = 0
        if not grid: return 0
        self.grid = grid
        self.row, self.col = len(grid), len(grid[0])
        for i in range(self.row):
            for j in range(self.col):
                if grid[i][j] == '1':
                    self.islandDFS(i, j)
                    self.island_num += 1
        return self.island_num
