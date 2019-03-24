/*
Toate testele pe care umreaza sa le sugerez vor avea la baza polinoamele
a = 12x^4-6x^3+2x+7 si
b = 3x^2+2
*/
#include <iostream>
#include "Polinom.h"
#include <cassert>

using namespace std;

istream& operator>>(istream& in,Polinom& a)
{
    for(int i=a.grad; i>= 0; i--)
        in>>a.coef[i];

    return in;
}

ostream& operator<<(ostream& out,const Polinom &a)
{

   if(a.coef[a.grad]>1) out<<a.coef[a.grad]<<"x^"<<a.grad;
   if(a.coef[a.grad]==1)out<<"x^"<<a.grad;
    for(int i=a.grad-1; i>=0 ;i--)
    {
        if(i>=2){
                if(a.coef[i]>1)out<<"+"<<a.coef[i]<<"x^"<<i;
                else if(a.coef[i]==1)out<<"+x^"<<i;
                else if(a.coef[i]<0) out<< a.coef[i]<<"x^"<<i;
                }
        else
        {
            if(i==1)
                {
                if(a.coef[i]>0)out<<"+"<<a.coef[i]<<"x";
                else if(a.coef[i]==1)out<<"+x"<<i;
                else if(a.coef[i]<0)out<< a.coef[i]<<"x";
                }
            if(i==0)
            {
                if(a.coef[i]>0)out<<"+"<<a.coef[i];
                else if(a.coef[i]<0)out<< a.coef[i];
            }
        }
    }

/*
    for(int i=a.grad; i>=0;i--)
    {
        if(i!=a.grad)
          {
            if(a.coef[i]!=0)
           {
            if(a.coef[i]>0){
                            if(a.coef[i]!=1)out<<"+"<<a.coef[i]<<"x^"<<i;
                            else out<<"+x^"<<i;
                            }
            else if(a.coef[i]<0)out<<a.coef[i]<<"x^"<<i;
            }
          }
          else out<<a.coef[i]<<"x^"<<i;

    }

   */

   //for(int i=a.grad; i>=0;i--)out<<" +"<<a.coef[i]<<"x^"<<i;


    return out;

}

int main()
{
    Polinom a(4),b(2);
    cout<<"a:";
    cin>>a;
    cout<<"Polinomul a este:"<<a<<endl;
    cout<<"b:";
    cin>>b;
    cout<<"Polinomul b este:"<<b<<endl;

    assert(a.val_pct(3) == 823);
    cout<<endl<<"Val a in pct 3 este:"<<a.val_pct(3)<<endl;

    cout<<"a+b = "<<a+b;        //polnomul rezultat trebuie sa fie 12x^4-6x^3+3x^2+2x+9
    cout<<endl;


    cout<<"a[1]="<<a[1];        //polinomul rezultat este 2x
    cout<<endl;

    cout<<"a*b = "<<a*b;        //polinomul rezultat este 36x^6-18x^5+24x^4-6x^3+21x^2+4x+14
    cout<<endl;

    cout<<"a*3 ="<<a*3<<endl;       //polinomul ce trebuie afisat este 36x^4-18x^3+6x+21

    Polinom test;
    test=b;
    test.adaug_termen(1,7);
    cout<<"Test:"<<test<<endl;       //test=3x^2+7x+2

    test.elimin_termen(1);
    cout<<"Test:"<<test<<endl;      //test=3x^2+2

    assert(a.grade()==4);
    cout<<"Gradul lui a este:"<<a.grade()<<endl;

    cout<<"a/b= "<<a/b<<endl;       //catul impartirii lui a la b este 4x^2-2x-2

    cout<<endl<<"___TESTAT CORECT___"<<endl;
    return 0;
}
