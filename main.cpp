#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

// funciones diferentes facciones serie

void exploracion(int);
void guarnicion(int);
void miltar(int);
void titan(int);
void people(int);

// funciones diferentes facciones manuales

void m_exploracion(int);
void m_guarnicion(int);
void m_miltar(int);
void m_titan(int);
void m_people(int);
void variousFactions(int, int);
void uniqueFaction(int);

int main()
{

    cout << "\n-------------------------------------------------------------------------\n";
    cout << "---------------CALCULO DE PROBABILIDADES DE SHINGEKY NO KYOJIN-----------\n";
    cout << "-------------------------------------------------------------------------\n";
    cout << R"(                                                                                                                        
  ++.     -++    +++       ++++++++++++  +++++++                      ++++++++++++++++++++++             ++++           
 -++++    +++   +++-            ++       ++   ++  +                   ++++++++++++++++++++++             ++++           
   +++   +++++++++++++++    ...=++=...  +++   +++++                   +++                                ++++           
    :   ++++++++++++++++    +-  ++  :+   =                            +++                                ++++           
       +++++    +++         +=  ++  =+  ++++++++++                    +++                                ++++           
      ++++++.  .+++====     +-  ++  -+    .    +++      +++++++++     +++++++++++++++++++++              ++++=          
       +=+++    +++             ++       -+   -+-     +++  ++   +++   +++++++++++++++++++++              +++++          
 +++++   +++    +++             ++       -++++++     ++    ++    -++  +++              ++++             ++++++          
 +++++   ++++++++++++++         ++      ++    ++++++++     ++     ++- +++              ++++             +++++++         
   +++   +++    +++             ++                  ++    =++     +++ +++              ++++            +++  +++         
   +++   +++    +++          ++++++++++++=:        .++    ++      +++=+++++++++++++++++++++           .+++   +++        
   +++   +++++++++++++++             ++++           ++    ++      +++ +++++++++++++++++++++           +++    =+++       
   +++   +++++++++++++++     ++++++++++++++++++++   ++   ++       ++  +++                           ++++      ++++      
   +++-                              ++++           ++++++=      ++=  +++                          ++++        +++++    
 +++++++                   ++++++++++++++++++++++++  =+++     -+++-   +++=                       +++++          =+++++  
 +++  +++++++++++++++++++            ++++                    +++-     +++++++++++++++++++++++   ++++=             ++++  
 -=     :+++++++++++++++         ====+++-                             +++++++++++++++++++++++    ++                :+   
                                                                                                                                                                                                                                        
)";

    // Se han creado 2 switch con diferentes funcionalidades:
    // primer switch: para dividir los datos de la serie o los datos que sean ingresados para calcularle la probabilidad.
    int option1, option2, charactersEv, opDiv;
    cout << "Elija la opcion que mas le guste\n 1.Calcular tu probabilidad de vida y muerte en la serie \n 2.Ingresar datos manuales para calcular la cantidad de muertes y vidas" << endl;
    cin >> option1;
    switch (option1)
    {
        // Datos de la serie
    case 1:
        cout << "Elija la faccion al que quiere pertenecer\n 1. Tropa de Exploracion\n 2. Tropa de guarnicion\n 3. Policia Militar\n 4. Titan\n 5. Pueblo\n";
        cin >> option2;
        // segundo switch: dividision de las facciones
        switch (option2)
        {
        case 1:
            exploracion(1);
            break;

        case 2:
            guarnicion(1);
            break;

        case 3:
            miltar(1);
            break;

        case 4:
            titan(1);
            break;

        case 5:
            people(1);
            break;

        default:
            break;
        }
        break;
    // Datos manuales
    case 2:

        // ─── Pidiendo datos ───────────────────────────────────────────────────
        /*
            En esta parte se piden los datos, primero de el numero de personajes que desea evaluar
            y luego se pide de que manera quiere dividirlos, si en varias facciones o en solamente
            una faccion.
        */

        cout << "Ingrese el numero de personajes que desea evaluar:\n";
        cin >> charactersEv;

        cout << "De que manera quiere dividir los personajes?\n 1.En varias facciones\n 2. En una faccion\n";
        cin >> opDiv;

        // ─── Switch 2 ────────────────────────────────────────────────
        switch (opDiv)
        {
        case 1:
            // Se envia el numero de personajes tomado anteriormente y el contador iniciado en 0

            variousFactions(charactersEv, 0);
            break;
        case 2:

            // Se envia el numero de personajes a una funcion, para elegir la faccion de destino.
            uniqueFaction(charactersEv);
            break;

        default:
            break;
        }


        break;


    }

    return 0;
}

void uniqueFaction(int numberCharacters)
{
    // pedir los datos: A que faccion se iran los datos anteriormente solicitados.
    int optionElegida;
    cout << "En que faccion los desea agregar? \n 1.Titanes\n 2.Exploration\n 3.Garrison\n 4. Militar\n 5.People" << endl;
    cin >> optionElegida;
    // Calculando probabilidad de los datos ingresados, contrastados con la probabilidad de la serie.
    switch (optionElegida)
    {
    case 1:

        m_titan(numberCharacters);

        break;

    case 2:
        m_exploracion(numberCharacters);

        break;

    case 3:
        m_guarnicion(numberCharacters);

        break;

    case 4:
        m_miltar(numberCharacters);

        break;

    case 5:
        m_people(numberCharacters);

        break;
    default:
        break;
    }
}
void variousFactions(int numberCharacters, int counter)
{
    // ─── Creación de arreglos ────────────────────────────────────────────────────────────
    /*
        @category

        Se crearon 2 arrays, el primero contiene los valores que ingresara el usuario, se inicializan
        en 0. El siguiente es un array con los nombres de las facciones existentes, van en orden, es decir
        la pocision 0 de el numFactions es equivalente a "Titanes", la pocision 1 a "Soldados de exploracion"
    */
    int numFactions[5] = {0, 0, 0, 0, 0};
    string nameFactions[5] = {"titanes", "soldados de exploracion", "soldados de guarnicion", "policia militar", "personas civiles"};

    // ─── Ciclos─────────────────────────────────────────────────────────────
    /*
        @details

        En los ciclos se recorre 6 veces (Ya que es un valor constante que no cambiara) primero se
        evalúa que el numero de personajes sea distinto a el contador (que inicia en 0). Luego se
        creo una variable booleana llamada proceed que ejecuta el while siempre que sea "false". Dentro de
        el while se piden los datos, despues en el if, se realiza una operacion, el cual consiste en
        que al restar la suma del contador + numero ingresado a el numero de personajes tiene que ser mayor
        a ese numero de personajes ingresados:

        Ej: Ingreso 10 personajes y ya agregue otros 7 y quiero agregar 2 mas
        Entonces: (10 - (7 +  2)) <= 10
        Mientras eso se cumpla y mientras esa resta sea mayor a 0, se guardaran los datos
        si no es asi, menciona cuantos puede agregar maximo y proceed se vuelve false aún, repitiendo
        el ciclo constantemente hasta que se agregue un valor correcto.
    */

    for (int i = 0; i < 5; i++)
    {
        if (numberCharacters != counter)
        {
            bool proceed = false;
            while (proceed == false)
            {
                int num;
                cout << "Ingrese el numero de personajes de " << nameFactions[i] << endl;
                cin >> num;

                if (numberCharacters - (counter + num) <= numberCharacters && numberCharacters - (counter + num) >= 0)
                {
                    numFactions[i] = num;
                    counter += num;
                    proceed = true;
                }
                else
                {
                    cout << "Debe agregar menos personajes, limite alcanzado (maximo: " << numberCharacters - counter << " )" << endl;
                    proceed = false;
                }
            }
        }
    }
    /*Al final, la posicion de evaluacion del arreglo debe de ser mayor a 0, para que se pueda evaluar su probabilidad
    mientras esa condicion se cumpla, el dato qeu se aloje en esa posicion va a ser enviado a su respectiva funcion. */
    if (numFactions[0] != 0)
    {
        m_titan(numFactions[0]);
    }
    if (numFactions[1] != 0)
    {
        m_exploracion(numFactions[1]);
    }
    if (numFactions[2] != 0)
    {
        m_guarnicion(numFactions[2]);
    }
    if (numFactions[3] != 0)
    {
        m_miltar(numFactions[3]);
    }
    if (numFactions[4] != 0)
    {
        m_people(numFactions[4]);
    }
}
void exploracion(int cantidad)
{
    // probabilidad de muerte o de vida con los datos de la serie en base a las tropas de exploracion.
    float Total_explo = 300;
    float exploVivos = 9;
    float exploMuertes = 291;
    int opc;

    cout << "¿Desea visualizar el porcentaje de muerte o el porcentaje de vivir de los personajes de exploracion? \n Presione 1 para el de muerte y 2 para el de vivir";

    cin >> opc;
    float porcentaje_deaths = 0, porcentaje_alive = 0;
    switch (opc)
    {
    case 1:
        porcentaje_deaths = exploMuertes / Total_explo;
        porcentaje_deaths = pow(porcentaje_deaths, cantidad);

        cout << "La probabilidad de que mueras siendo tropa de exploracion es de " << porcentaje_deaths * 100 << "%" << endl;
        break;
    case 2:
        porcentaje_alive = exploVivos / Total_explo;
        porcentaje_alive = pow(porcentaje_alive, cantidad);
        cout << "La probabilidad de que vivas siendo tropa de exploracion es de " << porcentaje_alive * 100 << "%" << endl;
        break;
    default:
        break;
    }
}

void guarnicion(int cantidad)
{
    // probabilidad de muerte o de vida con los datos de la serie en base a las tropas de guarnicion
    float Total_guarni = 30218;
    float guarniVivos = 30005;
    float guarniMuertes = 213;
    int opc;
    // Seleccion de la probabilidad. Ya sea de vivir o de morir.
    cout << "¿Desea visualizar el porcentaje de muerte o el porcentaje de vivir? \n Presione 1 para el de muerte y 2 para el de vivir: ";
    cin >> opc;
    float porcentaje_deaths = 0, porcentaje_alive = 0;
    switch (opc)
    {
    case 1:
        porcentaje_deaths = guarniMuertes / Total_guarni;
        porcentaje_deaths = pow(porcentaje_deaths, cantidad);

        cout << "La probabilidad de que mueras siendo tropa de guarnicion es de " << porcentaje_deaths * 100 << "%" << endl;
        break;
    case 2:
        porcentaje_alive = guarniVivos / Total_guarni;
        porcentaje_alive = pow(porcentaje_alive, cantidad);
        cout << "La probabilidad de que vivas siendo tropa de guarnicion es de " << porcentaje_alive * 100 << "%" << endl;
        break;
    default:
        break;
    }
}

void titan(int cantidad)
{
    // probabilidad de muerte o de vida con los datos de la serie en base a los titanes
    double T_titans = 2047, titans_deaths = 2022, titans_alive = 25, percentage_deaths = 0, percentage_alive = 0;

    // Pocentaje de vida y muerte
    percentage_deaths = titans_deaths / T_titans;
    percentage_alive = titans_alive / T_titans;

    percentage_alive = pow(percentage_alive, cantidad);
    percentage_deaths = pow(percentage_deaths, cantidad);

    int opc;
    // Seleccion de la probabilidad. Ya sea de vivir o de morir.
    cout << "¿Desea visualizar el porcentaje de muerte o el porcentaje de vivir? \n Presione 1 para el de muerte y 2 para el de vivir: ";
    cin >> opc;

    switch (opc)
    {
    case 1:

        cout << "La probabilidad de que mueras siendo titan es de: " << percentage_deaths * 100 << "%" << endl;
        break;
    case 2:
        cout.precision(9);
        cout << fixed << "La probabilidad de que vivas siendo titan es de" << percentage_alive * 100 << "%" << endl;
        break;
    default:
        break;
    }
}

void people(int cantidad)
{
    // probabilidad de muerte o de vida con los datos de la serie en base a los titanes
    double T_People = 1214482, people_deaths = 259991, people_alives = 954491, percentage_deaths = 0, percentage_alives = 0;

    // Pocentaje de vida y muerte
    percentage_deaths = people_deaths / T_People;
    percentage_alives = people_alives / T_People;

    percentage_alives = pow(percentage_alives, cantidad);
    percentage_deaths = pow(percentage_deaths, cantidad);

    int opc;
    // Seleccion de la probabilidad. Ya sea de vivir o de morir.
    cout << "¿Desea visualizar el porcentaje de muerte o el porcentaje de vivir? \n Presione 1 para el de muerte y 2 para el de vivir: ";
    cin >> opc;

    switch (opc)
    {
    case 1:

        cout << "La probabilidad de que mueras siendo civil es de" << percentage_deaths * 100 << "%" << endl;
        break;
    case 2:
        cout.precision(9);
        cout << fixed << "La probabilidad de que vivas siendo civil es de" << percentage_alives * 100 << "%" << endl;
        break;
    default:
        break;
    }
}

void miltar(int cantidad)
{
    // probabilidad de muerte o de vida con los datos de la serie en base a los titanes
    float Total_poliMili = 5000;
    float poliMiliDeaths = 37;
    float poliMiliAlive = 4963;
    int opci;
    float percentDeaths = 0, livingPercent = 0;
    cout << "¿Desea visualizar el porcentaje de muerte o el porcentaje de vivir? \n Presione 1 para el de muerte y 2 para el de vivir: ";
    cin >> opci;
    switch (opci)
    {
    case 1:
        percentDeaths = poliMiliDeaths / Total_poliMili;
        percentDeaths = pow(percentDeaths, cantidad);

        cout << "La probabilidad de que mueras siendo de la policia militar es de " << percentDeaths * 100 << "%" << endl;
        break;
    case 2:
        livingPercent = poliMiliAlive / Total_poliMili;
        livingPercent = pow(livingPercent, cantidad);
        cout << "La probabilidad de que vivas siendo de la policia militar es de " << livingPercent * 100 << "%" << endl;
    default:
        break;
    }
}

void m_exploracion(int cantidad)
{
    // La funcion recibe la cantidad de personajes que se han definido para esta facción, posteriormente
    // se pregunta si desea visualizar la probabilidad de muerte o de vida. Luego, solo se multiplica
    // la cantidad por el porcentaje
    double percentage_alives = 0.97, percentage_deaths = 0.03;
    cout.precision(0);
    int opci;
    cout << "¿Desea visualizar la cantidad de soldados de exploracion que viviran o que moriran? \n Presione 1 para el de muerte y 2 para el de vivir: ";
    cin >> opci;
    switch (opci)
    {
    case 1:
        cout << fixed << "La cantidad de soldados de exploracion que moriran son: " << cantidad * percentage_deaths << endl;
        break;
    case 2:
        cout << fixed << "La cantidad de soldados de exploracion que viviran son: " << cantidad * percentage_alives << endl;
        break;
    default:
        break;
    }
}

void m_guarnicion(int cantidad)
{
    // La funcion recibe la cantidad de personajes que se han definido para esta facción, posteriormente
    // se pregunta si desea visualizar la probabilidad de muerte o de vida. Luego, solo se multiplica
    // la cantidad por el porcentaje
    double percentage_alives = 0.0075, percentage_deaths = 0.9925;
    cout.precision(0);
    int opci;
    cout << "Desea visualizar la cantidad de soldados de guarnicion que viviran o que moriran? \n Presione 1 para el de muerte y 2 para el de vivir: ";
    cin >> opci;
    switch (opci)
    {
    case 1:
        cout << fixed << "La cantidad de soldados de guarnicion que moriran son " << cantidad * percentage_deaths << endl;
        break;
    case 2:
        cout << fixed << "La cantidad de soldados de guarnicion que viviran son: " << cantidad * percentage_alives << endl;
        break;
    default:
        break;
    }
}

void m_miltar(int cantidad)
{
    // La funcion recibe la cantidad de personajes que se han definido para esta facción, posteriormente
    // se pregunta si desea visualizar la probabilidad de muerte o de vida. Luego, solo se multiplica
    // la cantidad por el porcentaje
    double percentage_alives = 0.9926, percentage_deaths = 0.0074;
    cout.precision(0);
    int opci;
    cout << "Desea visualizar la cantidad de policias militares que viviran o que moriran? \n Presione 1 para el de muerte y 2 para el de vivir: ";
    cin >> opci;
    switch (opci)
    {
    case 1:
        cout << fixed << "La cantidad de policias militares que moriran son: " << cantidad * percentage_deaths << endl;
        break;
    case 2:
        cout << fixed << "La cantidad de policias militares que viviran son:" << cantidad * percentage_alives << endl;
        break;
    default:
        break;
    }
}

void m_titan(int cantidad)
{
    // La funcion recibe la cantidad de personajes que se han definido para esta facción, posteriormente
    // se pregunta si desea visualizar la probabilidad de muerte o de vida. Luego, solo se multiplica
    // la cantidad por el porcentaje
    double percentage_alives = 0.01, percentage_deaths = 0.99;
    cout.precision(0);
    int opci;
    cout << "Desea visualizar la cantidad de titanes que viviran o que moriran? \n Presione 1 para el de muerte y 2 para el de vivir: ";
    cin >> opci;
    switch (opci)
    {
    case 1:
        cout << fixed << "La cantidad de titanes que moriran son:" << cantidad * percentage_deaths << endl;
        break;
    case 2:
        cout << fixed << "La cantidad de titanes que viviran son:" << cantidad * percentage_alives << endl;
        break;
    default:
        break;
    }
}

void m_people(int cantidad)
{
    // La funcion recibe la cantidad de personajes que se han definido para esta facción, posteriormente
    // se pregunta si desea visualizar la probabilidad de muerte o de vida. Luego, solo se multiplica
    // la cantidad por el porcentaje
    int opci;
    cout << "Desea visualizar la cantidad de civiles que viviran o que moriran? \n Presione 1 para el de muerte y 2 para el de vivir: ";
    cin >> opci;
    double percentage_alives = 0.78, percentage_deaths = 0.22;
    cout.precision(0);
    switch (opci)
    {
    case 1:
        cout << fixed << "La cantidad de civiles que moriran son:" << cantidad * percentage_deaths << endl;

        break;
    case 2:
        cout << fixed << "La cantidad de civiles que viviran son:" << cantidad * percentage_alives << endl;
        break;
    default:

        break;
    }
}
