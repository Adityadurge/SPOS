#include <iostream>
using namespace std;

template <class t>
class Queue{
    t * arr;
    int n;
    int f,r;
public:
    Queue()
    {

    }
    Queue(int n) : f(-1), r(-1), n(n) {
          arr = new t[n];
      }

    bool is_empty()
    {
        return (f==-1)?true:false;
    }
    bool is_full()
    {
        return ((r+1)%n==f)?true:false;
    }
    void push(t data)
    {
        if(is_full())
        {
            cout<<"Queue is full"<<endl;
        }
        else
        {
            if(f==-1)
            {
                f++;
            }
            r=(r+1)%n;
            arr[r]=data;

        }
    }
    void display()
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i];
        }
    }
    t pop()
    {
        if(is_empty())
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            t result=arr[f];
            if(f==r)
            {
                f=r=-1;
            }
            else
            {
                f=(f+1)%n;
            }
            return result;

        }
    }

};
class process{
    int pid, at, bt, ct, tat, wt,bt1;
    public:

    process()
    {
        at=bt=ct=tat=wt=0;
    }
    void setprocess()
    {
        cout<<"Enter Arival time :-";
        cin>>at;
        cout<<"Enter Brust time :-";
        cin>>bt;
        cout<<endl;
        bt1=bt;
    }
    void getprocess()
    {
        cout<<"Process Id :- "<<pid<<endl;
        cout<<"Arival Time :- "<<at<<endl;
        cout<<"Brust Time :- "<<bt<<endl;
        cout<<"completion Time :- "<<ct<<endl;
        cout<<endl;
    }
    friend class sheduler;
};
class sheduler
{

    process **arr;
    int n;
    int ts;
    Queue<int> rq;



    public:
    sheduler() : rq(10) {
    	ts=10;

       }
    void setprocess()
    {

        cout<<"Enter No of Process :-";
        cin>>n;
        arr=new process*[n];
        for(int i=0;i<n;i++)
        {
        	arr[i]=new process;
        }
        for(int i=0;i<n;i++)
        {
            arr[i]->pid=i+1;
            arr[i]->setprocess();
        }
    }
    void getprocess()
    {
        for(int i=0;i<n;i++)
        {
            arr[i]->getprocess();
        }
    }

    void insert(int t)
    {
    	      for(int i=0;i<n;i++)
    	      {
    	    	  if(arr[i]->at==t)
    	    	  {
    	    		rq.push(i);
    	    	  }
    	      }
    }

    void Rr()
    {
      int count=0;
      insert(0);
     while(!rq.is_empty())
     {

    	 	 int i=rq.pop();

    	 	 while(arr[i]->bt!=0)
    	 	 {count++;
    	 		 arr[i]->bt-=1;
    	 		 arr[i]->ct=count;
    	 		insert(count);

    	 	 }

     }
    	float ttat=0;
    	float twt=0;
    	 for(int i=0;i<n;i++)
    	 {
    		 arr[i]->tat=arr[i]->ct-arr[i]->at;
    		 ttat+=arr[i]->tat;
    		 arr[i]->wt=arr[i]->tat-arr[i]->bt1;
    		 twt+=arr[i]->wt;
    	 }

    	 ttat=ttat/n;
    	 twt=twt/n;
    	 cout<<endl;
    	 cout<<"avg TAT :-"<<ttat<<endl;
    	 cout<<"avg WT :- "<<twt<<endl;

    }
};
int main()
{

    sheduler s;
    s.setprocess();

    s.Rr();
    s.getprocess();

    return 0;

}
