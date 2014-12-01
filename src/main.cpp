#include <iostream>

int main()
{

  bool takeTurn(BoardGame<Tile, Player, N, N>& bg, const std::string& pName) {

    try {
      Move m;
      cin.exceptions(std::istream::failbit);
      cin>> m;
      const Tile t = bg.move( m, pName );
      Player p = bg.getPlayer( pName );
      if (p.canAct()) {
        bool makeAction;
        cin>>makeAction;
        if ( makeAction ) std::vector<Player> opL = bg.getPlayers( t );
        if (p.getGold()>= opL.size()) {
          p.eat();
          for ( auto op : opL ) {
            p.pay( op, 1 );
            bg.setPlayer( op );
          }
          t.action( p );
          bg.setPlayer( p );
        }
      }
      return true;
    } 
    catch ( std::istream::failure e ) {
      cout<< “Incorrect key pressed”; cin.clear(); }
    } 
    catch ( std::out_of_range e ) {
      cout<< e.what();
    }
    return false;
  }
    /*
        if game is paused
          resume
        else
          Setup: Input the names of all players and the size of the board. Initialize a board game for N players
        While no Player has won
          Check for Pause
          For each Player
            Display Player status
            while move is not valid
              Input move (up/down/right or left)
            Move Player to Tile
            if Player has food items
              Display Tile Action
              if Player chooses Action and Action is valid
                if Tile occupied
                  Player pays other Player
                Perform Action
            Display Player status
            if Player has 5 Rubies player has won
        */

    
}
