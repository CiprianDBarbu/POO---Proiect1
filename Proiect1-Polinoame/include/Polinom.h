#ifndef POLINOM_H
#define POLINOM_H

#include <iostream>

using namespace std;

class Polinom
{
    public:
        Polinom();
        Polinom(int);
        Polinom(const Polinom &a);
        ~Polinom();

        friend istream& operator>>(istream& in,Polinom& a);
        friend ostream& operator<<(ostream& out,const Polinom& a);

        int val_pct(int);
        int grade();
        void adaug_termen(int g , int c);                                  //se va da gradul termenului dorit si coef termenuli nou
        void elimin_termen(int g);                                         //se va da gradul termenului pe care dorim sa il stergem

        void operator=(const Polinom &a);
        Polinom operator+(const Polinom &a);
        Polinom operator-(const Polinom &a);
        Polinom operator[](int i);
        Polinom operator*(const Polinom &a);
        Polinom operator*(int x);
        Polinom operator/(const Polinom &a);




    protected:

    private:
        int grad;
        int *coef;
};

#endif // POLINOM_H
