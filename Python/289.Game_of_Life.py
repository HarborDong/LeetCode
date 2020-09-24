class Solution:
    def stateChange(self, cur:int, num_of_one:int) -> int:
        if cur == 1:
            if num_of_one < 2 or num_of_one >3:
                return 0
            else:
                return 1
        elif cur == 0:
            if num_of_one == 3:
                return 1
            else:
                return 0
                
                
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        import copy
        if not board: return

        for i in range(len(board)):
            board[i].insert(0, 0)
            board[i].append(0)

        board.append([0]*len(board[0]))
        pre_list = [0] * len(board[0])
        for i in range(len(board)-1):
            cur_list = copy.deepcopy(board[i])
            for j in range(1, len(board[i]) - 1):
                sum1 = sum([pre_list[j-1], pre_list[j], pre_list[j+1], cur_list[j-1], cur_list[j+1], board[i+1][j-1], board[i+1][j], board[i+1][j+1]])
                #print(board[i][j], sum1)
                board[i][j] = self.stateChange(board[i][j], sum1)
                #print(board[i][j])
            pre_list = copy.deepcopy(cur_list)
        #print(board)
        board.pop()
        for i in range(len(board)):
            board[i].pop(0)
            board[i].pop()        
        return 
        
        
