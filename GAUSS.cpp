#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include<math.h>
 
void llena_matriz(float m [50][50],int n)
{
 
int a,b;
float A[50][50],B[50],cte,aux;
      printf("\n\t\tMETODO DE GAUSS-JORDAN\n");
      printf("\nIngrese el numero de ecuaciones del sistema: ");
      scanf("%i",&n);
 
      for(a=0;a<n;a++)
       {
        for(b=0;b<n;b++)
          {
           printf("Coef. (%i,%i) ",a+1,b+1);
           scanf("%f",&A[a][b]);
           }
           printf("Termino independiente Ec. %i: ",a+1);
           scanf("%f",&B[a]);
        }
}
 
void escribir_matriz(float m[50][50],int n)
{
       int i,j;
       printf("  \n  ");
       for(i=0;i<n;i++)
       {
           for(j=0;j<n+1;j++)
           {
               printf("%f\t",m[i][j]);
           }
           printf("\n");
       }
  }
 
 
void gauss(float m[50][50],int n)
{
     float piv,x,y;
     int i,ii,j;
      for(i=0;i<n;i++)
      {
          for (ii=0;ii<n;ii++)
          {
               if (ii!=i)
               {
                x = - m[i][i];
                y=  m[ii][i];
                for (j=0;j<n+1;j++)
                    m[ii][j]=m[ii][j]/y*x+m[i][j];
                }
          }
      }
}
 
int main()
{
    int n;
    float a[50][50];
     scanf("%i",&n);
    llena_matriz(a,n);
    escribir_matriz(a,n);
    gauss(a,n);
    escribir_matriz(a,n);
    getch();
    return 0;
}
