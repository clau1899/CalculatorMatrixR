#include <iostream>

using namespace std;

int **mat1,**mat2,**mat3;//declaramos las matrices
int f,c,f1,c1,f2,c2,i,j,k;//declaramos los enteros que usaremos, filas y columnas y los iteradores para usar recursividad

//LA PLANTILLA DE LAS FUNCIONES QUE USAREMOS
void iniciar (int **,int, int,int);
void aCeros(int **,int, int,int,int);
void elementos(int **,int,int,int,int);
void mayor(int **,int **,int **,int,int,int,int);
void menor(int**,int**,int**,int,int,int,int);
void promedio(int**,int**,int**,int,int,int,int);
void sumar(int**,int**,int**,int,int,int,int);
void restar(int**, int**, int**,int,int,int,int);
void multip(int**, int**, int**,int,int,int,int,int,int,int);
void imprimir(int**,int,int,int,int);
void borrar(int **,int,int);
int elegir(int,int,int,int,int**,int**);

int main()
{
    cout<<"Filas de la primera matriz: \n";//pedimos nro de filas de la primera
    cin>>f1;//se almacena en f1
    cout<<"Columnas de la primera matrix: \n";
    cin>>c1;//el numero de columnas de la primera de almcena en c1
    cout<<"Filas de la segunda  matriz: \n";
    cin>>f2;//el numero de filas de la segunda se almacena en f2
    cout<<"Columnas de la segunda  matriz: \n";
    cin>>c2;//el numero de columnas de la segunda se almacena en c2
    int**mat1= new int*[f1];//reservamos memoria de las matrices, a los apuntadores
    int**mat2= new int*[f2];//lo mismo con la matriz segunda
    iniciar(mat1,f1,c1,i);//llamamos a la funcion iniciar para separar la memoria para cada posicion
    iniciar(mat2,f2,c2,i);//lo mismo para la segunda matriz

    cout<< "\n" <<"Ingresa los elementos de la matriz 1"<<"\n";
    elementos(mat1,f1,c1,i,j);//ingresamos los elementos con ayuda de la funcion elementos (esta mas abajo)
    cout<< "\n" <<"Ingresa los elementos de la matriz 2"<<"\n";
    elementos(mat2,f2,c2,i,j);//hacemos lo mismo con la segunda matriz
    cout<<"OPCIONES: "<<"\n";//se iba a usar un switch pero había una condicion adicional que no lo permitia
    cout<<"Presiona 1 para hallar los Mayores Elementos"<<"\n";
    cout<<"Presiona 2 para hallar los Menores Elementos"<<"\n";
    cout<<"Presiona 3 para hallar el promedio de los Elementos"<<"\n";
    cout<<"Presiona 4 para sumar las Matrices"<<"\n";
    cout<<"Presiona 5 para restar las Matrices"<<"\n";
    cout<<"Presiona 6 para multiplicar las Matrices"<<"\n";//se pide al usuario que digite un numero y se guarda en una variable "x"
    elegir(f1,c1,f2,c2,mat1,mat2);//llamamos a la funcion elegir para que esta a su vez llame a la funcion correspondiente segun lo que digito el usuario
    return 0;

}
void iniciar(int**mat,int f,int c,int i=0){
    if(i==f){//cuando se hayan recorrido todas las filas
        return;//se acaba la recursion
    }
    *(mat+i)=new int[c];//ira avanzando por cada fila almacenando para columna, es decir separa memoria para cada posicion
    return iniciar(mat,f,c,i+1);//mientras que i no reccorra toda la mtriz, se repite el proceso, pero i va aumentadno de 1 en 1
}
void aCeros(int**mat,int f,int c,int i=0,int j=0){
    if(j==c){//cuando haya pasado por todas las columnas:
        return aCeros(mat,f,c,i+1,0);//pasamos a las filas y aumentando de 1 en 1
    }
    if(i==f){//cuando se haya recorrido toda la matriz termina
        return;
    }
    *(*(mat+i)+j)=0;//mientras que los iteradores no sean iguaes al numero de filas, cada elemento se iguala a 0
    return aCeros(mat,f,c,i,j+1);//se llama de nuevo la funcion aumentando solo columnas porque la filas se incrementan en la primera condicion. sin recursion son 2 fors anidados
}
void elementos(int**mat,int f,int c,int i=0, int j=0){
    int elemento;//declaramos una variable llamada elemento
    if(j==c)//cuando haya terminado de reccorrer columnas: se pasa a las filas
        return elementos(mat,f,c,i+1,0);//se repite el proceso recorriendo las filas una a una
    if(i==f)
        return;//cuando ya se han recorrido todas la filas se acaba la recursion
    cout<<"El elemento de la posición ["<<i<<"] ["<<j<<"] es: ";//se pide al usuario los valores
    cin>>elemento;//se guarda en la var. elemento
    *(*(mat+i)+j)=elemento;//se guarda cada valor en la posicion de la matriz
    return elementos(mat,f,c,i,j+1);//se aumenta la posiccion de las columnas
}
void mayor(int**mat1, int**mat2, int**mat3,int f, int c,int i=0, int j=0){
    if(j==c){//cuando haya terminado de reccorrer columnas:
        return mayor(mat1,mat2,mat3,f,c,i+1,0);//se pasa a las filas, aumentando en 1
    }
    if(i==f){//cuando se haya recorrido todas las filas
        return;//se acaba el proceso
    }
    if ((*(*(mat1+i)+j) > *(*(mat2+i)+j))){//se comparan los elemtos de ambas matrices que esten en las mismas posiciones
        *(*(mat3+i)+j)=*(*(mat1+i)+j);//si el de la primera matriz es mayor entonces se agrega a la nueva matriz, asi con todos los elemntos
    }//al final muestra una matriz con todos los valores mayores de ambas matrices
    else
        *(*(mat3+i)+j)= *(*(mat2+i)+j);//si el de la segunda matriz es mayor al de la primera:se agrega el elemento de la segunda matriz
    return mayor(mat1,mat2,mat3,f,c,i,j+1);//se llama de nuevo a la funcion para que recorra la matriz, aumntando las columnas
}
void menor(int**mat1, int**mat2, int**mat3,int f, int c,int i=0, int j=0){// para el menor se utiliza la misma logica que el de arriba
    if(j==c){//cuando haya terminado de reccorrer columnas:
        return menor(mat1,mat2,mat3,f,c,i+1,0);//se pasa a las filas, aumentando en 1
    }
    if(i==f){//cuando se haya recorrido todas las filas
        return;//se acaba el proceso
    }
    if ((*(*(mat1+i)+j) < *(*(mat2+i)+j))){//se comparan los elemtos de ambas matrices que esten en las mismas posiciones
        *(*(mat3+i)+j)=*(*(mat1+i)+j);//si el de la primera matriz es menor entonces se agrega a la nueva matriz, asi con todos los elemntos
    }//al final muestra una matriz con todos los valores mayores de ambas matrices
    else
        *(*(mat3+i)+j)= *(*(mat2+i)+j);
    return menor(mat1,mat2,mat3,f,c,i,j+1);//se llama de nuevo a la funcion aumentando columnas
}
void promedio(int**mat1, int**mat2, int**mat3,int f, int c,int i=0, int j=0){
    if(j==c){//cuando se haya recorrido todas las columnas todas las posiciones
        return promedio(mat1,mat2,mat3,f,c,i+1,0);//se pasa a  recorrer las filas
    }
    if(i==f){//cuando se recorre tdoas las filas
        return;//se termina el proceso
    }
    *(*(mat3+i)+j)= (*(*(mat1+i)+j) + *(*(mat2+i)+j))/2;//se saca el promedio de los valores en las mismas psiciones, por lo tanto se suman y se divide entre. el resultado se almacena en una tercer amtriz
    return promedio(mat1,mat2,mat3,f,c,i,j+1);//se llama de nuevo aumentado las colunmas para recorrer todo
}
void sumar(int**mat1, int**mat2, int**mat3,int f, int c,int i=0, int j=0){
    if(j==c){//cuando se haya recorrido todas las columnas todas las posiciones
        return promedio(mat1,mat2,mat3,f,c,i+1,0);//se pasa a  recorrer las filas
    }
    if(i==f){//cuando se recorre tdoas las filas
        return;//se termina el proceso
    }
    *(*(mat3+i)+j)= *(*(mat1+i)+j) + *(*(mat2+i)+j);//se suma los valores de las matrices y coloca en el lugar correspondiente de la tercera matriz
    return sumar(mat1,mat2,mat3,f,c,i,j+1);//se llama de nuevo para la recursion y se aumenta las columnas
}
void restar(int**mat1, int**mat2, int**mat3,int f, int c,int i=0, int j=0){
    if(j==c){//cuando se haya recorrido todas las columnas todas las posiciones
        return promedio(mat1,mat2,mat3,f,c,i+1,0);//se pasa a  recorrer las filas
    }
    if(i==f){//cuando se recorre tdoas las filas
        return;//se termina el proceso
    }
    *(*(mat3+i)+j)= *(*(mat1+i)+j) - *(*(mat2+i)+j);//se resta los valores de las matrices y coloca en el lugar correspondiente de la tercera matriz
    return restar(mat1,mat2,mat3,f,c,i,j+1);//se llama de nuevo para la recursion y se aumenta las columnas
}
void multip(int**mat1, int**mat2, int**mat3,int f1, int c1,int f2,int c2,int i=0, int j=0,int k =0){
    if(c1!=f2){//si las columnas de la primeroa mat no conincide con el nro de filas de la segunda:
        cout<<"no se puede realizar la multiplicacion de matrices "<<"\n";//se no se puede multiplicar las matrices
        return;
    }
    if(k==f2)//cuando se recorre hasta la ultima fila de segunda mat
        return multip(mat1,mat2,mat3,f1,c1,f2,c2,i,j+1,0);//se pasa a recorrer cada columna de
    if(j==c2)//cuando se recorre hasta la columna fila de segunda mat
        return multip(mat1,mat2,mat3,f1,c1,f2,c2,i+1,0,k);//se recorren las filas de la primera matriz
    if(i==f1)//cuando se recorre hasta la ultima fila de primera mat
        return;//se acaba todo, caso de parada
    *(*(mat3+i)+j)=*(*(mat3+i)+j)+(*(*(mat1+i)+j) * *(*(mat2+i)+j));//mientran no sean iguales, se va suamndo las multiplicaciones de los posiciones y se agrega al final en la pos coresp de la mat3
    return multip(mat1,mat2,mat3,f1,c1,f2,c2,i,j,k+1);//mienttras sean menores, se llama de nuevo a la funcion, aumentando las filas de la segunda matriz
}
void imprimir(int**mat,int f,int c,int i=0, int j=0){
    if(j==c){//cuando se haya recorrido todas las columnas todas las posiciones
        cout<<"\n";//saltode linea para dar aspecto de matriz
        return imprimir(mat,f,c,i+1,0);//se llama a la funcion auemntando las filas
    }
    if(i==f)//cuando se haya reocrrido todas las filas
        return;//se acaba el proceso
    cout<<*(*(mat+i)+j)<<" ";//si no se ha recorrido todas las filas se muestra las posicion con una espacio al lado
    return imprimir(mat,f,c,i,j+1);//se llama de nuevo la funcion aumentando las columnas
}
void borrar(int**mat,int f,int i=0){//Funcion que borra el espacio asignado a una matriz
    if(i==f){//cuando se haya reocrrido todas las filas
        delete []mat;//se borra en si toda la mat creada
        return;//fin
    }
    delete [] mat[i];//se borra cada posicion, sse accesa a las filas
    return borrar(mat,f,i+1);//se van aumentando las filas, para borrar todo
}
int elegir(int f1,int c1,int f2,int c2,int **mat1,int **mat2)
{
    void (*ptrCalculadora)(int**,int**,int**,int,int,int,int);//plantilla de las varibles a usar
    int x=0;//declaracion de variable cuando se le pide al usuario que elija una opcion
    cout<<"Elija una opción: "<<endl;
    cin>>x;//se almacena en x
    if(x==1){//si lo que eligio el usuario es 1
        ptrCalculadora=mayor;//llama a la funcion mayor, con sus paramteros
    }
    else if(x==2){//si lo que eligio el usuario es 2
        ptrCalculadora=menor;//llama a la funcion menor, con sus paramteros
    }
    else if(x==3){//si lo que eligio el usuario es 3
        ptrCalculadora=promedio;//llama a la funcion promedio, con sus paramteros
    }
    else if(x==4){//si lo que eligio el usuario es 4
        ptrCalculadora=sumar;//llama a la funcion sumar, con sus paramteros
    }
    else if(x==5){//si lo que eligio el usuario es 5
        ptrCalculadora=restar;//llama a la funcion restar, con sus paramteros
    }
    if(x!=6)//si no se eligio multiplicacion
    {
        if(f1!=f2 || c1!=c2){//debemos asegurarnos que las matrices son de las mismas dimensiones
            cout<<"No se puede realizar esta operacion"<<"\n";// si no lo es, se informa al usuraio qie no se podra operar
            borrar(mat1,f1);//se llama a la funcion borrar para eliminar la memoria reservada para la primera matriz
            borrar(mat2,f2);//se llama a la funcion borrar para eliminar la memoria reservada para la segunda matriz
            return 0;
        }
        int**mat3= new int*[c1];//si son de las mismas dimensiones:
        iniciar(mat3,f1,c1,i);//se reserva memoria para la nueva matriz resultante
        ptrCalculadora(mat1,mat2,mat3,f1,c1,0,0);//se llama a la opcion que elegimos
        imprimir(mat3,f1,c1);//se muestra al usuario la matriz resultado de la operacion que eligio
        borrar(mat3,f1);//se elimina la memoria reservada on la funcion borrar
    }
    if(x==6){//si lo que eligio el usuario es 6
        int**mat3= new int*[c1];//se declara la tercera matriz con numero de  columnas iguales
        iniciar(mat3,f1,c2,i);//se reserva memorria para la tercer amatriz
        aCeros(mat3,f1,c2,i);//se iguala a 0 todos sus elementos
        multip(mat1,mat2,mat3,f1,c1,f2,c2);// se llama a la funcion multiplicar
        imprimir(mat3,f1,c2);// se muestra al usuario con la funcion imprimir
        borrar(mat3,f1);//se elimina la memoria reservada para la tercer matriz
    }
    borrar(mat1,f1);//sea que elija una opcion que cumpla las condicion o no, al final simpre se elimina la memoria reservada de la matriz 1
    borrar(mat2,f2);//sea que elija una opcion que cumpla las condicion o no, al final simpre se elimina la memoria reservada de la matriz 2
}
