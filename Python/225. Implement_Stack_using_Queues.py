class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []      
        

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.stack.append(x)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.stack.pop() if len(self.stack) else None
        

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.stack[-1] if len(self.stack) else None
            
        

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return False if len(self.stack) else True


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
