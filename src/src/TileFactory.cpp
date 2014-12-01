#include "TileFactory.h"
#include <cmath>
#include <iostream>
#include <random>
#include <algorithm>



Tile* maker(unsigned int j){
    Tile tile;
    switch (j){
        case 0:
            break;
        case 1:

            tile = ResturantTile();// Restaurant
            break;
        case 2:
            tile = SpiceMerchantTile();// spice merchant
            break;
        case 3:
            tile = FabricManufacturerTile();// fabric man
            break;
        case 4:
            tile = JewelerTile();// jeweler
            break;
        case 5:
            tile = CartManufacturerTile();// cart man
            break;
        case 6:
            tile = SmallMarketTile();// small market
            break;
        case 7:
            tile = SpiceMarketTile();// spice market
            break;
        case 8:
            tile = JewelMarketTile();// jewelry market
            break;
        case 9:
            tile = FabricMarketTile();// fabric market
            break;
        case 10:
            tile = BlackMarketTile();// black market
            break;
        case 11:
            tile = CasinoTile();// casion
            break;
        case 12:
            tile = GemMerchantTile();// gem merhcant
            break;
        case 13:
            tile = PalaceTile();// palace
            break;
    }
    Tile* t = &tile;
    return t;
}

TileFactory::TileFactory(int& _ntiles):ntiles(_ntiles)
{

    const int range_from  = 0;
    const int range_to    = 13;
    std::random_device rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);

    unsigned int t[14];
    unsigned int t2 = floor(ntiles/14);
    unsigned int i;
    for(i = 0; i<14; i++){
        t[i]= t2;
    }
    unsigned int t3 =ntiles-(t2*14);
    unsigned int t4;
    while(t3>0){
        t4= distr(generator);
        if(t[t4]<(t2+1)){
            t[t4]++;
            t3--;
        }
    }
    i=0;
    for(unsigned int j =0; j<14u;j++){
    for(;i<t[j];i++){
        tiles.push_back(maker(j));
    }
    }
    std::random_shuffle (tiles.begin(), tiles.end());
}

TileFactory::~TileFactory()
{
    //dtor
}

Tile* TileFactory::next(){
    Tile * tile = tiles.back();
    return tile;
}
