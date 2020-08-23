class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        overlap_x_start = overlap_x_end = 0
        overlap_y_start = overlap_y_end = 0
        
        if A <= E and E <= C:
            overlap_x_start = E
        elif E <= A and A <= G:
            overlap_x_start = A
            
        if A <= G and G <= C:
            overlap_x_end = G
        elif E <= C and C <= G:
            overlap_x_end = C
        
        if B <= F and F <= D:
            overlap_y_start = F
        elif F <= B and B <= H:
            overlap_y_start = B
            
        if B <= H and H <= D:
            overlap_y_end = H
        elif F <= D and D <= H:
            overlap_y_end = D
            
        return (C- A) * (D - B) + (G - E) * (H - F) -(overlap_x_end - overlap_x_start) * (overlap_y_end - overlap_y_start)
