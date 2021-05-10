

public class Game 
{
    final static int BLACK = 1;          
    final static int WHITE = 2;
    final static int EMPTY = 0;
    final static int WIDTH = 10;
    final static int HEIGHT = 10;
    final int bord[][] = new int[WIDTH][HEIGHT];
	

	
    public Game() 
	{
	}
	



    public Game(Game another) 
	{
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				this.bord[i][j] = another.bord[i][j];
			}
		}
	}
	


    public boolean legal(int r, int c) 
    {
    }


	public void printBord()
	{
		for (int i = 1; i <= HEIGHT - 2; i++)
		{
			for (int j = 1; j <= WIDTH - 2; j++)
			{
				System.out.print("[" + bord[i][j] + "]");
			}
			System.out.println();
		}
	}
}
