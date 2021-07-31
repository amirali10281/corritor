//AP project 
//Fig : 2
//use ? for ap
//date : july , 21 , 2021
//amiraliamini 610399102 UT-CS-99

//=================================================================================

#include <iostream>
#include <string>
#include<vector>
#include <iomanip>
#include<cstdlib>
#include<stdlib.h>
using namespace std;
#include"board.h"

//----------------------------------------------------------------------------------

int main ()
{
    //enter number of players ;

    cout<<"enter the number of players please : ";
    int number ;
    cin>> number ; 

    //check for numver of players ; 

    while (number <2||number>4 )
    {
        cout << "Eror : \n| you can not play with your self or no-one or more than 4, try again : \n| | enter the number of players again: ";
        cin >> number ; 
    }

    // print number of players ; 

    cout << "there is "<< number << " of players in this game \n";
    
    //creat board of the game ; 

    board a (number);

    //first print for start ; 

    a.print () ;
    for (int p = 1 ;  p < number + 1  ; p++)
    {
        if (a.chekmid()!=0)
        {
            cout << "END\nwinner is number "<< a.chekmid() <<endl;
            return 0 ;
        }
        else 
        {
            char s ; int r ;int i =0 ; int j = 0;
            cout << "for play enter d and for wall w ... player number " <<p << " : \n";
            cin >>s;
            if (s=='d')
                cout << "for right ernter 0 , down 1 , left 2 and for up enter 3: \n";
            else 
                cout<<"0 for vertical and 1 for horizental and then enter the place : \n";
            cin>>r;
            if (s=='w')cin>>i>>j;
            if (s=='w')
            {
                //check for avalbility ; 

                if (a.chekwall(r,i,j)==true)
                {
                    a.play(p,s,r,i,j);
                    cout << "OK\n";
                }
                else 
                {
                    //for trying agin dicreasing number of player one time ; 

                    p--;
                    cout << "try again\n";
                }
            }
            else 
            {
                if (a.chek(p,r)==true )
                {
                    a.play(p,s,r,i,j);
                    cout << "OK\n";
                }
                else 
                {
                    p--;
                    cout << "try again\n";
                }
            }
        }
        //for loap ;
        if (p==number )
            p-=number ; 
    }
}