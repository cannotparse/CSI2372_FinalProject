#include "Player.h"

bool Player::canAct() const{// returns true if food > 0
    return true;
}
bool Player::pay( Player& player ){
    if(gold>1){
        player.Addgold(1u);
        gold--;
        return true;
    }
    return false;
}
void Player::eat(){ // reduces food count by 1 if food > 0
}


Player::Player(unsigned int _gold,
               unsigned int _ruby,
               unsigned int _fabric,
               unsigned int _jewel,
               unsigned int _spice,
               unsigned int _cart,
               unsigned int _food)
               :
                gold(_gold),
                ruby(_ruby),
                fabric(_fabric),
                jewel(_jewel),
                spice(_spice),
                cart(_cart),
                food(_food)
{
    //ctor
}

Player::~Player()
{
    //dtor
}

Player::Player(const Player& other):
                gold(other.gold),
                ruby(other.ruby),
                fabric(other.fabric),
                jewel(other.jewel),
                spice(other.spice),
                cart(other.cart),
                food(other.food)
{
    //copy ctor
}
void Player::getCoords(int * _x, int * _y){
    *_x=x;
    *_y=y;
    return;
}
//Getters and Setters
        unsigned int Player::Getgold() { return gold; }
        void Player::Addgold(unsigned int val) { gold += val; }

        unsigned int Player::Getruby() { return ruby; }
        void Player::Addruby(unsigned int val) { ruby += val; }

        unsigned int Player::Getfabric() { return fabric; }
        void Player::Addfabric(unsigned int val) { fabric += val; }

        unsigned int Player::Getjewel() { return jewel; }
        void Player::Addjewel(unsigned int val) { jewel += val; }

        unsigned int Player::Getspice() { return spice; }
        void Player::Addspice(unsigned int val) { spice += val; }

        unsigned int Player::Getcart() { return cart; }
        void Player::Addcart(unsigned int val) { cart += val; }

        unsigned int Player::Getfood() { return food; }
        void Player::Setfood(unsigned int val) { food = val; }
        void Player::Addfood(unsigned int val) { food += val; }
