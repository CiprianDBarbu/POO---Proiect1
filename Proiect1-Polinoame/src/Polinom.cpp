#include "Polinom.h"
#include <stdexcept>
#include <exception>
#include <math.h>

Polinom::Polinom()
{
    grad = 0;
    coef = new int[grad];
    coef[grad] =0;
}

Polinom::Polinom(int n)
{
    try
    {
        if(n < 0)
            throw n;
        grad = n;
        coef = new int [grad+1];
        for(int i=0;i<=grad;i++)coef[i]=0;
    }
    catch (int n)
    {
        cerr<<"Error_1!"<<'\n';
    }
}

Polinom::Polinom(const Polinom &a)
{
    grad = a.grad;
    for(int i=grad ;i>=0 ;i--)coef[i] = a.coef[i];
}

Polinom::~Polinom()
{
    delete []coef;
}

//metoda care intoarce ca int valoarea polinomului in punctul dat x
int Polinom::val_pct(int x)
{
    int aux=0;
    for(int i=grad; i>0; i--)
        aux = aux + coef[i] * pow(x,i);
    aux = aux+ coef[0];

    return aux;
}

//metoda care intoarce ca int gradul polinomului
int Polinom::grade()
{
    return grad;
}

//metoda ce intoarce polinomul inital caruia i se adauga un nou element
//g reprezinta gradul elementului pe care il adaugam ; c reprezinta coeficientul acestuia
void Polinom::adaug_termen(int g, int c)
{
        if(g > grad)        //in cazul in care elementul adaugat are gradul mai mare decat al polinomului actual seva mari gradul si restule elmentelor pana acolo vor avea coeficientul 0
        {
            int gr_vechi = grad;
            grad = g;
            for(int i=gr_vechi+1 ; i<grad ; i++)
                coef[i] = 0;
            coef[grad] = c;
        }
        else
        {
            if(coef[g] == 0)
                coef[g] = c;
        }
}

//metoda ce elimina termenul de grad g din polinom
void Polinom::elimin_termen(int g)
{

    if(g == grad)
    {
        coef[g] =0;
        grad--;
    }
    else
        {
        if(g < grad)
        coef[g] = 0;
        }

}

void Polinom::operator= (const Polinom &a)
{
    grad = a.grad;
    for (int i=a.grad; i>=0 ; i--)
        coef[i] = a.coef[i];
}

//supraincarcarea operator + va intoarce un polinom de grad max(a,b)
Polinom Polinom::operator+ (const Polinom &a)
{
    int maxi;       //maximul dintre cele doua grade pentru a aloca polinomul adiacent
    if(grad > a.grad)maxi=grad;
    else maxi=a.grad;

    Polinom b(maxi);

    if(grad > a.grad)
        {
            for(int i=b.grad ; i>=0 ; i--)
            if(i<=a.grad)b.coef[i] = coef[i] + a.coef[i];
                else b.coef[i] = coef[i];

        }
    else
        {
            for(int i=b.grad ; i>=0 ; i--)
            if(i<=grad)b.coef[i] = coef[i] + a.coef[i];
                else b.coef[i] = a.coef[i];
        }
        return b;
}

//se va intoarce un polinom ce are gradul i
//Singurul element va fi cel de grad i impreuna cu coeficientul sau
//Restul elementelor au grad 0
Polinom Polinom::operator[] (int i)
{
    Polinom b(i);

    b.coef[b.grad] = coef[i];
    for(int j=b.grad-1 ; j>=0; j--)
        b.coef[j] =0;

    return b;
}


Polinom Polinom::operator*(const Polinom &a)
{
    Polinom b(grad + a.grad);

    for(int i=b.grad; i>=0; i--)        //initializez gradele polinomului in care se calculeaza produsul pentru a putea calcula coeficientii
        b.coef[i] =0;

    for(int i=grad ; i>=0; i--)
        for(int j=a.grad ; j>=0 ; j--)
            b.coef[i+j] = b.coef[i+j] + coef[i] * a.coef[j];

    return b;
}

Polinom Polinom::operator*(const int x)
{
    Polinom b(grad);

    for(int i=grad ; i>=0; i--)
        b.coef[i] =x * coef[i];

    return b;
}

//impartirea foloseste "metoda scaritei"
//impartirea va functiona doar daca grad > a.grad
Polinom Polinom::operator/ (const Polinom &a)
{

    Polinom m(grad),n(a.grad),c(grad-a.grad);       //c este catul

        for(int i=m.grad ; i>=0 ;i--)m.coef[i] = coef[i];       //m este copie a polinomul de impartit
        for(int i=n.grad ; i>=0 ;i--) n.coef[i] = a.coef[i];    //n e copie a polinomului impartitor

    int k=c.grad;       //k parcurge elementele catului

    for(int i=m.grad ; i>=0;i--)
    {
        c.coef[k] = m.coef[i] / n.coef[n.grad];  //calculeaza gradul fiecarui element al catului
        for(int j=n.grad ; j>=0;j--)
        m.coef[j+k] = m.coef[j+k] - n.coef[j] * c.coef[k];      //se scade din polinomul de impartit coeficientii conform formulei
        k--;
        if(k<0)break;       //algoritmul se opreste cand gradul lui c ajunge la 0
    }

    return c;


}
