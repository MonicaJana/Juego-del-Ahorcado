#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

string palabraRandom(){
    string palabras[]={"cama","barco","computador","manzana","cruz","matematica"};
    int numero;
    srand(time(NULL));
    numero=0+rand()%(6+1-0);
    return palabras[numero];
}
void dibujar(int fallos,char dibujo[3][3]){
    if (fallos==1)
    {   
        cout<<"\nDibujare la cabeza\n\n";
        dibujo[0][1]='O';
    }else if (fallos==2)
    {
        cout<<"\nDibujare el cuerpo\n\n";
        dibujo[1][1]='|';
    }else if (fallos==3)
    {
        cout<<"\nDibujare el brazo izquierdo\n\n";
        dibujo[1][0]='/';
    }else if (fallos==4)
    {
        cout<<"\nDibujare el brazo derecho\n\n";
        dibujo[1][2]='\\';
    }else if( fallos==5){
        cout<<"\nDibujare la pierna izquierda\n\n";
        dibujo[2][0]='/';
    }else if (fallos==6)
    {
        cout<<"\nDibujare la pierna derecha\n\n";
        dibujo[2][2]='\\';
    }
        
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (dibujo[0][0]==dibujo[i][j] || dibujo[0][2]== dibujo[i][j] || dibujo[2][1]== dibujo[i][j])
            {
                cout<<' ';
            }else{
                cout<<dibujo[i][j];
            }
        }
        cout<<endl;
    }
}
bool jugar(string palabraAdivinar,char temporal[],int& aciertos, int longitud){
    char caracter;
    bool bandera=false;
    cout<<"\n\nIngresa una letra: ";
    cin>>caracter;
    for (int i = 0; i < longitud; i++)
    {
        if (palabraAdivinar.at(i)==caracter)
        {
            temporal[i]=caracter;
            aciertos+=1;
            bandera=true;
        }
    }
    return bandera;
}
int main(){ 
    int opcion;
    do
    {
        cout<<"\n\n        JUEGO DEL AHORCADO         "<<endl;
        cout<<"1. Jugar"<<endl;
        cout<<"2. Salir"<<endl;
        cout<<"Elija una opcion: ";
        cin>>opcion;
        if (opcion==1)
        {   
            cout<<"--------------Jugando------------\n\n";
            int vidas=6;
            int fallos=0;
            int aciertos=0;
            char dibujo[3][3]={' '};
            char temporal[17]={' '};
            string palabraAdivinar=palabraRandom();
            int longitud=palabraAdivinar.size();
            cout<<"Adivina la palabra: ";
            for (int i = 0; i < longitud; i++)
            {
                cout<<'_';
                temporal[i]='_';
            }
            do 
            {
                if (jugar(palabraAdivinar,temporal,aciertos,longitud)) {
                    cout<<"\nBuen Trabajo!\n";
                    cout<<"Hasta el momento tu palabra es: ";
                    for (int i = 0; i < longitud; i++)
                    {
                        cout<<temporal[i];
                    }
                }else{
                    fallos+=1;
                    vidas-=1;
                    dibujar(fallos,dibujo);
                    cout<<"\nTe quedan "<<vidas<<" vidas"<<endl;
                }
            }while (vidas>0 && aciertos!=longitud);
            if (vidas>0 && aciertos==longitud )
            {
                cout<<"\nGANASTE! \n";
                cout<<"La palabra es: "<<palabraAdivinar<<endl;
            }else{
                cout<<"\nPERDISTE! ";
                cout<<"La palabra era: "<<palabraAdivinar<<endl;
                
            }
        }
    } while (opcion<1 || opcion>2 || opcion!=2);
    cout<<"\n\nAdios!";
    return 0;
}
