#include <iostream>

int main()
{
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

    for(int i = 0; i <= 10; i++) {
      std::cout << i << std::endl;
    }
}
