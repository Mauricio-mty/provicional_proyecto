#include <iostream>

using namespace std;

//Informacion jugador
struct members{
    string name;
    string position;
   // members *next;
}team1[6];

//Informacion equipo
struct team{
   string name;
   string pais;
   int point;
   members *members_team;
   team * next;
   team * previous;
}

//Partidos datos
struct match{
    team* team_1;
    team* team_2;
    int points_team1;
    int points_team2;
}

void AgrgarEquipo();
//void AgregarMiembros();
members AgregarMiembros();
void EliminarEquipo();
void EliminarMiembro();
void BuscarEquipo():
void MostrarPartidos();
void MostrarResultados();
void Ramdom();

int main(){

team first;
first.next=NULL;
first.previous=NULL;



}

//Agregar Equipo(Mauricio)
void AgregarEquipo(team *pTeam,string &name,string *pais,int &point,int &members_team){
    team *newTeam = new team();
    team *tempTeam = pTeam;
   

    newTeam->name=name;
    newTeam->pais=pais;
    newTeam->point=point;
    newTeam->next=NULL;
    newTeam->previous=NULL;
    newTeam->members_team=AgregarMiembros(members_team);

    if(tempTeam==NULL){
        tempTeam=newTeam;
    }else{
       while (tempTeam!=NULL)
       {
         tempTeam=tempTeam->next;
       }
       tempTeam->next=newTeam;
       newTeam->previous=tempTeam;
       newTeam= 

       
    }
    
}

//Agregar Miembro(Mauricio)
//void AgregarMiembros(){};
//Agregar Moembro(Mauricio)
members AgregarMiembros(int *&members_team){
    members* newMembers = new members[members_team];
  
   for(int i=0;i<members_team;i++){
       fflush(stdin);
       cout<<"Integrante N° "<<i+1<<endl;
       cout<<"Nombre:";cin>>newMembers[i].name;
       cout<<"Posicion:";cin>>newMembers[i].position;        
   }
    return &newMembers;
}

//Eliminar Equipo(Fernando)
void EliminarEquipo(){};

//Eliminar Miembro(Fernando)
void EliminarMiembro(){};

//Buscar Equipo(Vanessa)
void BuscarEquipo(){};

//Buscar Miembro(Vanessa)
void BuscarMiembro(){};

//Mostrar Partido(German)
void MostrarPartidos(){};

//Mostrar Resultado(Jose)
void MostrarResultados(){};

//Resultados aleatorios(German)
void Ramdom(){};














