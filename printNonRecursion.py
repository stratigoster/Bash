maze = [[]]

def initialize(maze):
   for i in range(0, 63):
        maze.append([])
        for j in range(0, 100):
            maze[i].append("_"),

def printMaze(maze):
    for i in range(63, -1, -1):
        print '{}'.format("".join(maze[i]))

def printYInRegion(maze,startPointX,startPointY,distance):
    i=0;
    j=0;

    for i in range(0, distance):
      print "startPoint is:"
      print startPointX+i
      maze[startPointX+i+1][startPointY]='1'

    for j in range(1, distance+1):
        maze[startPointX+i+j+1][startPointY+j]='1'

    for j in range(1, distance+1):
        maze[startPointX+i+j+1][startPointY-j]='1'

def main():

    initialize(maze)

    n = raw_input('Enter the value for n:')
    outcome=int(n)
    print outcome
    startPoint = 0
    distance = pow(outcome, 2)
            
    startValue = 100/2
    cnt=5

    startValueArray=[0,0,0,0,50]
    while cnt > 1:
        startValue -= pow(2,(cnt-1))
        startValueArray[cnt-2]=startValue
        cnt=cnt-1

    for i in range(outcome, 0, -1):
        power = pow(2, 5-i)
        inversePower = pow(2, i-1)
        xValue = 63-(4*power)
        length = 0
        for j in range(0, inversePower):
            width=startValueArray[5-i] + power * j * 4
            printYInRegion(maze, xValue, width, power)
    
    printMaze(maze)
main()
