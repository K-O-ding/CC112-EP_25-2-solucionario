#include<iostream>
#include<cstring>
using namespace std;

void elim_duplicados(char* str, int n);
void convertir_minusc(char* str, int n);
void reemplazar_pos(char* str);
void imprimirCadena(char* str, int n);

int main(){
    char ejemplo[] = "  Hola  MUndo";
    cout<<"cadena original:"<<endl;
    imprimirCadena(ejemplo, strlen(ejemplo));

    cout<<"cadena modificada:"<<endl;
    elim_duplicados(ejemplo, strlen(ejemplo));
    convertir_minusc(ejemplo, strlen(ejemplo));
    reemplazar_pos(ejemplo);

    imprimirCadena(ejemplo, strlen(ejemplo));

    return 0;
}

void elim_duplicados(char* str, int n){
    char* escritor = str;
    char* lector = str;
    int ctr=0;

    for (int i = 0; i < n; i++)
    {
        if (*(lector) == ' ')
        {
            ctr++;
        }else
        {
            ctr= 0;
        }
        if (ctr==2 )
        {
            lector++;
            ctr=0;
        }

        *(escritor) = *(lector);
        *(str) = *(escritor);

        escritor++;
        lector++;
        str++;
    }
    
    
}
void convertir_minusc(char* str, int n){
    for (int i = 0; i < n; i++)
    {
        *(str+i) = tolower(*(str+i));
    }
    
}
void reemplazar_pos(char* str){
    int len_original = strlen(str);
    int crecimiento = 0;

     for (int k = 0; k < len_original; k++) 
     {
        if (str[k] == 'o' || str[k] == 'u') 
        {
            crecimiento++;
        }
    }

    int len_nueva = len_original + crecimiento;
    str[len_nueva] = '\0'; 

    char* lector = str + len_original - 1;
    
    char* escritor = str + len_nueva - 1;

    while (lector >= str) 
    { 
        if (*lector == 'o') 
        {
        // la notacion *p-- significa que accede al valor apuntado por 'p' y luego de la operacion decrementa su valor
            *escritor-- = '5'; 
            *escritor-- = '1';
        } else if (*lector == 'u') 
        {
            *escritor-- = '1';
            *escritor-- = '2';
        } else if (*lector == 'a') 
        {
            *escritor-- = '1';
        } else if (*lector == 'e') 
        {
            *escritor-- = '5';
        } else if (*lector == 'i') 
        {
            *escritor-- = '9';
        } else 
        {
            *escritor-- = *lector;
        }
        lector--;
    }
}
void imprimirCadena(char* str, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<*(str+i);
    }
    cout<<endl;
}