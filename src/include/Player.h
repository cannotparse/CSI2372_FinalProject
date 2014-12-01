#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        /** Default constructor */
        Player(unsigned int _gold,
               unsigned int _ruby,
               unsigned int _fabric,
               unsigned int _jewel,
               unsigned int _spice,
               unsigned int _cart,
               unsigned int _food);

        bool canAct() const; // returns true if food > 0
        bool pay( Player& player );
        void eat(); // reduces food count by 1 if food > 0

        virtual ~Player();
        Player(const Player& other);

        unsigned int Getgold();
        void Setgold(unsigned int val);

        unsigned int Getruby();
        void Setruby(unsigned int val);

        unsigned int Getfabric();
        void Setfabric(unsigned int val);

        unsigned int Getjewel();
        void Setjewel(unsigned int val);

        unsigned int Getspice();
        void Setspice(unsigned int val);

        unsigned int Getcart();
        void Setcart(unsigned int val);

        unsigned int Getfood();
        void Setfood(unsigned int val);

    protected:
    private:
        unsigned int gold;
        unsigned int ruby;
        unsigned int fabric;
        unsigned int jewel;
        unsigned int spice;
        unsigned int cart;
        unsigned int food;
};

#endif // PLAYER_H
