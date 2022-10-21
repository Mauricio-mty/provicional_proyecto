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
void AgregarMiembros();
void EliminarEquipo();
void EliminarMiembro();
void BuscarEquipo():
void MostrarPartidos();
void MostrarResultados();
void Ramdom();

int main(){

}

//Agregar Equipo(Mauricio)
void AgregarEquipo(){};

//Agregar Miembro(Mauricio)
void AgregarMiembros(){};

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














