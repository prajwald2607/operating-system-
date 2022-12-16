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

void LRU()
{
	intialize();
	int least[50];
	
	for(int i=0;i<n;i++)
	{
		cout<<"\nFor "<<in[i]<<": ";
		
		if(isHit(in[i])==0)
		{
			for(int j=0;j<nf;j++)
			{
				int pg=p[j];
				int found=0;
				for(int k=i-1;k>=0;k--)
				{
					if(pg==in[k])
					{
						least[j]=k;
						found=1;
						break;
					}
					else
					{
						found=0;
					}
				}
				if(!found)
				{
					least[j]=-9999;
				}
			}
			int min=9999;
			int repindex;
			for(int j=0;j<nf;j++)
			{
				if(least[j]<min)
				{
					min=least[j];
					repindex=j;
				}
			}
			p[repindex]=in[i];
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
	LRU();
	}
