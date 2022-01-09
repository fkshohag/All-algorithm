# include <iostream>
# include <cstdio>
# include <cstring>
# include <deque>
# include <vector>
using namespace std;
int main()
{
    //freopen("in.text","r",stdin);
    deque<int>q;
    int t;
    cin>>t;
    int cases=0;
    while(t--)
    {
        q.clear();
        printf("Case %d:\n",++cases);
        int n,m;
        cin>>n>>m;
        while(m--)
        {
            string s;
            cin>>s;
            if(s=="pushLeft")
            {
                int val;
                cin>>val;
                if(q.size()==n)
                {
                    cout<<"The queue is full"<<endl;
                }
                else
                {
                    q.push_front(val);
                    printf("Pushed in left: %d\n",val);
                }
            }
           else if(s=="pushRight")
            {
                int val;
                cin>>val;
                if(q.size()==n)
                {
                    cout<<"The queue is full"<<endl;
                }
                else
                {
                    q.push_back(val);
                    printf("Pushed in right: %d\n",val);
                }
            }
            else if(s=="popLeft")
            {
                if(q.empty())
                {
                    cout<<"The queue is empty"<<endl;
                }
                else
                {
                  printf("Popped from left: %d\n",q.front());
                  q.pop_front();
                }
            }
            else if(s=="popRight")
            {
                if(q.empty())
                {
                    cout<<"The queue is empty"<<endl;
                }
                else
                {
                    printf("Popped from right: %d\n",q.back());
                  q.pop_back();
                }
            }
        }
    }
    return 0;
}
