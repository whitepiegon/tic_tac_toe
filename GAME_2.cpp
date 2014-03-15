#include<conio.h>
#include<stdio.h>

void prnt(int A[][3], int);
int check (int A[][3]);
int procedure (int A[][3], int, int);
void comp(int A[][3], int);
int check2(int A[][3], int, int);
void descending(int B[][3]);


main()

{
      
      int y, A[3][3]={0}, choice, step=0, bari=0;
      
          printf("'TIC TAC TOE'\nIT IS A SERIOUS OF 5 GAMES\nWIN\t=\t5 POINTS\nDRAW\t=\t3 POINTS\nLOSS\t=\t0 POINTS\n");
          printf("");
          printf("\n\nENTER:\n1.TO START WITH USER\t2.TO START WITH COMP\n\n");
          scanf("%d",&choice);
          printf("\nCOMP will use 'X'\nPLAYER will use 'O'\n");
      step=step+choice;
      y = procedure (A,step,bari);
      
            
      /*change*/
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
      /*change*/
      
      if (y==2)
           printf("\n\nWINNER IS PLAYER\n");
      else if (y==1)
           printf("\n\nWINNER IS COMP\n"); 
      else if (y==3)
           printf("\n\nDRAW\n"); 
      
      getch();
}


int procedure (int A[][3], int step, int bari)

{
     int col, row, y, i, j;
     step= step+1;
     bari=bari+1;
     
     if (bari>9)
     return (3);
     
      
     prnt(A,step);
     
     int k= step%2;
         
     if (k==0)
     {
              
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
                         bari=bari-1;
                         y = procedure (A,step,bari);
                         if (y==1)
                         return (1);
                         else if (y==2)
                         return (2);
             }
             
     
             A[i][j]=200;
             
     }
                  
     else
     
                      
         comp(A, step);
         
          
     if (step>=5)
     {
                 
                 y = check(A);
                 printf("\ny=%d",y);
                 if (y==1)
                 return (1);
                 else if (y==2)
                 return (2);
     }
     
     
         y = procedure (A,step,bari);
         if (y==1)
         return (1);
         else if (y==2)
         return (2);
         else if (y==3)
         return (3);
     
}

int check(int A[3][3])
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
                      if(i+j==2)
                         sum4=sum4+A[i][j];
                  }
                  
                  if (sum1==750 || sum2==750 || sum3==750 || sum4==750)
                  {
                                return (1);
                                break;
                                }
                  if (sum1==600 || sum2==600 || sum3==600 || sum4==600)
                  {
                                return (2);
                                break;
                                }
                  
                  
                  
                                    
                  sum1=0,sum2=0;
              }
                       
          return (300);         
                      
              
}

void comp(int A[][3], int step)
{    
     int flag=0,ask,i=0,j,n=0,m=0;
     int B[3][3]={0};
     
                
     while (flag == 0 && i<3)
     {
           
         j=0;
         while (flag == 0 && j<3)
         {
             
             if (A[i][j]==0)
             {
                            
                            A[i][j] = 250;
                            
                            ask = check2(A,i,j);                                  
                            
                            B[i][j]=ask;
                            
                            if (B[i][j]>=B[m][n])
                            {
                                                m=i;
                                                n=j;
                            }
                            
                            A[i][j] = 0;
             }
             
        
         j=j+1;
                                
         }            
     
     i=i+1;
     }
     
      A[m][n]=250;
     
     
     
          
                 
     
}
 
int check2 (int A[][3], int i, int j)
{
    
    int sum1=0,sum2=0,sum3=0,sum4=0;
    for (int k=0;k<3;k++)
    {
        sum1=sum1+A[i][k];
        sum2=sum2+A[k][j];
    }
    if (i==j)
    sum3=A[0][0]+A[1][1]+A[2][2];
    
    if (i+j==2)
    sum4=A[2][0]+A[1][1]+A[0][2];
    
    if ((sum1+sum2)==1500 || (sum2+sum3)==1500 || (sum3+sum4)==1500 || (sum4+sum1)==1500 || (sum1+sum3)==1500 || (sum2+sum4)==1500 )      
                  return (5);
    
    
    if (sum1==750 || sum2==750 || sum3==750 || sum4==750)      
                  return (4);
                                 
                                
    if (sum1==650 || sum2==650 || sum3==650 || sum4==650)
                  return (3);
    
    
    if (sum1==500 || sum2==500 || sum3==500 || sum4==500)
                  return (2);
                                    
    else 
    
                  return (1);                            
                                
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
            printf("\n\nMAKE YOUR CHOICE PLAYER\n");
         else
            printf("\n\nMAKE YOUR CHOICE COMP\n"); 

}


