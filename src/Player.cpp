#include "Player.h"

bool canAct() const{// returns true if food > 0

}
bool pay( Player& player ){

}
void eat(){ // reduces food count by 1 if food > 0

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

//Getters and Setters
        unsigned int Player::Getgold() { return gold; }
        void Player::Setgold(unsigned int val) { gold = val; }

        unsigned int Player::Getruby() { return ruby; }
        void Player::Setruby(unsigned int val) { ruby = val; }

        unsigned int Player::Getfabric() { return fabric; }
        void Player::Setfabric(unsigned int val) { fabric = val; }

        unsigned int Player::Getjewel() { return jewel; }
        void Player::Setjewel(unsigned int val) { jewel = val; }

        unsigned int Player::Getspice() { return spice; }
        void Player::Setspice(unsigned int val) { spice = val; }

        unsigned int Player::Getcart() { return cart; }
        void Player::Setcart(unsigned int val) { cart = val; }

        unsigned int Player::Getfood() { return food; }
        void Player::Setfood(unsigned int val) { food = val; }
