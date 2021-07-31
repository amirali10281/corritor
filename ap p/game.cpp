//AP project 
//Fig : 1
//use ? for ap
//date : july , 21 , 2021
//amiraliamini 610399102 UT-CS-99

//=================================================================================

#include <iostream>
#include <string>
#include<vector>
#include <iomanip>
#include<cstdlib>
using namespace std;

//----------------------------------------------------------------------------------


class board
{
public :
    board ()
    {
        arr=new char *[13];
        for (int i =0 ; i < 13 ; i++)
        {
            arr[i]=new char [13];
        }
        for (int i = 0 ; i < 13 ;i++)
            for (int j = 0 ; j< 13 ; j++)
            {
                if (i==0 || i==12 || j==0 || j==12)
                    arr[i][j]='x';
                else
                    arr[i][j]='0' ;
            }
        players[1][0]=1;players[1][1]=1;players[2][0]=11;players[2][1]=11;players[3][0]=1;players[3][1]=11;players[4][0]=11;players[4][1]=1;
        arr[1][1]=1;arr[11][11]=2;arr[1][11]=3;arr[11][1]=4;

    }

   void print ()
    {
        for (int i = 0 ; i < 13 ;i++)
        {
            for (int j = 0 ; j< 13 ; j++)
            {
                if ((arr[i][j]==1||arr[i][j]==2||arr[i][j]==3||arr[i][j]==4))
                {
                    if (arr[i][j]==1)
                        cout << "A" <<"  ";
                    if (arr[i][j]==2)
                        cout << "B" <<"  ";
                    if (arr[i][j]==3)
                        cout << "C" <<"  ";
                    if (arr[i][j]==4)
                        cout << "D" <<"  ";
                }
                else     
                    cout << arr[i][j] <<"  ";
            }
            cout << endl ;
        }
    }

    int chekmid()
    {
        if (arr[6][6]=='0')
        {
            return 0 ; 
        }
        else 
        {
            for (int i = 1 ; i < 5 ; i++)
            {
                if (players[i][0]==6&&players[i][1]==6)
                {
                    return i;
                }
            }
        }
        return 0 ; 
    }

    bool chekwall (int r , int i , int j  )
    {
        if (r==1)
        {
            if ((arr[i][j]!='0'||arr[i-1][j]!='0'||arr[i+1][j]!='0'))
                return false;
        }
        else 
        {
            if ((arr[i][j]!='0'||arr[i][j-1]!='0'||arr[i][j+1]!='0'))
            return false ;
        }
        return true ; 
    }

    bool chek(int player , int r )
    {
        if (r==0)
        {
            if (arr[players[player][0]][players[player][1]+1]!='0')
                return false ; 
        }
        if (r==1)
        {
            if (arr[players[player][0]+1][players[player][1]]!='0')
                return false ; 
        }
        if (r==2)
        {
            if (arr[players[player][0]][players[player][1]-1]!='0')
                return false ; 
        }
        if (r==3)
        {
            if (arr[players[player][0]-1][players[player][1]]!='0')
                return false ; 
        }
        return true ;
    }
    void play(int player , char s , int r ,int i =0 , int j = 0  )
    {
        if (s=='w')
        {

            if (r==0)
            {
                arr[i][j-1] = arr[i][j] = arr[i][j+1]='x';
            }
            else
            {
                arr[i-1][j]=arr[i][j]=arr[i+1][j]='x';
            }
        }
        if (s=='d')
        {
            //cout <<players[p][0] << " " <<players[p][1]<<endl;
            if (r==0)
            {

                arr[players[player][0]][players[player][1]]='0';
                players[player][1]++;
                arr[players[player][0]][players[player][1]]=player;
            }
            if (r==1)
            {
                arr[players[player][0]][players[player][1]]='0';
                players[player][0]++;
                arr[players[player][0]][players[player][1]]=player;
            }
            if (r==2)
            {
                arr[players[player][0]][players[player][1]]='0';
                players[player][1]--;
                arr[players[player][0]][players[player][1]]=player;
            }
            if (r==3)
            {
                arr[players[player][0]][players[player][1]]='0';
                players[player][0]--;
                arr[players[player][0]][players[player][1]]=player;
            }
        }
        //cout <<players[p][0] << " " <<players[p][1]<<endl;
        print () ;
    }



private :
    char **arr ;
    int players [5][2];

};
int main ()
{
    cout<<"enter the number of players please : ";
    int number ;
    cin>> number ; 
    while (number <2||number>4 )
    {
        cout << "Eror : \n| you can not play with your self or no-one or more than 4, try again : \n| | enter the number of players again: ";
        cin >> number ; 
    }
    cout << "there is "<< number << " of players in this game \n";
    board a ;
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
                if (a.chekwall(r,i,j)==true)
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
        if (p==number )
            p-=number ; 
    }
}