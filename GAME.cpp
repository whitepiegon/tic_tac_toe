#include<conio.h>
#include<stdio.h>

void prnt(int A[][3], int);
int check (int A[][3]);
int procedure (int A[][3], int);


main()

{
      
      int y, A[3][3]={0}, step=0;
      
          printf("Player 1 will start with 'X'\nPlayer 2 will use 'O'\n");
          
      y = procedure (A,step);
      
      if (y==2)
           printf("\n\nWINNER IS PLAYER 2\n");
      else if (y==1)
           printf("\n\nWINNER IS PLAYER 1\n"); 
      else if (y==3)
           printf("\n\nDRAW\n"); 
      getch();
}


int procedure (int A[][3], int step)
{
     int col,row,y,i,j;
     step= step+1;
     
     if (step>9)
     return (3);
      
     prnt(A,step);
     
     printf("\nrow=");        
     scanf("%d",&row);
     
     printf("\ncolumn=");
     scanf("%d",&col);
     
     i=row-1;
     j=col-1;
     
     
                  
             if (((i < 0) || (i > 2)) || ((j < 0) || (j > 2)) || (A[i][j] != 0))
             {
                         printf("\nCHOICE NOT ALLOWED\n");
                         step=step-1;
                         y = procedure (A,step);
                         if (y==1)
                         return (1);
                         else if (y==2)
                         return (2);
             }
             
     int k= step%2;
         
     if (k==0)
     A[i][j]=200;
                   
     else
     A[i][j]=250;
          
     if (step>=5)
     {
                 y = check(A);
                 if (y==1)
                 return (1);
                 else if (y==2)
                 return (2);
     }
     
     
         y = procedure (A,step);
         if (y==1)
         return (1);
         else if (y==2)
         return (2);
         else if (y==3)
         return (3);
     
}

int check(int A[][3])
{
              int sum1=0,sum2=0,sum3=0,sum4=0;
              for (int i=0;i<3;i++)
              {
                  for (int j=0;j<3;j++)
                  {
                      sum1=sum1+A[i][j];
                      sum2=sum2+A[j][i];
                      if (j==i)
                         sum3=sum3+A[i][j];
                      if(i+j==4)
                         sum4=sum4+A[i][j];
                  }
                  
                  if (sum1==750 || sum2==750 || sum3==750 || sum4==750)
                  {
                                return (1);
                                break;
                                }
                  else if (sum1==600 || sum2==600 || sum3==600 || sum4==600)
                  {
                                return (2);
                                break;
                                }
                  sum1=0,sum2=0;
              }
                       
                   
                      
              
}


void prnt (int A[][3], int step)
{
         printf("\nCURRENT STATUS OF GAME IS\n");
         printf("\t1\t2\t3\n");
         for (int i=0;i<3;i++)
         {
             int g=i+1;
             printf("%d\t",g);
             for (int j=0;j<3;j++)
             {
                 
                 if (A[i][j]==250)
                    printf("X\t");
                 else if (A[i][j]==200)
                    printf("O\t");
                 else if (A[i][j]==0)
                 printf("_\t");
             }
         
         printf("\n");
         
         }
         
         if (step%2==0)
            printf("\n\nMAKE YOUR CHOICE PLAYER 2\n");
         else
            printf("\n\nMAKE YOUR CHOICE PLAYER 1\n"); 

}
