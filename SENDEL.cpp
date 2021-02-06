#include <iostream>
#include <cmath>
using namespace std;


void gaussSeidel(int A[][3], int B[], int size){
 double EPSILON = 0.00001; // error iterativo como tolerancia

 double S[size]; //Array with the solutions
 double OS[size]; //Array with old solutions
 double E[size]; //Array with th error of each variable
 for (int i = 0; i < size; ++i)
 {
 S[i] = 0; //We initialize each solution at 0;
 OS[i] = 0; //Pseudo minus infinity at each old solution;

 E[i] = (S[i]-OS[i]); //Error iterativo absoluto
 //E[i] = (S[i]-OS[i])/S[i]; // Error iterativo relativo
 //E[i] = ((S[i]-OS[i])/S[i])*100; // Error iterativo porcentual
 }

 bool errorCheck = false; //For each variable we have a

 int counter=0;
 
 while(!errorCheck){
 cout << "Solution " << counter << endl;
 for (int i = 0; i < size; ++i)
 {
 double sum = 0;
 for (int j = 0; j < size; ++j)
 {
 if (j != i)
 {
 sum += A[i][j]*S[j];
 }
 }
 OS[i] = S[i]; //The old value is the actual value
 S[i] = (B[i] - sum)/A[i][i]; //The actual value changes to the substitution of the variable

 E[i] = (S[i]-OS[i]); //Error iterativo absoluto
 //E[i] = (S[i]-OS[i])/S[i]; // Error iterativo relativo
 //E[i] = ((S[i]-OS[i])/S[i])*100; // Error iterativo porcentual

 cout << "( " << S[i] << ", " << abs(E[i]) << " )";


 }
 cout << endl;

 for (int i = 0; i < size; ++i)
 {
 if(abs(E[i]) > EPSILON){
 break;
 }
 errorCheck = true;
 }
 counter++;
 }

 cout << "FINAL ANSWER" << endl;
 for (int i = 0; i < size; ++i)
 {
 cout << S[i] << ", ";
 }
 cout << endl;
 cout << "it took " << counter << " times to terminate";
}

int main(){
 // int size = 4;
 // int matrix[][4] = {{1,-2,2,-3},{3,4,-1,1},{2,-3,2,-1},{1,1,-3,-2}};
 // int solutions[] = {15,-6,17,-7};

 int size = 3;
 int matrix[][3] = {{2,1,-1},{1,-2,2},{3,-2,1}};
 int solutions[] = {1,3,2};

 gaussSeidel(matrix, solutions, size);
 
 return 0;
}

