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

        void getCoords(int * _x, int * _y);

        int setX(int _x);
        int setY(int _y);

        unsigned int Getgold();
        void Addgold(unsigned int val);

        unsigned int Getruby();
        void Addruby(unsigned int val);

        unsigned int Getfabric();
        void Addfabric(unsigned int val);

        unsigned int Getjewel();
        void Addjewel(unsigned int val);

        unsigned int Getspice();
        void Addspice(unsigned int val);

        unsigned int Getcart();
        void Addcart(unsigned int val);

        unsigned int Getfood();
        void Setfood(unsigned int val);
        void Addfood(unsigned int val);

        unsigned int Getusedcartspace();
        unsigned int Addusedcartspace(unsigned int val);

    protected:
    private:
        int x;
        int y;
        unsigned int gold;
        unsigned int ruby;
        unsigned int fabric;
        unsigned int jewel;
        unsigned int spice;
        unsigned int cart;
        unsigned int food;
        unsigned int usedCartSpace;
};

#endif // PLAYER_H
