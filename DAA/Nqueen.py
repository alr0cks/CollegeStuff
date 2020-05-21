def checkSafe(board, row, col):

    for i in range(col):
        if board[row][i] == 1:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, n, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True

def solveNQueen(board, col):

    if col >= n:
        return True

    for i in range(n):

        if checkSafe(board, i, col):

            board[i][col] = 1
            if solveNQueen(board, col + 1) == True:
                return True
            board[i][col] = 0

    return False

n = int(input("Enter Value of N:"))
board = [[0]*n for x in range(n)]
solveNQueen(board, 0)
for i in board:
    print(i)







