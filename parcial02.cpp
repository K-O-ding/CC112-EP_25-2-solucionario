#include <iostream>
#include <iomanip>
using namespace std;

double promedio(double *E, int n) {
    double suma = 0.0;
    for (double *p = E; p < E + n; ++p) {
        suma += *p;
    }

    return (suma/n);
}

void diferencias(double *E, double *D, int n) {
     
     double *pd = D + 1;

     for (double *pe = E + 1; pe < E + n - 1; ++pe, ++pd) {
          *pd = (*(pe + 1) - *(pe - 1))/2.0;
     }
}

double maximo(double* arr, int n){
    double max = *(arr+0);
    for (int i = 0; i < n; i++)
    {
        if (*(arr+i) > max)
        {
            max = *(arr+i);
        }
        
    }
    return max;
}

double minimo(double* arr, int n){
    double min = *(arr+0);
    for (int i = 0; i < n; i++)
    {
        if (*(arr+i) < min)
        {
            min = *(arr+i);
        }
        
    }
    return min;
}

void e_normalizada(double *E, double *EN, int n){
    double max = maximo(E, n);
    double min = minimo(E, n);
    double *p_norm = EN;

    for (double *p_ener = E; p_ener < E + n; p_ener++, p_norm++)
    {
        *(p_norm) = (*(p_ener) - min) / ( max - min ); 
    }

    double suma = 0;
    for (double *p_norm = EN; p_norm < EN + n; p_norm++)
    {
        suma += *(p_norm);
    }
    
    for (double *p_norm = EN; p_norm < EN + n; p_norm++)
    {
        *(p_norm) = *(p_norm)/suma;
    }
    
    
}

int main(){
    const int MAX  = 10;
    double E[MAX] = {2, 3, 5, 7, 6};
    double D[MAX];
    double EN[MAX];

    int n = 5;

    double prom = promedio(E, n);

    diferencias(E,D,n);
    e_normalizada(E,EN, n);
    
    
    cout << right << setw(8) << "Indice" << setw(14) << "E_original"
    << setw(14) << "D_centrada" << setw(14) << "E_normalizada"<< endl;


    cout << fixed << setprecision(3);
    for (int i = 0; i < n; ++i) {
        cout <<setw(8) <<i << setw(14) << *(E + i);
        
        cout << setw(14) << *(D + i) << setw(14) << *(EN + i);
        
        cout << endl; 
    }

    cout << "energia promedio = " << prom <<endl;

    return 0;
}