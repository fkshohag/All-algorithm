class TicTacToe:

    def __init__(self, n: int):
        self.board = [[0]*n for _ in range(n)]
        self.n = n

    def checkRow(self, row: int, player: int) -> bool:
        for col in range(self.n):
            if self.board[row][col] != player:
                return False
        return True

    def checkCol(self, col: int, player: int) -> bool:
        for row in range(self.n):
            if self.board[row][col] != player:
                return False
        return True
    
    def checkDiagonal(self, player: int) -> bool:
        for row in range(self.n):
            if self.board[row][row] != player:
                return False
        return True
    
    def checkAntiDiagonal(self, player: int) -> bool:
        for row in range(self.n):
            if self.board[row][self.n - row - 1] != player:
                return False
        return True

    def move(self, row: int, col: int, player: int) -> int:
        self.board[row][col] = player
        if (self.checkCol(col, player) or self.checkRow(row, player) or
            (row == col and self.checkDiagonal(player)) or
            (row == self.n - col - 1 and
              self.checkAntiDiagonal(player))
            ):
            return player
        return 0
        


# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)