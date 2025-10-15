#include<iostream>
#include<iomanip>
using namespace std;

void imprimirLista(int*, float*, int n);
void mergeSort(int * hash, float* idx, int inicio, int final);
void merge(int * hash, float* idx, int inicio, int medio, int final);
void buscarMediciones(int*, float*, int n, int valor);

int main(){

    const int MAX = 100;
    int hash[MAX] = {500, 200, 500, 100, 300};

    float idx[MAX] = {101, 102, 103, 104, 105};

    int n = 5;

    cout<<"\nlista original: "<<endl;
    imprimirLista(hash, idx, n);

    cout<<"\nlista ordenada:"<<endl;
    mergeSort(hash, idx, 0, n-1);
    imprimirLista(hash, idx, n);

    buscarMediciones(hash, idx, n, 500);

    return 0;
}

void imprimirLista(int* hash, float* idx, int n){
    cout<<fixed<<setprecision(0);
    cout<<right<<setw(8)<<"indice"<<setw(14)<<"documento"<<setw(14)<<"hash"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<setw(8)<< i <<setw(14)<<*(idx +i)<<setw(14)<<*(hash+i)<<endl;
    }
    cout<<endl;
}
void mergeSort(int * hash, float* idx, int inicio, int final){
    if (inicio>=final)
    {
        return;
    }

    int medio  = inicio + (final - inicio)/2;

    mergeSort(hash, idx, inicio, medio);
    mergeSort(hash, idx, medio+1, final);
    merge(hash, idx, inicio, medio, final);
}
void merge(int * hash, float* idx, int inicio, int medio, int final){
    int n1 = medio - inicio + 1;
    int n2 = final - medio;

    //Arreglos temporales para almacenar las mitades
    int temp_hash_izq[n1], temp_hash_der[n2];
    float temp_idx_iz[n1], temp_idx_der[n2];

    for (int i = 0; i < n1; i++)
    {
        *(temp_hash_izq + i) = *(hash + inicio + i);
        *(temp_idx_iz + i) = *(idx + inicio + i);
    }
    for (int j = 0; j < n2; j++)
    {
        *(temp_hash_der + j) = *(hash + medio + 1+ j);
        *(temp_idx_der + j) = *(idx + medio +1 +j);
    }
    
    //indices
    int i = 0, d = 0, k = inicio;

    while (i<n1 && d<n2)
    {
        if (*(temp_hash_izq + i) <= *(temp_hash_der + d))
        {
            *(hash + k) = *(temp_hash_izq + i);
            *(idx + k) = *(temp_idx_iz + i); 
            i++;
        }else
        {
            *(hash + k) = *(temp_hash_der + d);
            *(idx + k) = *(temp_idx_der + d); 
            d++;
        }
        k++;
    }
    
    while (i < n1)
    {
        *(hash + k) = *(temp_hash_izq + i);
        *(idx + k) = *(temp_idx_iz + i);
        i++;
        k++;
    }
    while (d < n2)
    {
        *(hash + k) = *(temp_hash_der + d);
        *(idx + k) = *(temp_idx_der + d);
        d++;
        k++;
    }
    
    
    
}
void buscarMediciones(int* hash, float* idx, int n, int valor){
    int inicio = 0, fin = n-1;
    int encontrado = -1;

    while (inicio<=fin)
    {
        int medio = inicio + (fin - inicio) / 2;
        if (*(hash + medio) == valor)
        {
            encontrado = medio;
            break;
        }
        if (*(hash + medio) < valor)
        {
            inicio =  medio +1;
        }else
        {
            fin = medio - 1;
        }
    }
    
    if (encontrado != -1)
    {
        int i = encontrado;
        while (i>=0 && *(hash + i)==valor)
        {
            i--;
        }
        int inicio_bloque = i+1;

        int j = encontrado;
        while (j<n && *(hash + j)==valor)
        {
            j++;
        }
        int fin_bloque = j-1;

        cout<<"lista con hash = "<<valor<<":"<<endl;
        cout<<right<<setw(8)<<"indice"<<setw(14)<<"documento"<<setw(14)<<"hash"<<endl;
        for (int k = inicio_bloque; k <= fin_bloque; k++)
        {
            cout<<setw(8)<< k <<setw(14)<<*(idx +k)<<setw(14)<<*(hash+k)<<endl;
        }
        cout<<endl;
    }else{
        cout<<"No se econtraron indices para el hash solicitado"<<endl;
    }
    
}