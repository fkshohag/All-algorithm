#include <bits/stdc++.h>
#define Mx 50

using namespace std;


struct Process
{
    int id;
    int At;
    int Bt;
    int Ct;
    int Wt;
    int Rt;
    int Tat;

    void P(){};

    void print()
    {
        cout<<"Process ID = "<<id<<" AT = "<<At<<" BT = "<<Bt<<" Rt = "<<Rt<<" CT = "<<Ct<<" WT = "<<Wt<<" TAT = "<<Tat<<endl;
    }
};

Process P[Mx];

/// FCFS       /// Priority Scheduling


/// SJF
bool operator < (const Process& A, const Process& B )
{
   return A.Bt > B.Bt;
}

/// FCFS
vector<Process>Tim[100000];

priority_queue<Process>Q;
vector<Process>Serial;

int main()
{
    freopen("in.text", "r", stdin);
    int numberOfprocess,x,y;
    /*
    4
    0 8
    1 4
    2 9
    3 5

    4
    0 6
    0 8
    0 7
    10 3


    */

//    0 1 2 3


    cin>>numberOfprocess;
    for(int i = 1; i <= numberOfprocess; i++)
    {
        scanf("%d %d",&P[i].At,&P[i].Bt);
        P[i].id = i;
        Tim[P[i].At].push_back(P[i]);
       /// Q.push(P[i]);
    }

    int RemTime = 0;
    Process tmp;

    for(int i=0;i<=10000;i++)
    {
        if(Tim[i].size())
        {
            for(int j=0;j<Tim[i].size();j++)
            {
                Q.push(Tim[i][j]);
            }
        }

        /// CPU faka thakle, Q theke Process nibe.

        ///

        if(RemTime == 0)
        {
            if(!Q.empty())
            {
                tmp=Q.top();
                Q.pop();
                tmp.Rt = i;
                tmp.Ct= tmp.Rt + tmp.Bt;
                tmp.Wt= tmp.Ct - tmp.At - tmp.Bt;
                tmp.Tat = tmp.Ct - tmp.At;
                RemTime = tmp.Bt;
                Serial.push_back(tmp);
            }
        }

        if(RemTime > 0) RemTime--;

        /// Otherwise, je Process CPU te ase seta cholbe.
    }

    for(int i=0;i<Serial.size();i++)
    {
        Serial[i].print();
    }

}

/*

4
0 2
1 2
6 10
7 5


4
0 6
0 8
0 7
0 3'


3
0 7
10 12
15 3

*/


