
def getPosition(initialPostion):
    xchar = initialPostion[0]
    yint = int(initialPostion[1]);
    xint = ord(xchar) - 97;
    return 8- yint,xint

def isPositionPossible(x ,y):
    if x>=0 and x<=7 and y>=0 and y<=7:
        return True
    return False

def runAllJumps(ChessBoard, x, y):

    currentsteps = ChessBoard[x][y]
    #For x+2,y-1
    nx, ny = x+2, y-1
    if isPositionPossible(nx, ny):
        if currentsteps + 1 < ChessBoard[nx][ny]:
            ChessBoard[nx][ny] = currentsteps + 1
            runAllJumps(ChessBoard, nx, ny)

    #For x+2,y+1
    nx, ny = x+2, y+1
    if isPositionPossible(nx, ny):
        if currentsteps + 1 < ChessBoard[nx][ny]:
            ChessBoard[nx][ny] = currentsteps + 1
            runAllJumps(ChessBoard, nx, ny)

    #For x-2,y-1
    nx, ny = x-2, y-1
    if isPositionPossible(nx, ny):
        if currentsteps + 1 < ChessBoard[nx][ny]:
            ChessBoard[nx][ny] = currentsteps + 1
            runAllJumps(ChessBoard, nx, ny)


    #For x-2,y+1
    nx, ny = x-2, y+1
    if isPositionPossible(nx, ny):
        if currentsteps + 1 < ChessBoard[nx][ny]:
            ChessBoard[nx][ny] = currentsteps + 1
            runAllJumps(ChessBoard, nx, ny)


    #For x+1,y+2
    nx, ny = x+1, y+2
    if isPositionPossible(nx, ny):
        if currentsteps + 1 < ChessBoard[nx][ny]:
            ChessBoard[nx][ny] = currentsteps + 1
            runAllJumps(ChessBoard, nx, ny)



    #For x-1,y+2
    nx, ny = x-1, y+2
    if isPositionPossible(nx, ny):
        if currentsteps + 1 < ChessBoard[nx][ny]:
            ChessBoard[nx][ny] = currentsteps + 1
            runAllJumps(ChessBoard, nx, ny)



    #For x+1,y-2
    nx, ny = x+1, y-2
    if isPositionPossible(nx, ny):
        if currentsteps + 1 < ChessBoard[nx][ny]:
            ChessBoard[nx][ny] = currentsteps + 1
            runAllJumps(ChessBoard, nx, ny)



    #For x-1,y-2
    nx, ny = x-1, y-2
    if isPositionPossible(nx, ny):
        if currentsteps + 1 < ChessBoard[nx][ny]:
            ChessBoard[nx][ny] = currentsteps + 1
            runAllJumps(ChessBoard, nx, ny)

    return ChessBoard

def convertToChessPostion(i, j):
    position = str(chr(j+97))
    position = position + str(8-i)
    return position

def determineHidingPlaces(initialPostion):
    # Creates a list containing 5 lists, each of 8 items, all set to 0
    w, h = 8, 8;
    maxsteps = 1000
    ChessBoard = [[maxsteps for x in range(w)] for y in range(h)]

    x, y = getPosition(initialPostion)
    # set Initial position
    ChessBoard[x][y] = 0;
    
    # Run the horse for all possibilites of jump
    ChessBoard = runAllJumps(ChessBoard, x,y)

    #determine steps to reach hiding places
    steps = -1;
    for i in range(0,8):
        for j in range(0,8):
            steps = max(steps, ChessBoard[i][j])

    #uncomment to debug
    #print ChessBoard
    #determine positions to reach hiding places
    list = []
    for i in range(0,8):
        for j in range(0,8):
            if steps == ChessBoard[i][j]:
                chessPosition = convertToChessPostion(i, j)
                list.append(chessPosition)

    #uncomment to debug
    #print ChessBoard
    return steps, list


'''
    Description: Controller method to get input and determine ouptut for knight hiding places problem
'''
def main():
    testCases = int(raw_input())
    while testCases > 0:
        # get Intial position
        initialPostion = raw_input()
        
        #Determin knight hiding places
        distance, list = determineHidingPlaces(initialPostion)
        
        #print distance of hiding places
        print distance,
        #print hiding places
        for position in list:
            print position,
        testCases = testCases - 1
        print

'''
    Program Entery point
'''
if __name__ == "__main__":
    main()


