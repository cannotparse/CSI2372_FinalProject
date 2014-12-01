#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "TileFactory.h"


template<class T, class J, unsigned int N> class GameBoard
{

    public:
        enum Move {UP, DOWN, LEFT, RIGHT};
        /** Default constructor */
        GameBoard() {}
        /** Default destructor */
        virtual ~GameBoard() {}
        /** Copy constructor
         *  \param other Object to copy from
         */
        GameBoard(const GameBoard& other) {}

        void add(const T& tile, int row, int col){

        }

        const T& getTile(int row, int col) const{

        }
        void getCoordinate(const T &tile, int *row, int *col) const{

        }
        void setPlayer(J player){

        }
        J getPlayer(const std::string& playerName){

        }
        const T& getTile(const std::string& playerName) const{

        }
        std::vector<J> getPlayers(const T& tile) const{

        }
        const T& move(Enum Move move, const std::string& playerName ) {

            try {
                T& currentTile = getTile(playerName);
                int x, y;
                void currentCoords = getCoordinate(currentTile, *x, *y);
                switch(move) {
                    case UP:
                        y--;
                        break;
                    case DOWN:
                        y++;
                        break;
                    case LEFT:
                        x--;
                        break;
                    case RIGHT:
                        x++;
                        break;
                }
                return getTile(x, y);
            } 
            // catch ( *** Find Error Type *** ) {
            //     add(tf.next(), x, y);
            // }

        }

    protected:
    private:
};

#endif // GAMEBOARD_H
