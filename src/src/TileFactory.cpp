#include "TileFactory.h"
#include <cmath>
#include <iostream>
#include <random>
#include <algorithm>



Tile* maker(unsigned int j){
    switch (j){
        case 0:
        	DesertTile tile();
            return tile;// Desert
        case 1:
        	ResturantTile tile();
            return tile;// Restaurant
        case 2:
        	SpiceMerchantTile tile();
            return tile;// spice merchant
        case 3:
        	FabricManufacturerTile tile();
            return tile;// fabric man
        case 4:
        	JewelerTile tile();
            return tile;// jeweler
        case 5:
        	CartManufacturerTile tile();
            return tile;// cart man
        case 6:
        	SmallMarketTile tile();
            return tile;// small market
        case 7:
        	SpiceMarketTile tile();
            return tile;// spice market
        case 8:
        	JewelMarketTile tile();
            return tile;// jewelry market
        case 9:
        	FabricMarketTile tile();
            return tile;// fabric market
        case 10:
	        BlackMarketTile tile();
            return tile;// black market
        case 11:
        	CasinoTile tile();
            return tile;// casion
        case 12:
        	GemMerchantTile tile();
            return tile;// gem merhcant
        case 13:
        	PalaceTile tile();
            return tile;// palace
    }
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
    return 0;//tiles.pop_back();
}
