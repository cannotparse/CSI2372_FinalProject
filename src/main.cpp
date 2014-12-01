#include <iostream>
#include <vector>
#include "GameBoard.h"
#include "Player.cpp"

bool takeTurn(BoardGame<Tile, Player, N, N>& bg, const std::string& pName) {
  try {
    Move m;
    cin.exceptions(std::istream::failbit);
    cin >> m;
    const Tile t = bg.move(m, pName);
    Player p = bg.getPlayer(pName);
    if(p.canAct()) {
      bool makeAction;
      cin >> makeAction;
      if(makeAction) std::vector<Player> opL = bg.getPlayers( t );
      if(p.getGold() >= opL.size()) {
        p.eat();
        for(auto op : opL) {
          p.pay(op, 1);
          bg.setPlayer(op);
        }
        t.action(p);
        bg.setPlayer(p);
      }
    }
    return true;
  }
  catch (std::istream::failure e) {
    cout<< “Incorrect key pressed”; cin.clear(); 
  }
  catch (std::out_of_range e) {
    cout<< e.what();
  }
  return false;
}


int main() {

  enum Move {UP, DOWN, LEFT, RIGHT};

  BoardGame bg = BoardGame();
  std::map<string,J> allPlayers;
  Player player;
  Move move;
  int amountOfPlayers;
  string name, input;

  std::cout << "How many players are playing: " << std::endl;
  cin >> amountOfPlayers;

  for(int i = 0; i < amountOfPlayers; i++) {
    std::cout << "Name of player number " << i << ": " << endl;
    std::cin >> name;
    player = Player(5, 0, 1, 1, 1, 9, 10, name);
    bg.addPlayer(name, player);
  }

  while(!takeTurn.hasPlayerWon()) {

    allPlayers = bg.getAllPlayers();

    for(std::map<string,J>::iterator it = allPlayers.begin(); it != allPlayers.end(); ++it) {
      std::cout << "Name: " << (it->second).getName() << endl;
      std::cout << "Gold: " << (it->second).Getgold() << endl;
      std::cout << "Ruby: " << (it->second).Getruby() << endl;
      std::cout << "Fabric: " << (it->second).Getfabric() << endl;
      std::cout << "Jewel: " << (it->second).Getjewel() << endl;
      std::cout << "Spice: " << (it->second).Getspice() << endl;
      std::cout << "Cart: " << (it->second).Getcart() << endl;
      std::cout << "Food: " << (it->second).Getfood() << endl;
      std::cout << " " << (it->second).getName() << endl;

      std::cout << "Type 'UP', 'DOWN', 'LEFT', or 'RIGHT' to move: " << std::endl;
      cin >> input;

      if(input == "UP") {
        move = UP;
      } else if(input == "DOWN") {
        move = DOWN;
      } else if(input == "LEFT") {
        move = LEFT;
      } else if(input == "RIGHT") {
        move = RIGHT;
      } else {
        move = RIGHT;
      }

      bg.move(move, )
    }

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
