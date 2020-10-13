#include <stdio.h>
#include <stdlib.h>

int time,n,numOfTrees;

struct tree
{  
  int x,y;
  int height;
  int thickness;
  int weight;
  int value;
  int leftValue, rightValue, upValue, downValue;

}*treeDetails,*arrangment[1001][1001],nullTree = {0,0,0,0,0,0,0,0,0,0};


void neibhour(struct tree *treeDetails)
{



    for(register int i=0;( (i<numOfTrees) && (treeDetails[i].height>1) ); i++)
    {                                                       
      int e =  treeDetails[i].x;
      int f =  treeDetails[i].y;

      // //Right
      for(int i = e ; i<n ; i++)
      {
        if( arrangment[i][f]->weight >= arrangment[i+1][f]->weight)
        {
          arrangment[e][f]->rightValue += arrangment[i+1][f]->value;
        }
        else
        {
          break;
        }
      }
     
      // //left
      for(int i = e ; i>0 ; i--)
      {
        if( arrangment[i][f]->weight >= arrangment[i-1][f]->weight)
        {
          arrangment[e][f]->leftValue += arrangment[i-1][f]->value;
        }
        else
        {
          break;
        }
      }

      // //Up
      for(int i =  f; i<n ; i++)
      {
        if( arrangment[e][i]->weight >= arrangment[e][i+1]->weight)
        {
          arrangment[e][f]->upValue += arrangment[e][i+1]->value ;
        }
        else
        {
          break;
        }
      }

      // //down
      for(int i = f ; i>0 ; i--)
      {
        if( arrangment[e][i]->weight >= arrangment[e][i-1]->weight)
        {
          arrangment[e][f]->leftValue += arrangment[e][i-1]->value;
        }
        else
        {
          break;
        }
      }

    }

}

int main(int argc, char *argv[])
{
  FILE *fp;

  char *filename;
  filename = argv[1];

  char ch;

  fp = fopen(filename, "r");

  if (fp == NULL)
   {
      printf("\n\t file named as-'%s' is not available.\n\n", filename);
      exit(0);
   }


  fscanf(fp,"%d %d %d",&time,&n,&numOfTrees);
  treeDetails = realloc(treeDetails,numOfTrees*sizeof(struct tree));
  


  for(int i = 0 ; i<=1000 ;i++)
  {
    for(int j= 0; j<=1000; j++)
    {
      arrangment[i][j] = &nullTree;
    }
  }

  printf("time - %d ,n - %d ,num of Trees - %d \n",time,n,numOfTrees); 
  for(register int i=0; i<numOfTrees; i++)
  { 
      int x,y;
      int weight ,value ; 
      fscanf(fp,"%d %d %d %d %d %d",&x ,&y ,&treeDetails[i].height ,&treeDetails[i].thickness ,&weight,&value);
      treeDetails[i].x = x;
      treeDetails[i].y = y;
      treeDetails[i].weight = weight*treeDetails[i].height*treeDetails[i].thickness ;
      treeDetails[i].value = value*treeDetails[i].height*treeDetails[i].thickness;
      treeDetails[i].upValue =  treeDetails[i].value;
      treeDetails[i].rightValue =  treeDetails[i].value;
      treeDetails[i].downValue =  treeDetails[i].value;
      treeDetails[i].leftValue =  treeDetails[i].value;
      arrangment[x][y] = &treeDetails[i];
  }

 fclose(fp);

 neibhour(treeDetails);

  for(int i = 0 ; i<=n ;i++)
  {
    for(int j= 0; j<=n; j++)
    {
        printf("(%d,%d)  =>  up -%d, right -%d, down -%d, left -%d  \n",i,j, arrangment[i][j]->upValue, arrangment[i][j]->rightValue, arrangment[i][j]->downValue, arrangment[i][j]->leftValue);
    }
  }
    


 return 0;
}