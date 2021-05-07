

public class Black {

 
    public Game strategy(Game game, boolean done, int color) {
        
        return randStrategy(game,done,color);
    }


    public Game randStrategy(Game game, boolean done, int color) {

        int row = (int)(Math.random()*(game.HEIGHT-2)) + 1;
        int column = (int)(Math.random()*(game.WIDTH-2)) + 1;
        
        while (!done && !game.legalMove(row,column,color,true)) {
            row = (int)(Math.random()*(game.HEIGHT-2)) + 1;
            column = (int)(Math.random()*(game.WIDTH-2)) + 1;
        }
        
        if (!done)
            game.board[row][column] = color;

        return game;
    }

    
}