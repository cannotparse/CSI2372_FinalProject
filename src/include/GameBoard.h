#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "TileFactory.h"


template<class T, class J, unsigned int N> class GameBoard
{
    private:
            std::map<string,J> pMap;
            std::vector<std::vector<const T&>> tVec;
            TileFactory tf;
    public:
        enum Move {UP, DOWN, LEFT, RIGHT};
        /** Default constructor */
        GameBoard():tf(TileFactory.get()){}
        /** Default destructor */
        virtual ~GameBoard() {}
        /** Copy constructor
         *  \param other Object to copy from
         */
        GameBoard(const GameBoard& other) {}

        void add(const T& tile, int row, int col){

        }

        const T& getTile(int row, int col) const{
            return tVec[row][col];
        }
        void getCoordinate(const T &tile, int *row, int *col) const{
            for(int i =0; i<tVec.length){
                for(int j = 0;j<tVec[i].length;j++){
                    if(tile == tVec[i][j]){
                        row=i;
                        col=j;
                        return;
                    }
                }
            }
            return;
        }
        void setPlayer(J player){

        }
        J getPlayer(const std::string& playerName){
            return pMap.find(playerName);
        }
        const T& getTile(const std::string& playerName) const{
            pMap.find(playerName).getCoords()
        }
        std::vector<J> getPlayers(const T& tile) const{
            return tile.getPlayers();
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
