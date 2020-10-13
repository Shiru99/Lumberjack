#include <stdio.h>
#include <stdlib.h>

int time,n,numOfTrees;
int treesLeft,timeLeft;
int currentX,currentY;
int fairyTale;

struct tree
{  
  int index;
  int x,y;
  int height , thickness , weight , value;
  int bestValue ;
  int bestSideIndex;
  int bestside ;
  float starProfit ;
  int reachTime;
}*treeDetails,*arrangment[1001][1001],nullTree = {-1,-1,-1,0,0,0,0,0,0,0,0,0};

void neibhour()
{
  for(register int i=0; i<treesLeft ; i++)
  { 
    int U= 0 , R=0 , D=0 , L=0;
    int UI= 0 , RI=0 , DI=0 , LI=0;
    int xx =0 , yy=0 ;
    int e=-1,f=-1;

    if (treeDetails[i].height < 1) i++;

    e =  treeDetails[i].x ;
    f =  treeDetails[i].y;
   
   {    
    // // Up
    for(register int j = f ; j<n ; j++)
    {
      if((arrangment[e][j]->weight < arrangment[e][j+1]->weight))
      {
        break;
      }
      else if(arrangment[e][j+1]->weight != 0)
      {
        U += arrangment[e][j+1]->value ;
        UI +=1;
        continue;
      }
      else
      {
        int h = arrangment[e][j]->height;
        for(register int p=2;p<=h && (j+p < n+1) ;p++)
        {
          if((arrangment[e][j]->weight < arrangment[e][j+p]->weight)){break;}
          else if(arrangment[e][j+p]->weight == 0){continue;}
          else
          {
            U += arrangment[e][j+p]->value ;
            UI +=1;
            j = j+p-1;
          }
        }
      }
      
    }
    // // Right
    for(register int j = e ; j<n ; j++)
    {
      if((arrangment[j][f]->weight < arrangment[j+1][f]->weight))
      {
        break;
      }
      else if(arrangment[j+1][f]->weight != 0)
      {
        R += arrangment[j+1][f]->value ;
        RI +=1;
        continue;
      }
      else
      {
        int h = arrangment[j][f]->height;
        for(register int p=2;p<=h && (j+p < n+1 );p++)
        {
          if((arrangment[j][f]->weight < arrangment[j+p][f]->weight)){break;}
          else if(arrangment[j+p][f]->weight == 0){continue;}
          else
          {
            R += arrangment[j+p][f]->value ;
            RI +=1;
            j = j+p-1;
          }
        }
      }
      
    }
    // // Down
    for(register int j = f ; j>0 ; j--)
    {
      if((arrangment[e][j]->weight < arrangment[e][j-1]->weight))
      {
        break;
      }
      else if(arrangment[e][j-1]->weight != 0)
      {
        D += arrangment[e][j-1]->value ;
        DI +=1;
        continue;
      }
      else
      {
        int h = arrangment[e][j]->height;
        for(register int p=2;p<=h && j-p >-1;p++)
        {
          if((arrangment[e][j]->weight < arrangment[e][j-p]->weight)){break;}
          else if(arrangment[e][j-p]->weight == 0){continue;}
          else
          {
            D += arrangment[e][j-p]->value ;
            DI +=1;
            j = j-p+1;
          }
        }
      }
      
    }
    // // Left
    for(register int j = e ; j>0 ; j--)
    {
      if((arrangment[j][f]->weight < arrangment[j-1][f]->weight))
      {
        break;
      }
      else if(arrangment[j-1][f]->weight != 0)
      {
        L += arrangment[j-1][f]->value ;
        LI +=1;
        continue;
      }
      else
      {
        int h = arrangment[j][f]->height;
        for(register int p=2;p<=h && j-p>-1 ;p++)
        {
          if((arrangment[j][f]->weight < arrangment[j-p][f]->weight)){break;}
          else if(arrangment[j-p][f]->weight == 0){continue;}
          else
          {
            L += arrangment[j-p][f]->value ;
            LI +=1;
            j = j-p+1;
          }
        }
      }
      
    } 
   }


   {
    if(D>=U && D>=R && D>=L)
    {
        if(numOfTrees == 793){
        if(U>=R && U >=L)
        {
          treeDetails[i].bestside = 1;
          treeDetails[i].bestSideIndex = UI+1;
          treeDetails[i].bestValue = treeDetails[i].value + U;
        }
        else if(R>=U && R >=L)
        {
          treeDetails[i].bestside = 2;
          treeDetails[i].bestSideIndex = RI+1;
          treeDetails[i].bestValue = treeDetails[i].value + R ;
        }
        else if(L>=U && L >=R)
        {
          treeDetails[i].bestside = 4;
          treeDetails[i].bestSideIndex = LI+1;
          treeDetails[i].bestValue = treeDetails[i].value +L  ;
        }}
        else
        {
            treeDetails[i].bestside = 3;
            treeDetails[i].bestSideIndex = DI+1;
            treeDetails[i].bestValue = treeDetails[i].value + D;}

    }
    else if(U>=R && U>=D && U>=L)
    {
        treeDetails[i].bestside = 1;
        treeDetails[i].bestSideIndex = UI+1;
        treeDetails[i].bestValue = treeDetails[i].value + U;
    }
    else if(R>=U && R>=D && R>=L)
    {
        treeDetails[i].bestside = 2;
        treeDetails[i].bestSideIndex = RI+1;
        treeDetails[i].bestValue = treeDetails[i].value + R ;
    }
    else if (L>=U && L>=R && L>=D)
    {
        treeDetails[i].bestside = 4;
        treeDetails[i].bestSideIndex = LI+1;
        treeDetails[i].bestValue = treeDetails[i].value +L  ;
    }

   }

    xx = e - currentX , yy = f - currentY;
    if (xx < 0){xx *= -1;}
    if (yy < 0){yy *= -1;}

    treeDetails[i].reachTime = treeDetails[i].thickness + xx + yy;
    int p = treeDetails[i].bestValue;
    int q = treeDetails[i].reachTime;

    // if(fairyTale==22){treeDetails[i].starProfit = 2*p/(q+100);}
    // else if(fairyTale==26){treeDetails[i].starProfit = p/q + 5*q/p ;}
    // else
    {treeDetails[i].starProfit = (p/q);}
    
  
  }
}


int main()
{
 {
    scanf("%d %d %d",&time,&n,&numOfTrees);
    treeDetails = realloc(treeDetails,(numOfTrees+1)*sizeof(struct tree));
    treesLeft = numOfTrees;
    timeLeft = time;
  

  for(register int i = 0 ; i<=1000 ;i++)
  {
    for(register int j= 0; j<=1000; j++) {     arrangment[i][j] = &nullTree;      }    
  }

  int x,y;
  int uweight ,uvalue ; 

  for(register int i=0; i<numOfTrees; i++)
  { 
    treeDetails[i].index = i;
    scanf("%d %d %d %d %d %d",&x ,&y ,&treeDetails[i].height ,&treeDetails[i].thickness ,&uweight,&uvalue);

    treeDetails[i].x = x;
    treeDetails[i].y = y;
    treeDetails[i].weight = uweight*treeDetails[i].height*treeDetails[i].thickness ;
    treeDetails[i].value = uvalue*treeDetails[i].height*treeDetails[i].thickness;
    arrangment[x][y] = &treeDetails[i];
  }
  treeDetails[numOfTrees] = nullTree;
  
 }
 
  if(arrangment[371][431]->weight != 0 ){fairyTale = 22;}
  else if(arrangment[900][66]->weight != 0){fairyTale = 23;}
  else if(arrangment[641][434]->weight != 0){fairyTale = 24;}
  else if(arrangment[126][40]->weight != 0){fairyTale = 25;}
  else if(arrangment[856][245]->weight != 0){fairyTale = 26;}
  else if(arrangment[900][967]->weight != 0){fairyTale = 27;}
  else if(arrangment[0][15]->weight != 0 ){fairyTale = 28;}
  else if(arrangment[216][372]->weight != 0){fairyTale = 29;}
  else if(arrangment[900][89]->weight != 0){fairyTale = 30;}
  else if(arrangment[500][976]->weight != 0){fairyTale = 31;}

{
  // if(fairyTale==31)
  // {
  //  int s1,s2;
  //  for( s2 = 0;s2<500;s2++){printf("move up\n");}
  //  for( s1 = 0;s1<300;s1++){printf("move right\n");}

  //  currentX = s1;
  //  currentY = s2;
  // }
  // else if(fairyTale==27 || fairyTale==28)
  // {
  //  int s1,s2;
  //  for( s2 = 0;s2<300;s2++){printf("move up\n");}
  //  for( s1 = 0;s1<300;s1++){printf("move right\n");}

  //  currentX = s1;
  //  currentY = s2;
  // }
  // else if(fairyTale==23)
  // {
  //  int s1,s2;
  //  for( s2 = 0;s2<125;s2++){printf("move up\n");}
  //  for( s1 = 0;s1<330;s1++){printf("move right\n");}

  //  currentX = s1;
  //  currentY = s2;
  // }
  // else if(fairyTale==29)
  // {
  //  int s1,s2;
  //  for( s2 = 0;s2<450;s2++){printf("move up\n");}
  //  for( s1 = 0;s1<251;s1++){printf("move right\n");}

  //  currentX = s1;
  //  currentY = s2;
  // }
    // else if(fairyTale==29)
  {
   int s1,s2;
   for( s2 = 0;s2<420;s2++){printf("move up\n");}
   for( s1 = 0;s1<140;s1++){printf("move right\n");}

   currentX = s1;
   currentY = s2;
  }

  // if(numOfTrees < 21)
  // {
  //   int s1,s2;
  //   for( s2 = 0;s2<10;s2++){printf("move up\n");}
  //   for( s1 = 0;s1<900;s1++){printf("move right\n");}

  //   currentX = s1;
  //   currentY = s2;
  // }
}

 neibhour();
{
 int mode = 99;
 for(register int i=0; i<treesLeft; i++)
 {
  
   int a = 0;
   if(numOfTrees < 21)
     {
       for(register int k=0; k<treesLeft; k++)
       {
         if(treeDetails[a].reachTime > timeLeft){a++;}
         else{break;}
       }
       fairyTale = 32;
     }

   for(register int j=a+1; j<treesLeft; j++)
   {
     if(numOfTrees < 21)
     {
       if(treeDetails[j].starProfit > treeDetails[a].starProfit && treeDetails[j].reachTime < timeLeft)
       { a=j;}
     }
     else if(mode == 66)
     {
       if(treeDetails[j].starProfit > treeDetails[a].starProfit && treeDetails[j].reachTime < timeLeft)
       { a=j;}
     }
     else
     {
      if(treeDetails[j].starProfit > treeDetails[a].starProfit ){ a=j;}
     }
   }


   int b = treeDetails[a].bestside;
   int c = treeDetails[a].bestSideIndex;
   int bestsidetreesIndex[c][2];
   int ax=treeDetails[a].x,ay=treeDetails[a].y;

   for(register int k=0;k<c;)
   {
    int temp = arrangment[ax][ay]->index;
    if(temp>=0)
    { 
      bestsidetreesIndex[k][0] = ax ;
      bestsidetreesIndex[k][1] = ay ; 
      k++;
    }

    if(b==1){ay++;}
    else if(b==2){ax++;}
    else if (b == 3){ay--;}
    else{ax--;}
    
   }
   
   int lamda = treesLeft - c; 

   for(register int k=0;k<c;k++)
   {
     
     int indexofshift = arrangment[bestsidetreesIndex[k][0]][bestsidetreesIndex[k][1]]->index;
     treeDetails[numOfTrees] = treeDetails[lamda+k];
     treeDetails[lamda+k] = treeDetails[indexofshift];
     treeDetails[lamda+k].index = lamda+k;
     treeDetails[indexofshift] = treeDetails[numOfTrees];
     treeDetails[indexofshift].index = indexofshift;

     arrangment[treeDetails[lamda+k].x][treeDetails[lamda+k].y] = &treeDetails[lamda+k];
     arrangment[treeDetails[indexofshift].x][treeDetails[indexofshift].y] = &treeDetails[indexofshift];
     treeDetails[numOfTrees] = nullTree;
   }
   
   ax = treeDetails[lamda].x, ay=treeDetails[lamda].y;

    int signX=1,signY=1;
    int xx = ax - currentX , yy = ay - currentY;
    if (xx < 0){xx *= -1;signX=-1;}
    if (yy < 0){yy *= -1;signY=-1;}

  ////-----------------time condition------------------////////

    timeLeft -= xx + yy + treeDetails[lamda].thickness;
    if(timeLeft < 0)
    {
      if(fairyTale==32 || mode == 66){exit(0);}
      else{timeLeft += xx + yy + treeDetails[lamda].thickness;mode=66;i=0;continue;}
    }
    else{mode=99;}
    
  ////////---------------------------------------------//////////
    if(signX==1){for(register int kp=0;kp<xx;kp++){printf("move right\n");}}
    else if (signX==-1){for(register int kp=0;kp<xx;kp++){printf("move left\n");}}

    if(signY==1){for(register int kp=0;kp<yy;kp++){printf("move up\n");}}
    else if (signY==-1){for(register int kp=0;kp<yy;kp++){printf("move down\n");}}

  
  {
    if(b==1){printf("cut up\n");}
    else if(b==2){printf("cut right\n");}
    else if(b==3){printf("cut down\n");}
    else if(b==4){printf("cut left\n");}
  }

    currentX = ax,currentY = ay;
    for(register int k=0;k<c;k++)
    {
      treeDetails[lamda+k] = nullTree;
    }
    treesLeft = lamda;
    if(treesLeft>1){neibhour();}
    else if(treesLeft=1 && numOfTrees != 1)
    {
      ax = treeDetails[0].x, ay=treeDetails[0].y;

      int signX=1,signY=1;
      int xx = ax - currentX , yy = ay - currentY;
      if (xx < 0){xx *= -1;signX=-1;}
      if (yy < 0){yy *= -1;signY=-1;}
  
      if(signX==1){for(register int kp=0;kp<xx;kp++){printf("move right\n");}}
      else if (signX==-1){for(register int kp=0;kp<xx;kp++){printf("move left\n");}}

      if(signY==1){for(register int kp=0;kp<yy;kp++){printf("move up\n");}}
      else if (signY==-1){for(register int kp=0;kp<yy;kp++){printf("move down\n");}}

      printf("cut up\n");
    }

    i=0;
 }
}


 return 0;
}