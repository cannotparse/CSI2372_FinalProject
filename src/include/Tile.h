#ifndef TILE_H
#define TILE_H

#include "Player.h"
#include <stdlib.h> 

class Tile
{
    public:
        /** Default constructor */
        Tile();
        /** Default destructor */
        virtual ~Tile();

        bool operator == (const Tile &t);

        virtual bool action(Player& player);

        virtual Tile* clone();

    protected:
    private:
};

class DesertTile: public Tile {

public:
    bool action(Player& player){
        return false;
    }
};

class ResturantTile: public Tile {

public:
    bool action(Player& player) {
        player.Setfood(10);
        return true;
    }
};

class SpiceMerchantTile: public Tile {

public:
    bool action(Player& player) {
        // Take 2 gold from player
        player.Addgold(-2);
        // Checks the amount in the players cart and how much room thay have left
        unsigned int playerCartUsed = player.Getusedcartspace();
        unsigned int playerCartLimit = player.Getcart();
        unsigned int playerCartDiff = playerCartLimit - playerCartUsed;
        // Gives player the appropriate amount of spice
        if(playerCartDiff >= 3) {
            player.Addspice(3);
        } else {
            player.Addspice(playerCartDiff);
        }
        return true;
    }
};

class FabricManufacturer: public Tile {

public:
    bool action(Player& player) {
        // Take 2 gold from player
        player.Addgold(-2);
        // Checks the amount in the players cart and how much room thay have left
        unsigned int playerCartUsed = player.Getusedcartspace();
        unsigned int playerCartLimit = player.Getcart();
        unsigned int playerCartDiff = playerCartLimit - playerCartUsed;
        // Gives player the appropriate amount of fabric
        if(playerCartDiff >= 3) {
            player.Addfabric(3);
        } else {
            player.Addfabric(playerCartDiff);
        }
        return true;
    }
};

class JewwlerTile: public Tile {

public:
    bool action(Player& player) {
        // Take 2 gold from player
        player.Addgold(-2);
        // Checks the amount in the players cart and how much room thay have left
        unsigned int playerCartUsed = player.Getusedcartspace();
        unsigned int playerCartLimit = player.Getcart();
        unsigned int playerCartDiff = playerCartLimit - playerCartUsed;
        // Gives player the appropriate amount of jewelry
        if(playerCartDiff >= 3) {
            player.Addjewel(3);
        } else {
            player.Addjewel(playerCartDiff);
        }
        return true;
    }
};

class CartManufacturerTile: public Tile {

public:
    bool action(Player& player) {
    // Take 7 gold from player
    player.Addgold(-7);
    // Add 3 to capacity of players cart
    player.Addcart(3);
    return true;
    }
};

class SmallMarketTile: public Tile {

public:
    bool action(Player& player) {
        if(player.Getfabric() >= 1 && player.Getjewel() >= 1 && player.Getspice() >= 1) {
            // Takes stuff from players
            player.Addfabric(-1);
            player.Addjewel(-1);
            player.Addspice(-1);
            // Pays player
            player.Addgold(8);
            return true;
        } else {
            return false;
        }
    }
};

class SpiceMarketTile: public Tile {

public:
    bool action(Player& player) {
        if(player.Getspice() >= 3) {
            // Takes stuff from player
            player.Addspice(-3);
            // Pays player
            player.Addgold(6);
            return true;
        } else {
            return false;
        }
    }
};

class JewelMarketTile: public Tile {

public:
    bool action(Player& player) {
        if(player.Getjewel() >= 3) {
            // Takes stuff from player
            player.Addjewel(-3);
            // Pays player
            player.Addgold(6);
            return true;
        } else {
            return false;
        }
    }
};

class FabricMarketTile: public Tile {

public:
    bool action(Player& player) {
        if(player.Getspice() >= 3) {
            // Takes stuff from player
            player.Addspice(-3);
            // Pays player
            player.Addgold(6);
            return true;
        } else {
            return false;
        }
    }
};

class BlackMarketTile: public Tile {

public:
    bool action(Player& player) {
        // Takes money from player
        player.Addgold(-1);
        // Finds available space in cart
        unsigned int playerCartUsed = player.Getusedcartspace();
        unsigned int playerCartLimit = player.Getcart();
        unsigned int playerCartDiff = playerCartLimit - playerCartUsed;
        // If size of available cart space is above 5 then call giveItems
        // with specific bounds. 
        if(playerCartDiff >= 5) {
            giveItems(6, player);
        } 
        else {
            giveItems(playerCartDiff + 1, player);
        }
        return true;
    }

    void giveItems(int bounds, Player& player) {
        int amountToBeGiven = rand() % bounds;
        int randOption;
        for(int i = 0; i <= amountToBeGiven; i++) {
            randOption = rand() % 4;
            if(randOption == 0) {
                player.Addruby(1);
            } 
            else if(randOption == 1) {
                player.Addspice(1);
            }
            else if(randOption == 2) {
                player.Addfabric(1);
            }
            else if(randOption == 3) {
                player.Addjewel(1);
            }
            else {
                // If somehow the rand() function generates something outside
                // its bounds... The player might as well get 100 million gold
                player.Addgold(100000000);
            }
        }
    }
};

class CasinoTile: public Tile {

public:

    bool action(Player& player) {
        // Take gold from player
        player.Addgold(-1);
        // Get random number
        int randOption = rand() % 10;
        if(randOption == 0 || randOption == 4 || randOption == 7 || randOption == 9) {
            player.Addgold(0);
        }
        else if(randOption == 1 || randOption == 5 || randOption == 8) {
            player.Addgold(2);
        }
        else if(randOption == 2 || randOption == 6) {
            player.Addgold(3);
        }
        else if(randOption == 3) {
            player.Addgold(10);
        }
        return true;
    }
};

class GemMerchant: public Tile {

public: 
    GemMerchant(void) : price(12) {}

    bool action(Player& player) {
        if(player.Getgold() >= price) {
            player.Addgold(-price);
            player.Addruby(1);
            return true;
        } else {
            return fale;
        }
    }

private:
    int price;
};


#endif // TILE_
