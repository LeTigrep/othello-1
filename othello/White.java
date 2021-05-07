
public class White 
{
	

	public White()
	{
		
	}
	
	
	
  
    public Game strategy(Game game, boolean done, int color) {
        
        return randStrategy(game,done,color);
    }


	
    public Game randStrategy(Game game, boolean done, int color) {

        int ligne = (int)(Math.random()*(game.HEIGHT-2)) + 1;
        int colone = (int)(Math.random()*(game.WIDTH-2)) + 1;
        
        while (!done && !game.legalMove(ligne,colone,color,true)) {
            ligne = (int)(Math.random()*(game.HEIGHT-2)) + 1;
            colone = (int)(Math.random()*(game.WIDTH-2)) + 1;
        }
        
        if (!done) 
            game.board[ligne][] = color;

        return game;
    }

    
}
