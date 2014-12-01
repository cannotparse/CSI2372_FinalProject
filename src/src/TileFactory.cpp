#include "TileFactory.h"
#include <cmath>
#include <iostream>
#include <random>
#include <algorithm>



Tile* maker(unsigned int j){
    switch (j){
        case 0:
                return 0;// Desert
        case 1:
                return 0;// Restaurant
        case 2:
            return 0;// spice merchant
        case 3:
            return 0;// fabric man
        case 4:
            return 0;// jeweler
        case 5:
            return 0;// cart man
        case 6:
            return 0;// small market
        case 7:
            return 0;// spice market
        case 8:
            return 0;// jewelry market
        case 9:
            return 0;// fabric market
        case 10:
            return 0;// black market
        case 11:
            return 0;// casion
        case 12:
            return 0;// gem merhcant
        case 13:
            return 0;// palace
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
