#include <bits/stdc++.h>
#define Mx 50

using namespace std;

int AT[Mx];
int BT[Mx];
int RT[Mx];
int CT[Mx];
int WT[Mx];
int TAT[Mx];

int main()
{
    // freopen("in.text", "r", stdin);

    int numberOfprocess;
    cin>>numberOfprocess;

    for(int i = 1; i <= numberOfprocess; i++)
    {
        scanf("%d%d", &AT[i], &BT[i]);
    }

    for(int i = 1; i <= numberOfprocess; i++)
    {
        RT[i] = max(CT[i-1], AT[i] );
        CT[i] = RT[i] + BT[i];
        WT[i] = CT[i] - AT[i] - BT[i];
        TAT[i] = CT[i] - AT[i];
    }


    for(int i = 1; i <= numberOfprocess; i++)
    {
        cout<<setw(4)<<"Process #"<<i<<": ";
        cout<<setw(4)<<" AT = "<<AT[i];
        cout<<setw(4)<<" BT = "<<BT[i];
        cout<<setw(4)<<" RT = "<<RT[i];
        cout<<setw(4)<<" CT = "<<CT[i];
        cout<<setw(4)<<" WT = "<<WT[i];
        cout<<setw(4)<<" TAT = "<<TAT[i]<<endl;

     }

     int totalWatingTime = 0, totalTimeAroundTime = 0;

     for (int i = 1; i <= numberOfprocess; i++)
     {
         totalWatingTime += WT[i];
         totalTimeAroundTime += TAT[i];
     }

     float avarageWaitingTime, avarageTimeAroundTime;

     avarageWaitingTime = (float) totalWatingTime / numberOfprocess; 
     avarageTimeAroundTime = (float) totalTimeAroundTime / numberOfprocess;

     printf("Average waiting time: %f\nAverage time around time: %f\n", avarageWaitingTime, avarageTimeAroundTime);
}

/*
3
0 7
10 12
15 3

*/


