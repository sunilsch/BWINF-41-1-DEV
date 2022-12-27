from copy import deepcopy

def read_data():
    print("Enter number of example: ", end="")
    filename = input()
    sudokuOrg = []
    sudokuNew = []
    try:
        with open('../beispieleingaben/sudoku'+filename+'.txt', encoding='utf-8') as f:
            f.read(1)
            for _ in range(9):
                sudokuOrg.append([int(x.strip()) for x in f.read(18).split(" ")])
            f.readline()
            for _ in range(9):
                sudokuNew.append([int(x.strip()) for x in f.read(18).split(" ")])
    except:
        print("Invalid number")
        exit(1) 

    return sudokuOrg, sudokuNew

def rotate_sudoku(sudoku):
    rotated_sudokus = []
    rotated_sudoku = deepcopy(sudoku)
    rotated_sudoku.append(rotate_sudoku)
    for _ in range(3):
        N = len(rotated_sudoku[0])
        for i in range(N // 2):
            for j in range(i, N - i - 1):
                temp = rotated_sudoku[i][j]
                rotated_sudoku[i][j] = rotated_sudoku[N - 1 - j][i]
                rotated_sudoku[N - 1 - j][i] = rotated_sudoku[N - 1 - i][N - 1 - j]
                rotated_sudoku[N - 1 - i][N - 1 - j] = rotated_sudoku[j][N - 1 - i]
                rotated_sudoku[j][N - 1 - i] = temp
        rotated_sudokus.append(deepcopy(rotated_sudoku))
    return rotated_sudokus

def printMatrix(A):
    N = len(A[0])
    for i in range(N):
        print(A[i])
    print("")

def check(sudoku):
    pass

def solve():
    sudokuOrg, sudokuNew = read_data()
    
    sudokuRotated = rotate_sudoku(sudokuNew)
    for sudoku in sudokuRotated:
        pass

if __name__  == "__main__":
    solve()