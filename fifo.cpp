#include<iostream>
using namespace std;

int n,nf;
int p[50],in[100];
int hit=0,pgfaultcnt=0,hitcnt=0;
int i,j,k;

void intialize() 
{
	pgfaultcnt=0;
	for(int k=0;k<nf;k++)
	{
		p[k]=999;
	}
}

void dispages()
{
	for(int k=0;k<nf;k++)
	{
		if(p[k]!=9999)
		{
			cout<<p[k]<<" ";
		}
	}
}
int isHit(int data)
{
	hit=0;
	for(int j=0;j<nf;j++)
	{
		if(p[j]==data)
		{
			hit=1;
			break;
		}
	}
	return hit;
}
void dispgfault()
{
	cout<<"\nTotal No. of Page Faults: "<<pgfaultcnt;
}
void dispghit()
{
	for(int i=0;i<n;i++)
	{
		hitcnt = n - pgfaultcnt;
	}
	cout<<"\nTotal No. of Page Hits: "<<hitcnt;
}

void fifo()
{
	intialize();
	for(int i=0;i<n;i++)
	{
		cout<<"\nFor "<<in[i]<<": ";
		// 0 - page fault
		/// 1 - page hit
		if(isHit(in[i])==0) // check whether data is present in stack or not
		{
		    for(k=0;k<nf-1;k++)
		    {
			    p[k]=p[k+1];
		    }// k = nf//
		p[k]=in[i];
		pgfaultcnt++;
		dispages();
		cout<<" ";	
		}
		else
		{
			cout<<"No Page Fault!";
		}	
	}
	dispgfault();
	dispghit();
	
}

int main()
{
	cout<<"\nEnter the Length of the referenced string: ";
	cin>>n;
	cout<<"\nEnter the Referenced string elements: ";
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	cout<<"\nEnter the number of frames: ";
	cin>>nf;
	fifo();
	}
