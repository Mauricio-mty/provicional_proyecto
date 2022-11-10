#include <iostream>
#include ".\proyecto.cpp" 


using namespace std;



int main(){
     team *first =NULL;
    /*team *first;
    first->next=NULL;
    first->previous=NULL;*/
    string name,pais;
    int point=0,members_team=0;

    for(int i=0;i<2;i++){
        fflush(stdin);
        cout<<"name:";
        cin>>name;
        cout<<"Pais:";
        cin>>pais;
        cout<<"puntos:";
        cin>>point;
        cout<<"Numero integrantes:";
        cin>>members_team;
        AgregarEquipo(first,name,pais,point,members_team);
    }
}


