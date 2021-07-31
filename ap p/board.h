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

//----------------------------------------------------------------------------------

class board
{
public :
    board (int number )
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
        if (number == 4 )
        {
            players[1][0]=1;players[1][1]=1;players[2][0]=11;players[2][1]=11;players[3][0]=1;players[3][1]=11;players[4][0]=11;players[4][1]=1;
            arr[1][1]=1;arr[11][11]=2;arr[1][11]=3;arr[11][1]=4;
        }
        if (number == 3 )
        {
            players[1][0]=1;players[1][1]=1;players[2][0]=11;players[2][1]=11;players[3][0]=1;players[3][1]=11;
            arr[1][1]=1;arr[11][11]=2;arr[1][11]=3;
        }
        if (number == 2 )
        {
            players[1][0]=1;players[1][1]=1;players[2][0]=11;players[2][1]=11;
            arr[1][1]=1;arr[11][11]=2;
        }
        
        

    }

   void print ()
    {
        system("CLS");
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