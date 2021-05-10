
public class blanc 
{
	

	public blanc()
	{
		
	}
	
	
	
  
    public Game strategie(Game game, boolean done, int color) {
        
        return randStrategie(game,done,color);
    }


	
    public Game randStrategie(Game game, boolean done, int color) {

        int ligne = (int)(Math.random()*(game.HEIGHT-2)) + 1;
        int colone = (int)(Math.random()*(game.WIDTH-2)) + 1;
        
        while (!done && !game.legalPas(ligne,colone,color,true)) {
            ligne = (int)(Math.random()*(game.HEIGHT-2)) + 1;
            colone = (int)(Math.random()*(game.WIDTH-2)) + 1;
        }
        
        if (!done) 
            game.bord[ligne][] = color;

        return game;
    }

    
}
