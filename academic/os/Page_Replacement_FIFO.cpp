#include <bits/stdc++.h>
#define Mx 50

using namespace std;

        /// [4] [ 20 ] freame ki obostha ?

int Frame[6][20];

int input[20];


int main()
{
    int numberOfprocess,x,y;


    cin>>numberOfprocess;


    for(int i=1;i<=numberOfprocess;i++)
    {
        cin>>input[i];

    }


    memset(Frame,-1,sizeof Frame);

    for(int i=1;i<=4;i++)
    {
        cout<<"|";
        for(int j = 0;j<=16;j++)
        {
            cout<<Frame[i][j]<<"|";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<endl;

    int hitCount = 0,nextFaka=1;
    for(int i=1;i<=numberOfprocess;i++)
    {
        int p = input[i];

        /// p ki frame gular vitor ase naki nai ?

        bool hit = false;

        for(int j=1;j<=4;j++)
        {
            if( p == Frame[j][i-1] )
            {
                hit = true;
            }
        }

        /// Ekhon dekhbo faka ase ki na!

        for(int j=1;j<=4;j++)
            {
                Frame[j][i] = Frame[j][i-1];
            }


        if(hit)hitCount++;
        else /// memoryte 1 ta frame faka korbo.
            /// sekhane, ei process add korbo.
        {

            bool fakaAse = 0;

            for(int j=1;j<=4;j++)
            {
                if( Frame[j][i] == -1 )
                {
                    fakaAse = true;
                    Frame[j][i] = p;
                    break;
                }
            }

            /// puraton process khuje ber korte hobe.
            /// Konta Bad dibo sei logic eikhane ase!!!!
            if(fakaAse==false)
            {
                Frame[nextFaka][i] = p;
                nextFaka++;
                if(nextFaka==5)nextFaka = 1;
                if(nextFaka>4)nextFaka = 1;
            }
            /// Homework for Least Recently Used (LRU)
        }

    }

    for(int i=1;i<=4;i++)
    {
        cout<<"|";
        for(int j = 0;j<=16;j++)
        {
            cout<<Frame[i][j]<<"|";
        }
        cout<<endl;
    }

    cout<<"Total Hit = "<<hitCount<<endl;
    cout<<"Total Miss= "<<16- hitCount<<endl;




}

/*

16
1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 0

*/


