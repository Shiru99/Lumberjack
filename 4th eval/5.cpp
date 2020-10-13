#include<iostream>
#include<cstring>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
struct tree
{
	int x,y,h,d,c,p;
	int cut;
};
int cut_up(tree *tr,int index,int k);
int cut_down(tree *tr,int index,int k);
int cut_right(tree *tr,int index,int k);
int cut_left(tree *tr,int index,int k);
int gain(vector<int> v);
int nearest_tree(int t,tree *tr,int x1, int y1,int min,int k,vector<int>p,vector<int>q)
{
	vector<int>s;
	//int p=0;
	int x2,y2,z2,out;
	int d;
	float max =0;
	float near;
	out =-1;
	for(int i=0;i<k;i++){
			//cout<<tr[i].cut<<tr[i].x<<tr[i].y<<x1<<y1<<endl;
		if(k<1871){
			if(tr[i].cut==0 && (tr[i].x != x1 || tr[i].y != y1))
			{  
				s.push_back(cut_up(tr,i,k));
				s.push_back(cut_down(tr,i,k));
				//s.push_back(cut_right(tr,i,k));
				//s.push_back(cut_left(tr,i,k));
				//cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<" "<<s[3]<<endl;
				d = gain(s);
				 x2 =abs(tr[i].x - x1);
				 y2 = abs(tr[i].y - y1);
				 z2 = x2 + y2;
				 if((t-(z2+tr[i].d))>=0){
				 	near = (s[d]/float(z2+tr[i].d));
				 	//cout<<near<<endl;
				 }
				 //cout<<near<<endl;
				 //check = 1;
				// cout<<x2<<"  "<<y2<<" coming"<<z2<<endl;
				if(near>max){
					 out = i;
					 max = near;
				}
			    s.resize(0);
			}
			
			//p++;
		}
		else {
			//int b=-1;
			if(tr[i].cut==0 && (tr[i].x != x1 || tr[i].y != y1)){
				x2 =abs(tr[i].x - x1);
				y2 = abs(tr[i].y - y1);
				z2 = x2 + y2;
				
				 if((t-(z2+tr[i].d))>=0){
				 	near = (p[i]/float(z2+tr[i].d));
				 	//cout<<near<<endl;
				 }
			
				 if(near>max){
					 out = i;
					 max = near;
				}
				

			}

		}	
     }
		
		return out;
}

int cut_up(tree *tr,int index,int k){
	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++){
		if(tr[i].cut ==0 && tr[i].x == tr[index].x && tr[i].y>tr[index].y){
			if(tr[i].y<min){
				min= tr[i].y;
				dot =i;
				//cout<<dot<<endl;
			}
		}
	}
	value = tr[index].h*tr[index].d*tr[index].p;
	if(min-tr[index].y<tr[index].h || min ==1000){
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c && dot>0){
      		value = value+cut_up(tr,dot,k);
      	}
	}
	//cout<<value<<endl;
	return value;
}
void assign_up_cut(tree *tr,int index,int k){
  	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++){
		if(tr[i].cut ==0 && tr[i].x == tr[index].x && tr[i].y>tr[index].y){
			if(tr[i].y<min){
				min= tr[i].y;
				dot =i;
				//cout<<dot<<endl;
			}
		}
	}
	//value = tr[index].h*tr[index].d*tr[index].p;
	tr[index].cut =1;
	//*s =*s-1;
	if(min-tr[index].y<tr[index].h || min ==1000){
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c && dot>0){
      		assign_up_cut(tr,dot,k);
      	}
	}
}
int cut_down(tree *tr,int index,int k){
	int max = 0;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++){
		if(tr[i].cut ==0 && tr[i].x == tr[index].x && tr[i].y<tr[index].y){
			if(tr[i].y>max){
				max= tr[i].y;
				dot =i;
				//cout<<dot<<endl;
			}
		}
	}
	value = tr[index].h*tr[index].d*tr[index].p;
	if(abs(max-tr[index].y)<tr[index].h || max ==0){
		if(dot>=0){
			if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c){
	      		value = value+cut_down(tr,dot,k);
	      	}
	    }
	}
	//cout<<value<<endl;
	return value;
}
void assign_down_cut(tree *tr,int index,int k){
	int max = 0;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++){
		if(tr[i].cut ==0 && tr[i].x == tr[index].x && tr[i].y<tr[index].y){
			if(tr[i].y>max){
				max= tr[i].y;
				dot =i;
				//cout<<dot<<endl;
			}
		}
	}
	//value = tr[index].h*tr[index].d*tr[index].p;
	tr[index].cut =1;
	//*s =*s-1;
	if(abs(max-tr[index].y)<tr[index].h || max ==0){
		if(dot>=0){
			if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c){
	      		assign_down_cut(tr,dot,k);
	      	}
	     }
	}
	//cout<<value<<endl;
	//return value;
}
int cut_right(tree *tr,int index,int k){
	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++){
		if(tr[i].cut ==0 && tr[i].y == tr[index].y && tr[i].x>tr[index].x){
			if(tr[i].x<min){
				min= tr[i].x;
				dot =i;
				//cout<<dot<<endl;
			}
		}
	}
	value = tr[index].h*tr[index].d*tr[index].p;
	if(abs(min-tr[index].x)<tr[index].h || min ==1000){
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c && dot>0){
      		value = value+cut_right(tr,dot,k);
      	}
	}
	//cout<<value<<endl;
	return value;
}
void assign_right_cut(tree *tr,int index,int k){
	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++){
		if(tr[i].cut ==0 && tr[i].y == tr[index].y && tr[i].x>tr[index].x){
			if(tr[i].x<min){
				min= tr[i].x;
				dot =i;
				//cout<<dot<<endl;
			}
		}
	}
	tr[index].cut =1;
	//*S =*S-1;
	if(abs(min-tr[index].x)<tr[index].h || min ==1000){
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c && dot>0){
      		assign_right_cut(tr,dot,k);
      	}
	}
	//cout<<value<<endl;
	//return value;
}
/*
55 10 5
2 3 4 5 2 2
2 6 3 1 1 3
2 7 2 2 2 4
5 5 10 3 1 5
4 3 5 5 2 6
*/
int cut_left(tree *tr,int index,int k){
	int max = 0;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++){
		if(tr[i].cut ==0 && tr[i].y == tr[index].y && tr[i].x<tr[index].x){
			if(tr[i].x>max){
				max= tr[i].x;
				dot =i;
				//cout<<dot<<endl;
			}
		}
	}
	value = tr[index].h*tr[index].d*tr[index].p;
	if(abs(max-tr[index].x)<tr[index].h || max ==0){	
		if(dot>=0){
			if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c){
      			value = value+cut_left(tr,dot,k);
      		}	
      	}
	}
	//cout<<value<<endl;
	return value;
}
void assign_left_cut(tree *tr,int index,int k){
	int max = 0;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++){
		if(tr[i].cut ==0 && tr[i].y == tr[index].y && tr[i].x<tr[index].x ){
			if(tr[i].x>max){
				max= tr[i].x;
				dot =i;
				//cout<<dot<<endl;
			}
		}
	}
	tr[index].cut=1;
	//*s =*s-1;
	if(abs(max-tr[index].x)<tr[index].h || max==0){	
		if(dot>=0){
			if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c){
      			assign_left_cut(tr,dot,k);
      		}	

      	}
	}
	//cout<<value<<endl;
	//return value;
}
int gain(vector<int> v){
	int max=0;
	int index;
	for(int i=0;i<v.size();i++){
         if(v[i]>max){
         	max=v[i];
         	index=i;
         }
	}
 return index;	
}
int main()
{
	int t,n,k;	
	cin>>t;
	cin>>n;
	cin>>k;
	tree tr[k];
	//cout<<"tree details: "<<endl;
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
	for(int i=0;i<k;i++){
		//p.push_back(tr[i].h*tr[i].d*tr[i].p);
	vector<int> t;
	t.push_back(cut_up(tr,i,k));
    t.push_back(cut_down(tr,i,k));
     //t.push_back(cut_right(tr,i,k));
     //t.push_back(cut_left(tr,i,k));
     int pt;
     pt = gain(t);
     p.push_back(t[pt]);
    // q.push_back(i);
     t.resize(0);
	}
	while(t>0){
     index = nearest_tree(t,tr,x1,y1,min,k,p,q);
     //cout<<index<<endl;
     if(index<0){
     	break;
     } 
    
     int incr = 0;
		//move left or light
		
		int val1 = tr[index].x-x1;
		if(val1>=0){
			if(t>abs(val1)){
				for(int j=0;j<abs(val1);j++){
					cout<<"move right"<<endl;
					incr++;
				}
			}
			else{
				for(int j=0;j<t;j++){
					cout<<"move right"<<endl;
					incr++;
				}
			}	
		}
	    else{
	    	if(t>abs(val1)){
				for(int j=0;j<abs(val1);j++){
					cout<<"move left"<<endl;
					incr++;
				}
			}
			else{
				for(int j=0;j<t;j++){
					cout<<"move left"<<endl;
					incr++;
				}
			}	
	    }
	    int val2 = tr[index].y-y1;
		if(val2>=0){
			if(t>abs(val2)){
				for(int j=0;j<abs(val2);j++){
					cout<<"move up"<<endl;
					incr++;
				}
			}
			else{
				for(int j=0;j<t;j++){
					cout<<"move up"<<endl;
					incr++;
				}
			}	
		}
	    else{
	    	if(t>abs(val2)){
				for(int j=0;j<abs(val2);j++){
					cout<<"move down"<<endl;
					incr++;
				}
			}
			else{
				for(int j=0;j<t;j++){
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
    v.push_back(cut_up(tr,index,k));
    v.push_back(cut_down(tr,index,k));
     //v.push_back(cut_right(tr,index,k));
    //v.push_back(cut_left(tr,index,k));
     int pf;
     pf = gain(v);
    // cout<<pf<<endl;

     if(t-tr[index].d>=0){
	     switch(pf)
	     {
	     	case 0:
	     	  cout<<"cut up"<<endl;
	     	  assign_up_cut(tr,index,k);
	     	  break;
	     	case 1:
	     	  cout<<"cut down"<<endl;
	     	   assign_down_cut(tr,index,k);
	     	  break;
	     	//case 2:
	     	  //cout<<"cut right"<<endl;
	     	   //assign_right_cut(tr,index,k);
	     	 //break;
	     	//case 3:
	     	 //cout<<"cut left"<<endl;
	     	 //assign_left_cut(tr,index,k);
	     	  //break;
	     }
	    // tr[index].cut =1;
	     t=t-tr[index].d;
	  }
     v.resize(0);
     //cout<<t<<endl;
     
	}
}