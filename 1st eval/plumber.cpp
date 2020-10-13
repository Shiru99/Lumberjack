#include<iostream>
#include<cstring>

using namespace std;

struct tree
{
	int x,y,h,d,c,p,cut,posx,posy,pos1[1000];
};

int main(){
	int t,n,k,r=0,temp;	
	cin>>t;
	cin>>n;
	cin>>k;
	struct tree tr[k+1];
	//cout<<"tree details: "<<endl;
	tr[0].x=0;
	tr[0].y=0;

	for(int i=1;i<=k;i++)
	{
		cin>>tr[i].x;
		cin>>tr[i].y;
		cin>>tr[i].h;
		cin>>tr[i].d;
		cin>>tr[i].c;
		cin>>tr[i].p;
		tr[i].cut = 0;
	}

	/*for(int i=1;i<=k;i++)
	{
		r=0;*/
	int i=1;
	int p=0;
	while(p<k)
	{
		for(int j=1;j<=k;j++)
		{

			tr[i].posx= abs(tr[i].x - tr[j].x);
			tr[i].posy = abs(tr[i].y - tr[j].y);
			tr[i].pos1[r] = tr[i].posx + tr[i].posy ;
			r++;
		}
		for(int t=0;t<k;t++)
		{
			for(int t1=0;t1<k;t1++)
			{
				if(tr[i].pos1[t]  < tr[i].pos1[t1])
				{
					temp = tr[i].pos1[t];
					tr[i].pos1[t] = tr[i].pos1[t1];
					tr[i].pos1[t1] = temp;
				}
			}
		}
		p++;
	}
	for(int t2=0; t2<k; t2++)
		{
			if(i==1)
			{
				printf("%d\n",tr[i].pos1[1]);
			}			
			else 
			printf("%d\n",tr[i].pos1[t2]);
		}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<k;j++)
		{
			if(tr[i].pos1[1] == tr[j].posx)
			{
				printf("%d\n",tr[j].x);
				printf("%d\n",tr[j-1].x);
				for(int t1=0;t1<(tr[j].x-tr[j-1].x);t1++)
				{
					printf("move right\n");
				}
				/*for(int t1l=0;t1l<(tr[j-1].x-tr[j].x);t1l++)
				{
					printf("move left\n");
				}*/
				printf("%d\n",tr[j].y);
				printf("%d\n",tr[j-1].y);
				for(int t2=0;t2<(tr[j].y-tr[j-1].y);t2++)
				{
					printf("move up\n");
				}
				/*for(int t2d=0;t2d<(tr[j-1].y-tr[j].y);t2d++)
				{
					printf("move down\n");
				}*/
				break;

			}
		}
	}
}