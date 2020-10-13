#include<iostream>
#include<cstring>
using namespace std;
struct tree
{
	int x,y,h,d,c,p;
	int cut;
};
void pn(tree *p)
{
	//cout<<p[1].x<<endl;
	p[2].cut =1;
	cout<<p[1].cut<<endl;
	cout<<p[2].cut<<endl;
}
int main(){
	int t,n,k;	
	cin>>t;
	cin>>n;
	cin>>k;
	tree tr[k];
	//cout<<"tree details: "<<endl;
	for(int i=0;i<k;i++){
		cin>>tr[i].x;
		cin>>tr[i].y;
		cin>>tr[i].h;
		cin>>tr[i].d;
		cin>>tr[i].c;
		cin>>tr[i].p;
		tr[i].cut = 0;
	}
	
     pn(tr);
	//search nearest tree
	int x1,y1;
	x1 =0;
	y1 =0;
	int min;
	int out;
	int x2,y2,z2;
    int check;
	//cout<<min<<endl;
	int profit = 0;
	//while(t>0){
		min = 1000000;
		check = 0;
	//search nearest tree
		for(int i=0;i<k;i++){
			//cout<<tr[i].cut<<tr[i].x<<tr[i].y<<x1<<y1<<endl;
			if(tr[i].cut==0 && (tr[i].x != x1 || tr[i].y != y1)){
				 x2 =abs(tr[i].x - x1);
				 y2 = abs(tr[i].y - y1);
				 z2 = x2 + y2;
				 check = 1;
				// cout<<x2<<"  "<<y2<<" coming"<<z2<<endl;
				if(z2<=min){
					 out = i;
					 min = z2;
				}
			}
		}
		//cout<<out<<endl;
		
		int incr = 0;
		//move left or light
		
		int val1 = tr[out].x-x1;
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
	    int val2 = tr[out].y-y1;
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
	    	if(t>abs(val1)){
				for(int j=0;j<abs(val1);j++){
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
	    //cout<<out<<endl;
		if (check == 1){
			t = t-incr;
		}

		x1 = tr[out].x;
		y1 = tr[out].y;
		tr[out].cut = 1;
		//cout <<tr[out].cut<<endl;
		//cut the tree
		if(t-tr[out].d>=0){
            cout<<"cut right"<<endl;
			t = t - (tr[out].d);
	     }
		//cout<<"time left"<<t<<endl; 
		if(t>0){
		profit = profit + (tr[out].h*tr[out].d*tr[out].p);
		}	
		//cout<<t<<endl;
	}	
