#include<iostream>
#include<cstring>
#include<vector>

using namespace std;


struct tree
{
	int x,y,h,d,c,p;
	int cut;
};


int cut_up(tree *tr,int index,int k,int ok)
{
	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++)
	{
		if(tr[i].cut ==0 && tr[i].x == tr[index].x && tr[i].y>tr[index].y)
		{
			if(tr[i].y<min)
			{
				min= tr[i].y;
				dot =i;
			}
		}
	}
	value = tr[index].h*tr[index].d*tr[index].p;
	if(min-tr[index].y<tr[ok].h || min ==1000)
	{
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[ok].h*tr[ok].d*tr[ok].c && dot>0)
		{
      		value = value+cut_up(tr,dot,k,ok);
      	}
	}
	return value;
}
void assign_up_cut(tree *tr,int index,int k,int ok)
{
  	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++)
	{
		if(tr[i].cut ==0 && tr[i].x == tr[index].x && tr[i].y>tr[index].y)
		{
			if(tr[i].y<min)
			{
				min= tr[i].y;
				dot =i;
			}
		}
	}
	tr[index].cut =1;
	if(min-tr[index].y<tr[ok].h || min ==1000)
	{
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[ok].h*tr[ok].d*tr[ok].c && dot>0)
		{
      		assign_up_cut(tr,dot,k,ok);
      	}
	}
}

int cut_down(tree *tr,int index,int k,int ok)
{
	int max = 0;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++)
	{
		if(tr[i].cut ==0 && tr[i].x == tr[index].x && tr[i].y<tr[index].y)
		{
			if(tr[i].y>max)
			{
				max= tr[i].y;
				dot =i;
			}
		}
	}
	value = tr[index].h*tr[index].d*tr[index].p;
	if(abs(max-tr[index].y)<tr[ok].h || max ==0)
	{
		if(dot>=0)
		{
			if(tr[dot].h*tr[dot].d*tr[dot].c<tr[ok].h*tr[ok].d*tr[ok].c)
			{
	      		value = value+cut_down(tr,dot,k,ok);
	      	}
	    }
	}
	return value;
}
void assign_down_cut(tree *tr,int index,int k,int ok)
{
	int max = 0;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++)
	{
		if(tr[i].cut ==0 && tr[i].x == tr[index].x && tr[i].y<tr[index].y)
		{
			if(tr[i].y>max)
			{
				max= tr[i].y;
				dot =i;
			}
		}
	}
	tr[index].cut =1;
	if(abs(max-tr[index].y)<tr[ok].h || max ==0)
	{
		if(dot>=0)
		{
			if(tr[dot].h*tr[dot].d*tr[dot].c<tr[ok].h*tr[ok].d*tr[ok].c)
			{
	      		assign_down_cut(tr,dot,k,ok);
	      	}
	     }
	}
}

int cut_right(tree *tr,int index,int k,int ok)
{
	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++)
	{
		if(tr[i].cut ==0 && tr[i].y == tr[index].y && tr[i].x>tr[index].x)
		{
			if(tr[i].x<min)
			{
				min= tr[i].x;
				dot =i;
			}
		}
	}
	value = tr[index].h*tr[index].d*tr[index].p;
	if(abs(min-tr[index].x)<tr[ok].h || min ==1000)
	{
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[ok].h*tr[ok].d*tr[ok].c && dot>0)
		{
      		value = value+cut_right(tr,dot,k,ok);
      	}
	}
	return value;
}
void assign_right_cut(tree *tr,int index,int k,int ok)
{
	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++)
	{
		if(tr[i].cut ==0 && tr[i].y == tr[index].y && tr[i].x>tr[index].x)
		{
			if(tr[i].x<min)
			{
				min= tr[i].x;
				dot =i;
			}
		}
	}
	tr[index].cut =1;
	if(abs(min-tr[index].x)<tr[ok].h || min ==1000)
	{
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[ok].h*tr[ok].d*tr[ok].c && dot>0)
		{
      		assign_right_cut(tr,dot,k,ok);
      	}
	}
}

int cut_left(tree *tr,int index,int k,int ok)
{
	int max = 0;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++)
	{
		if(tr[i].cut ==0 && tr[i].y == tr[index].y && tr[i].x<tr[index].x)
		{
			if(tr[i].x>max)
			{
				max= tr[i].x;
				dot =i;
			}
		}
	}
	value = tr[index].h*tr[index].d*tr[index].p;
	if(abs(max-tr[index].x)<tr[ok].h || max ==0)
	{	
		if(dot>=0)
		{
			if(tr[dot].h*tr[dot].d*tr[dot].c<tr[ok].h*tr[ok].d*tr[ok].c)
			{
      			value = value+cut_left(tr,dot,k,ok);
      		}	
      	}
	}
	return value;
}
void assign_left_cut(tree *tr,int index,int k,int ok){
	int max = 0;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++){
		if(tr[i].cut ==0 && tr[i].y == tr[index].y && tr[i].x<tr[index].x )
		{
			if(tr[i].x>max)
			{
				max= tr[i].x;
				dot =i;
			}
		}
	}
	tr[index].cut=1;
	if(abs(max-tr[index].x)<tr[ok].h || max==0)
	{	
		if(dot>=0)
		{
			if(tr[dot].h*tr[dot].d*tr[dot].c<tr[ok].h*tr[ok].d*tr[ok].c)
			{
      			assign_left_cut(tr,dot,k,ok);
      		}	
      	}
	}
}

int gain(vector<int> v)
{
	int max=0;
	int index;
	for(int i=0;i<v.size();i++)
	{
         if(v[i]>max)
         {
         	max=v[i];
         	index=i;
         }
	}
 return index;	
}

int nearest_tree(int t,tree *tr,int x1, int y1,int min,int k,vector<int>p,vector<int>q)
{
	vector<int>s;
	int x2,y2,z2,out;
	int d;
	float max =0;
	float near;
	out =-1;
	for(int i=0;i<k;i++)
	{
		if(k<1871)
		{
			if(tr[i].cut==0 && (tr[i].x != x1 || tr[i].y != y1))
			{  
				s.push_back(cut_up(tr,i,k,i));
				s.push_back(cut_down(tr,i,k,i));
				s.push_back(cut_right(tr,i,k,i));
				s.push_back(cut_left(tr,i,k,i));
				d = gain(s);
				x2 =abs(tr[i].x - x1);
				y2 = abs(tr[i].y - y1);
				z2 = x2 + y2;
				if((t-(z2+tr[i].d))>=0)
				{
				 	near = (s[d]/float(z2+tr[i].d));
				}
				if(near>max)
				{
					 out = i;
					 max = near;
				}
			    s.resize(0);
			}
		}
		else 
		{
			int b=-1;
			if(tr[i].cut==0 && (tr[i].x != x1 || tr[i].y != y1))
			{
				x2 =abs(tr[i].x - x1);
				y2 = abs(tr[i].y - y1);
				z2 = x2 + y2;
				
				if((t-(z2+tr[i].d))>=0)
				{
				 	near = (p[i]/float(z2+tr[i].d));
				}
				if(near>max)
				{
					out = i;
					max = near;
				}
			}
		}	
     }
		return out;
}
int main()
{
	int t,n,k;	
	cin>>t;
	cin>>n;
	cin>>k;
	tree tr[k];
	for(int i=0;i<k;i++)
	{
		cin>>tr[i].x;
		cin>>tr[i].y;
		cin>>tr[i].h;
		cin>>tr[i].d;
		cin>>tr[i].c;
		cin>>tr[i].p;
		tr[i].cut = 0;
	}
	int x1,y1;
	x1 =0;
	y1 =0;
	int min = 5000;
	int index;
	vector<int> p;
	vector<int> q;
	for(int i=0;i<k;i++)
	{
	vector<int> t;
	 t.push_back(cut_up(tr,i,k,i));
     t.push_back(cut_down(tr,i,k,i));
     t.push_back(cut_right(tr,i,k,i));
     t.push_back(cut_left(tr,i,k,i));
     int pt;
     pt = gain(t);
     p.push_back(t[pt]);
     t.resize(0);
	}
	int w[p.size()];
    for(int h=0;h<p.size();h++)
    {
    	w[h]=p[h];
    }
	int maxm=0;	
	vector<int> du;
	int dumb=k;
	int tom;
	while(dumb>0){
		for(int x=0;x<p.size();x++){
			if(w[x]>maxm){
				maxm=w[x];
				tom=x;
			}
		}
		w[tom]=0;
		q.push_back(tom);
		dumb--;
	}
	while(t>0)
	{
     index = nearest_tree(t,tr,x1,y1,min,k,p,q);
     if(index<0)
     {
     	break;
     } 
     int incr = 0;
		int val1 = tr[index].x-x1;
		if(val1>=0)
		{
			if(t>abs(val1))
			{
				for(int j=0;j<abs(val1);j++)
				{
					cout<<"move right"<<endl;
					incr++;
				}
			}
			else
			{
				for(int j=0;j<t;j++)
				{
					cout<<"move right"<<endl;
					incr++;
				}
			}	
		}
	    else
	    {
	    	if(t>abs(val1))
	    	{
				for(int j=0;j<abs(val1);j++)
				{
					cout<<"move left"<<endl;
					incr++;
				}
			}
			else
			{
				for(int j=0;j<t;j++)
				{
					cout<<"move left"<<endl;
					incr++;
				}
			}	
	    }
	    int val2 = tr[index].y-y1;
		if(val2>=0)
		{
			if(t>abs(val2))
			{
				for(int j=0;j<abs(val2);j++)
				{
					cout<<"move up"<<endl;
					incr++;
				}
			}
			else
			{
				for(int j=0;j<t;j++)
				{
					cout<<"move up"<<endl;
					incr++;
				}
			}	
		}
	    else
	    {
	    	if(t>abs(val2))
	    	{
				for(int j=0;j<abs(val2);j++)
				{
					cout<<"move down"<<endl;
					incr++;
				}
			}
			else
			{
				for(int j=0;j<t;j++)
				{
					cout<<"move down"<<endl;
					incr++;
				}
			}	
	    }
	 t=t-incr;
	 int check = abs(tr[index].x-x1)+abs(tr[index].y-y1);
	 x1=tr[index].x;
     y1=tr[index].y;
     vector<int> v;
     v.push_back(cut_up(tr,index,k,index));
     v.push_back(cut_down(tr,index,k,index));
     v.push_back(cut_right(tr,index,k,index));
     v.push_back(cut_left(tr,index,k,index));
     int pf;
     pf = gain(v);

     if(t-tr[index].d>=0 && tr[index].cut==0)
     {
	     switch(pf)
	     {
	     	case 0:
	     	  cout<<"cut up"<<endl;
	     	  assign_up_cut(tr,index,k,index);
	     	  break;
	     	case 1:
	     	  cout<<"cut down"<<endl;
	     	   assign_down_cut(tr,index,k,index);
	     	   break;
	     	case 2:
	     	   cout<<"cut right"<<endl;
	     	   assign_right_cut(tr,index,k,index);
	     	   break;
	     	case 3:
	     	  cout<<"cut left"<<endl;
	     	   assign_left_cut(tr,index,k,index);
	     	   break;
	     }
	     t=t-tr[index].d;
	  }
     v.resize(0);
	}
}
