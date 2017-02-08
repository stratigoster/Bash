public class PrintYRecursion {

    public static final int ROW = 63;
    public static final int COL = 100;
    public static char maze[][] = new char[ROW][COL];

    public static void initialize(char maze[][]) {
        for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				maze[i][j] = '_';
			}
		}
    }

    public static void printMaze(char maze[][]) {
        for (int i = ROW-1; i >= 0; i--) {
			for (int j = 0; j < COL; j++) {
				System.out.print(maze[i][j]);
			}
			System.out.println();
		}
    }

    public static void printY(char maze[][], int startX, int startY, int distance, int n) {
    	
    	if (n == 0) {
    		return;
    	}
        
        for (int i = 0; i < distance; i++) {
        	maze[startX+i][startY] = '1';
        }
        int temp = startX;
        temp = temp + distance - 1;
        
        for (int i = 1; i <= distance; i++) {
        	maze[temp+i][startY+i] = '1';
        }

        for (int i = 1; i <= distance; i++) {
 			maze[temp+i][startY-i] = '1';
        }

        printY(maze, startX+distance*2, startY - distance, distance/2, n-1);
        printY(maze, startX+distance*2, startY + distance, distance/2, n-1);
    }

	public static void main(String args[]) {

		initialize(maze);
		
		printY(maze, 0, COL/2, 16, 5);
	   printMaze(maze);
	}
}