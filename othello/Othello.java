
import java.util.*;



public class Othello
{
    final static int BLACK = 1;         
    final static int WHITE = 2;
    final static int EMPTY = 0;
    final static int OFFBOARD = -1;

    Black black = new Black();         
    White white = new White();

    private Game game = new Game();    
  
 
    private int turn = BLACK;
    private boolean black_done = false; 
    private boolean white_done = false;
    


    
   

    public void initGame(Game game) {

        turn = BLACK;
      
        for (int i=0; i<game.WIDTH; i++) {     
            game.board[i][0] = OFFBOARD;
            game.board[i][game.WIDTH-1] = OFFBOARD;
            game.board[0][i] = OFFBOARD;
            game.board[game.HEIGHT-1][i] = OFFBOARD;
        }

       
        for (int i=1; i<game.HEIGHT-1; i++)        
            for (int j=1; j<game.WIDTH-1; j++)
			   game.board[i][j] = EMPTY;
        
        game.board[game.HEIGHT/2-1][game.WIDTH/2-1] = WHITE;        
        game.board[game.HEIGHT/2][game.WIDTH/2-1] = BLACK;
        game.board[game.HEIGHT/2-1][game.WIDTH/2] = BLACK;
        game.board[game.HEIGHT/2][game.WIDTH/2] = WHITE;
    }



    public void playerMove() {
        
        if (turn == BLACK) {
            blackMove();
            turn = WHITE;
        }
        else {
            whiteMove();
            turn = BLACK;
        }
    }

    public void blackMove() {
       
       
        black_done = true;
        for (int i=1; i<game.HEIGHT-1; i++)
            for (int j=1; j<game.WIDTH-1; j++)
                if (game.legalMove(i,j,BLACK,false) ) 
                    black_done=false;

        game = black.strategy(game, black_done, BLACK);          
    } 

 
    public void whiteMove() {

  
        white_done = true;
        for (int i=1; i<game.HEIGHT-1; i++)
            for (int j=1; j<game.WIDTH-1; j++)
                if (game.legalMove(i,j,WHITE,false) )
                    white_done=false;
        
        game = white.strategy(game, white_done, WHITE);
    }

   



   
public static void main(){		
      

      
}  

}
