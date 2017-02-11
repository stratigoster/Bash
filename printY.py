def initialize( maze ):
    for i in range(0, 63):
        maze.append([])
        for j in range(0, 100):
            maze[i][j] = '_'

def printMaze( maze ):
    for i in range(63, -1, -1):
        print '{}'.format("".join(maze[i]))

def printY( maze,startX,startY,distance,n ):
    if (n == 0):
        return

    for i in range( 0, distance ):
        maze[startX+i][startY] = '1'
    
    temp=startX
    temp=temp+distance-1
        
    for i in range( 1, distance+1):
        maze[temp+i][startY+i]='1'

    for i in range( 1, distance+1):
        maze[temp+i][startY-i]='1'

    temp1=startX+distance*2
    temp2=startY-distance
    temp3=startY+distance
    temp4=distance/2
    temp5=int(n)-1

    printY(maze, temp1, temp2, temp4, temp5)
    printY(maze, temp1, temp3, temp4, temp5)

def main():
    maze = []
    print "maze"
    for i in range(0, 63):
        maze.append([])
        for j in range(0, 100):
            maze[i].append('_')
    initialize(maze)
    cnt = raw_input('N value is :')
    printY(maze, 0, 50, 16, cnt)
    printMaze(maze)

main()
