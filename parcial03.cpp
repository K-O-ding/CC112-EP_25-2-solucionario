#include<iostream>
#include<iomanip>
using namespace std;

void imprimirMatriz(double **mat, int l, int a){
    cout<<fixed<<setprecision(0);
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cout<<right<<setw(5);
            cout<<*(*(mat+i) +j );
        }
        cout<<endl;
    }
    cout<<endl;
}

double multiplicacion(double **mat, double** ker, int n){
    double suma = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            suma += *(*(mat+i)+j) * *(*(ker+ i)+j);
            
        }
        
    }
    return suma;
}

void convolucion(double **mat, double **ker,  double** conv, int l, int a, int n){
    for (int i = 1; i < a-1; i++)
    {
        for (int j = 1; j < l-1; j++)
        {
            
            double* sub_matriz[n];

            for(int k=0; k<n; k++){
                *(sub_matriz + k) = *(mat + i - 1 + k) + (j - 1);
            }

            *(*(conv + i) + j) = multiplicacion( sub_matriz, ker, n );
        }
    }
    
}

double maximo(double** conv, int l, int a){
    double max = *(*(conv));
    for (int i = 1; i < a-1; i++)
    {
        for (int j = 1; j < l-1; j++)
        {
            if (*(*(conv+i)+j) >max)
            {
                max = *(*(conv+i)+j);
            }
        }
    }
    return max;
}

double minimo(double** conv, int l, int a){
    double min = *(*(conv));
    for (int i = 1; i < a-1; i++)
    {
        for (int j = 1; j < l-1; j++)
        {
            if (*(*(conv+i)+j) <min)
            {
                min = *(*(conv+i)+j);
            }
        }
    }
    return min;
}


void normalizacion(double **conv, double** norm, int l, int a){
    for (int i = 1; i < a-1; i++)
    {
        for (int j = 1; j < l-1; j++)
        {
            *(*(norm+i)+j) = 255* (*(*(conv+i)+j) - minimo(conv, l, a) )/(maximo(conv, l, a) - minimo(conv, l, a));
        }
        
    }
    
}


int main(){
    const int MAX = 100;

    double imagen[MAX][MAX] ={
        {10, 10, 10, 10, 10},
        {10, 255, 255, 255, 10},
        {10, 255, 10, 255, 10},
        {10, 10, 10, 10, 10}
    };
    double conv[MAX][MAX];
    double norm[MAX][MAX];

    int a = 4;
    int l = 5;

    double *p_imagen[MAX];
    for (int i = 0; i < a; i++)
    {
        *(p_imagen + i) = *(imagen + i);
    }

    double *p_conv[MAX];
    for (int i = 0; i < a; i++)
    {
        *(p_conv + i) = *(conv + i);
    }

    double *p_norm[MAX];
    for (int i = 0; i < a; i++)
    {
        *(p_norm + i) = *(norm + i);
    }

    const int N =3;
    double kernel[N][N]={
        {-1, -1, -1},
        {-1, 8, -1},
        {-1, -1, -1},
    };

    double *p_ker[MAX];
    for (int i = 0; i < N; i++)
    {
        *(p_ker + i) = *(kernel + i);
    }



    cout<<"imagen original:"<<endl;
    imprimirMatriz(p_imagen, l, a);
    
    cout<<"kernel aplicado:"<<endl;
    imprimirMatriz(p_ker, N, N);

    convolucion(p_imagen, p_ker,  p_conv, l,  a,  N);

    cout<<"resultado de la convolucion (sin normalizar):"<<endl;
    imprimirMatriz(p_conv, l, a);

    normalizacion(p_conv, p_norm, l, a);
    cout<<"resultado de la convolucion (normalizado 0-255):"<<endl;
    imprimirMatriz(p_norm, l, a);

    return 0;
}