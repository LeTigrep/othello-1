

public class Game 
{
    final static int BLACK = 1;          
    final static int WHITE = 2;
    final static int EMPTY = 0;
    final static int WIDTH = 10;
    final static int HEIGHT = 10;
    final int board[][] = new int[WIDTH][HEIGHT];
	

	
    public Game() 
	{
	}
	



    public Game(Game another) 
	{
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				this.board[i][j] = another.board[i][j];
			}
		}
	}
	


    public boolean legalMove(int r, int c) 
    {
    }


	public void printBoard()
	{
		for (int i = 1; i <= HEIGHT - 2; i++)
		{
			for (int j = 1; j <= WIDTH - 2; j++)
			{
				System.out.print("[" + board[i][j] + "]");
			}
			System.out.println();
		}
	}
}
