

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
	


    public boolean legalMove(int r, int c, int color, boolean retourner) 
	{
		
		boolean legal = false;
		
	
		if (board[r][c] == 0)
		{
	
			int posX;
			int posY;
			boolean found;
			int current;
			

			for (int x = -1; x <= 1; x++)
			{
				for (int y = -1; y <= 1; y++)
				{
				
					posX = c + x;
					posY = r + y;
					found = false;
					current = board[posY][posX];
					
				
					if (current == -1 || current == 0 || current == color)
					{
						continue;
					}
					
				
					while (!found)
					{
						posX += x;
						posY += y;
						current = board[posY][posX];
						
					
						if (current == color)
						{
							found = true;
							legal = true;
						
							if (retourner)
							{
								posX -= x;
								posY -= y;
								current = board[posY][posX];
								
								while(current != 0)
								{
									board[posY][posX] = color;
									posX -= x;
									posY -= y;
									current = board[posY][posX];
								}
							}
						}
						else if (current == -1 || current == 0)
						{
							found = true;
						}
					}
				}
			}
		}

        return legal;
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
