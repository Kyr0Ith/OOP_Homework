/*
ИДЗ 2
Закрятин Касьян
Б9120-09.03.04прогин, подгруппа 4
Вариант 3

Задана матрица размером NxM. 
Получить массив B, присвоив его k-му элементу значение 1, 
если k-я строка матрицы симметрична, и значение 0 − в противном случае.
*/

#include <iostream>
using namespace std;
 
bool SymmetricRow (int *A, int m)
{
    for (int i = 0; i < m/2; i++)    
        if(A[i]!=A[m-1-i]) return false;     
    return true;
}
 
int main()
{
    int n, m;
    cout << "n="; cin >> n;
    cout << "m="; cin >> m;
    
      int **A = new int*[n]; 
    for (int i = 0; i < n; i++)
       A[i]=new int[m];
       
       int *B = new int[n];
       
    cout << "Enter "<< n*m << " elements:\n";
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> A[i][j];
 
    cout << "Array B:\n";   
    for (int i = 0; i < n; i++)
    {
    if (SymmetricRow(A[i],m)) B[i]=1;
    else B[i]=0;
    cout << B[i] << " ";
    }
    cout << "\n";
    
return 0;
}
