class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        for i, row in enumerate(board):
            for j, v in enumerate(row):
                board[i][j] = (
                    (board[i-1][j-1] & 1 if i > 0            and j > 0          else 0) +
                    (board[i-1][j  ] & 1 if i > 0                               else 0) +
                    (board[i-1][j+1] & 1 if i > 0            and j < len(row)-1 else 0) +
                    (board[i  ][j-1] & 1 if                      j > 0          else 0) +
                    (board[i  ][j+1]     if                      j < len(row)-1 else 0) +
                    (board[i+1][j-1]     if i < len(board)-1 and j > 0          else 0) +
                    (board[i+1][j  ]     if i < len(board)-1                    else 0) +
                    (board[i+1][j+1]     if i < len(board)-1 and j < len(row)-1 else 0)) << 1 | v

        for i, row in enumerate(board):
            for j, v in enumerate(row):
                neighbor = v >> 1
                if v & 1 == 1 and neighbor == 2 or neighbor == 3:
                    board[i][j] = 1
                else:
                    board[i][j] = 0
