#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
    //freopen("in.text","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case %d:\n",i);
       stack<string>backd,fordw;
       string cur="http://www.lightoj.com/";
       string command;
       while(cin>>command)
       {
           if(command[0]=='Q')break;
          else if(command[0]=='V')
           {
               backd.push(cur);
               cin>>cur;
               cout<<cur<<endl;
               while(!fordw.empty())
               {
                   fordw.pop();
               }
           }
           else if(command[0]=='B')
           {
               if(backd.empty())
               {
                   puts("Ignored");
                   continue;
               }
               fordw.push(cur);
               cur=backd.top();
               backd.pop();
               cout<<cur<<endl;
           }
           else if(command[0]=='F')
           {
               if(fordw.empty())
               {
                   puts("Ignored");
                   continue;
               }
               backd.push(cur);
               cur=fordw.top();
               fordw.pop();
               cout<<cur<<endl;
           }

           }
       }
       return 0;
    }
