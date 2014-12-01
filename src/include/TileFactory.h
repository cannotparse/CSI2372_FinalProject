#ifndef TILEFACTORY_H
#define TILEFACTORY_H
#ifndef TILE_H
#include "Tile.h"
#endif //TILE_H
#ifndef VECTOR_H
#include <vector>
#endif // VECTOR_H
#ifndef STRING_H
#include <string>
#endif // STRING_H


class TileFactory
{
    private:
        int ntiles;
        std::vector<Tile*> tiles;
    protected:
        TileFactory(int& nTiles);
    public:
        /** Default constructor */

        /** Default destructor */
        virtual ~TileFactory();
        static TileFactory *get(int _nTiles) {
          static TileFactory tf(_nTiles);
          return &tf;
        }
        Tile* next();
    protected:
    private:
};

#endif // TILEFACTORY_H
