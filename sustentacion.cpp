#include <iostream>
#include <iomanip>
#define maximo 50
#define maxanios 20
#define maxacud 5
using namespace std;

struct ubi
{
    string direccion;
    string ciudad;
};
struct cumple
{
    int diacumple;
    int mescumple;
    int aniocumple;

};
struct carpeta
{
    int cantianios;
    int puesto[maxanios];
    float promedio[maxanios];

};
struct estudiante
{
    long int  id;
    string nombre;
    long int telefono;
    ubi ubicacion;
    int cant_acud;
    string nom_acud[maxacud];
    cumple cumpleanios;
    carpeta estudi;
    int cursoact;
    char sexo;
    int contador_primer;
};
void informacion(estudiante estudiantes[maximo], int i);
bool funcion0 (estudiante estudiantes[maximo], int cantidad);
void funcion1(estudiante estudiantes[maximo], int cantidad);
void funcion2 (estudiante estudiantes[maximo], int cantidad);
void funcion3 (estudiante estudiantes[maximo], int cantidad);
void funcion4 (estudiante estudiantes[maximo], int cantidad);
int funcion5 (estudiante estudiantes[maximo], int cantidad);
int funcion6 (estudiante estudiantes[maximo], int cantidad);
void sustentacion(estudiante estudiantes[maximo], int cantidad);
bool aniobisiesto(int anio);
int diames(int mescumple, bool bisiesto);
int main( )
{
    int opcion, cantidad;
    char opcion5;
    bool opc=false;
    estudiante estudiantes[maximo];
    cout<<"==========================================================\n";
    cout << "+++++++++++++++++++BIENVENIDO+++++++++++++++++++" << endl;
    cout<<"==========================================================\n";
    do
    {
        cout << "\nOpcion 0: Introducir datos disponibles.\n";
        cout << "Opcion 1: Lista de los estudiantes que estan en primaria.\n"; //Andres
        cout << "Opcion 2: Lista de los estudiantes que estan en bachillerato.\n"; //Andres
        cout << "Opcion 3: Nombre del estudiante que ha obtenido mas veces el primer puesto.\n"; //Pablo
        cout << "Opcion 4: Lista de los acudientes de estudiante femininos de primaria.\n"; //Andres
        cout << "Opcion 5: Borrar un estudiante o Reportar los datos completos de los estudiantes que en algun anio han tenido un promedio menor a 3.\n"; //Alejo
        cout << "Opcion 6: Agregar un estudiante.\n"; //Alejo
        cout << "Opcion 7: Fin del programa.\n";
        cin >> opcion;
        switch(opcion)
        {
        case 0:
            if (opc == false)
            {
                cout << " Ingrese cantidad de estudiantes";
                cin >> cantidad;
                opc = funcion0(estudiantes,cantidad);
            }
            else
            {
                cout <<"----------------------------------------------\n";
                cout <<"   Esta opcion ya fue ejecutada anteriormente. \n";
                cout <<"-----------------------------------------------\n";
            }
            break;
        case 1:
            funcion1(estudiantes,cantidad);
            break;
        case 2:
            funcion2(estudiantes,cantidad);
            break;
        case 3:
            funcion3(estudiantes,cantidad);
            break;
        case 4:
            funcion4(estudiantes,cantidad);
            break;
        case 5:
            cout << "a: Borrar un estudiante\n";
            cout << "b: Reportar los datos completos de los estudiantes que en algun anio han tenido un promedio menor a 3\n";
            cin >> opcion5;
            if(opcion5 == 'a')
                cantidad=funcion5(estudiantes, cantidad);
            else
            {
                if(opcion5 == 'b')
                    sustentacion(estudiantes, cantidad);
                else
                    cout <<  "Opcion invalida.";
            }
            break;
        case 6:
            cantidad=funcion6(estudiantes, cantidad);
            break;
        case 7:
            cout<<"\n==========================================================\n";
            cout << "Termina programa";
            cout<<"\n==========================================================\n";
            break;
        default:
            cout << "Favor ingresar una opcion valida";
            cout<<"\n==========================================================\n";
            break;
        }
    }
    while (opcion != 7);
}
void informacion(estudiante estudiantes[maximo], int i)
{
    char resp;
    bool bisiesto;
    int diasmes, contadorpuesto;
    contadorpuesto=0;
    do
    {
        cout << "\nIngrese ID: ";
        cin >> estudiantes[i].id;
        if ( estudiantes[i].id <= 0)
        {
            cout << endl << "ID invalido. Intentar de nuevo.";
            cout<<"\n-------------------------------------------------------\n";
        }
    }
    while (estudiantes[i].id <= 0);
    cout <<"\nIngrese nombre del estudiante: ";
    cin >> estudiantes[i].nombre;
    do
    {
        cout << "\nIngrese telefono del estudiante: ";
        cin >> estudiantes[i].telefono;
        if ( estudiantes[i].telefono < 0)
        {
            cout << endl << "Telefono invalido. Intente de nuevo";
            cout<<"\n-------------------------------------------------------\n";
        }
    }
    while (estudiantes[i].telefono < 0);
    cout << "\nIngrese direccion del estudiante: ";
    cin >> estudiantes[i].ubicacion.direccion;
    cout << "\nIngrese ciudad del estudiante: ";
    cin >> estudiantes[i].ubicacion.ciudad;
    do
    {
        cout << "Ingrese cantidad de acudientes (Minimo: 1 Maximo: 5): ";
        cin >> estudiantes[i].cant_acud;
        if( estudiantes[i].cant_acud < 1 || estudiantes[i].cant_acud > 5)
        {
            cout << endl << "Cantidad de acudientes invalido. Intente de nuevo";
            cout<<"\n-------------------------------------------------------\n";
        }
    }
    while( estudiantes[i].cant_acud < 1 || estudiantes[i].cant_acud > 5);
    for (int h=0; h< estudiantes[i].cant_acud ; h++)
    {
        cout<<"Ingrese nombre del acudiente: ";
        cin>> estudiantes[i].nom_acud[h];
    }
    cout << "\nIngrese dia de cumpleanios del estudiante: ";
    cin >>estudiantes[i].cumpleanios.diacumple;
    cout << "\nIngrese mes de cumpleanios del estudiante: ";
    cin >> estudiantes[i].cumpleanios.mescumple;
    cout << "\nIngrese anio de cumpleanios del estudiante: ";
    cin >> estudiantes[i].cumpleanios.aniocumple;
    bisiesto = aniobisiesto(estudiantes[i].cumpleanios.aniocumple);
    diasmes = diames( estudiantes[i].cumpleanios.mescumple , bisiesto);
    do
    {
        if(estudiantes[i].cumpleanios.diacumple > diasmes || estudiantes[i].cumpleanios.diacumple<1)
        {
            cout << "Dia Invalido. Intente de nuevo";
            cout << "\nIngrese dia de cumpleanios del estudiante: ";
            cin >>estudiantes[i].cumpleanios.diacumple;
        }
    }
    while(estudiantes[i].cumpleanios.diacumple > diasmes || estudiantes[i].cumpleanios.diacumple<1);
    do
    {
        if(estudiantes[i].cumpleanios.mescumple > 12 || estudiantes[i].cumpleanios.mescumple<1)
        {
            cout << "Mes Invalido. Intente de nuevo";
            cout << "\nIngrese mes de cumpleanios del estudiante: ";
            cin >>estudiantes[i].cumpleanios.mescumple;
        }
    }
    while(estudiantes[i].cumpleanios.mescumple > 12 || estudiantes[i].cumpleanios.mescumple<1);
    do
    {
        if(estudiantes[i].cumpleanios.aniocumple > 2015 || estudiantes[i].cumpleanios.aniocumple < 1900)
        {
            cout << "Anio Invalido. Intente de nuevo";
            cout << "\nIngrese anio de cumpleanios del estudiante: ";
            cin >>estudiantes[i].cumpleanios.aniocumple;
        }
    }
    while(estudiantes[i].cumpleanios.aniocumple > 2015 || estudiantes[i].cumpleanios.aniocumple<1900);
    do
    {
        cout<< "\nIngrese cantidad de años que ha estado en el colegio: ";
        cin >>estudiantes[i].estudi.cantianios ;
        if ( estudiantes[i].estudi.cantianios < 0)
        {
            cout << endl << "Cantidad de cursos invalida. Intenta de nuevo.";
            cout<<"\n-------------------------------------------------------\n";
        }
    }
    while ( estudiantes[i].estudi.cantianios < 0);
    for (int k = 0; k < estudiantes[i].estudi.cantianios ; k++)
    {
        cout << "\nIngrese numero de puesto del estudiante en el anio " << k+1 << ": ";
        cin >> estudiantes[i].estudi.puesto[k];
        if ( estudiantes[i].estudi.puesto[k] == 1)
        {
            contadorpuesto = contadorpuesto + 1;
        }
        cout << "\nIngrese promedio del estudiante en el anio " << k+1 << ": ";
        cin >> estudiantes[i].estudi.promedio[k] ;
    }
    estudiantes[i].contador_primer = contadorpuesto;
    do
    {
        cout << "\nIngrese curso actual del estudiante: " << estudiantes[i].nombre << ": ";
        cin >> estudiantes[i].cursoact ;
        if ( estudiantes[i].cursoact < 1 || estudiantes[i].cursoact > 11 )
        {
            cout << endl << "Curso actual invalido. Intente de nuevo";
            cout<<"\n-------------------------------------------------------\n";
        }
    }
    while( estudiantes[i].cursoact < 1 || estudiantes[i].cursoact > 11 );
    do
    {
        cout << "\nIngrese sexo del estudiante ( f / m ): ";
        cin >> estudiantes[i].sexo;
        if (estudiantes[i].sexo != 'f' && estudiantes[i].sexo != 'm')
        {
            cout << endl << "Sexo invalido. Intente de nuevo";
            cout<<"\n-------------------------------------------------------\n";
        }
    }
    while (estudiantes[i].sexo != 'f' && estudiantes[i].sexo != 'm');
    cout<< endl <<"==========================================================" << endl;
}
bool funcion0(estudiante estudiantes[maximo], int cantidad)
{
    cout<<"==========================================================\n";
    for(int i=0; i<cantidad; i++)
    {
        informacion(estudiantes,i);
    }
    return true;
}
void funcion1(estudiante estudiantes[maximo], int cantidad)
{
    int i,j;
    string genero;
    bool disponible;
    disponible= false;
    for(i=0; i <cantidad; i++)
    {
        if(estudiantes[i].cursoact < 6)
        {
            disponible= true;
        }
    }
    if(disponible== true)
    {
        cout <<endl<<endl;
        cout << "===============================================================================\n";
        cout <<"\t\t\tLISTA DE ESTUDIENTES DE PRIMARIA\n";

        //este ciclo recorrera todos los estudiantes y se verificara que el curso actual sea menor a grado 6//
        for(i=0; i<cantidad; i++)
        {
            if(estudiantes[i].cursoact<6)
            {
                if(estudiantes[i].sexo =='f')
                {
                    genero= "femenino";
                }
                else
                {
                    genero= "masculino";
                }
                cout <<endl;
                cout <<"\tESTUDIANTE: "<<estudiantes[i].nombre<<endl;
                cout <<"\tDATOS DEL ESTUDIANTE: \n";
                cout << "--------------------------------------------------------------------------------\n";

                cout <<"\tID: "<<estudiantes[i].id<<"\t"<<"CURSO ACTUAL : "<<estudiantes[i].cursoact<<"\t"<<"TELEFONO: "<<estudiantes[i].telefono<<endl;
                cout <<"\tCIUDAD: "<<estudiantes[i].ubicacion.ciudad<<"\t"<<"DIRECCION : "<<estudiantes[i].ubicacion.direccion<<endl;
                cout <<"\tNACIMIENTO (DD/MM/AA): "<<estudiantes[i].cumpleanios.diacumple<<" / "<<estudiantes[i].cumpleanios.mescumple<<" / "<<estudiantes[i].cumpleanios.aniocumple<<endl;
                cout <<"\tSEXO: "<<genero<<endl<<endl;
                cout <<"\tCANTIDAD DE ANIOS: "<<estudiantes[i].estudi.cantianios<<endl;
                for(j=0; j<estudiantes[i].estudi.cantianios; j++)
                {
                    cout << "\t\t\tANIO "<<j+1<<": "<<" puesto: "<<estudiantes[i].estudi.puesto[j]<<" | promedio: "<<estudiantes[i].estudi.promedio[j]<<endl;

                }
                cout <<endl;
                cout << "\tCANTIDAD DE ACUDIENTES: "<<estudiantes[i].cant_acud<<endl;
                cout <<"\tACUDIENTES: "<<endl;
                for(j=0; j < estudiantes[i].cant_acud; j++)
                {
                    cout<<"\t\t\t"<<estudiantes[i].nom_acud[j]<<endl;
                }
                cout <<"_______________________________________________________________________________\n";
                cout <<"_______________________________________________________________________________\n";
                cout << endl;


            }

        }
        cout << "===============================================================================\n";
    }
    else
    {
        cout << "_________________________________________________\n";
        cout << "| no hay estudientes de de primaria registrados |\n ";
        cout << "_________________________________________________\n";
    }


}
void funcion2(estudiante estudiantes[maximo], int cantidad)
{
    int i,j;
    string genero;
    bool disponible;
    disponible = false;
    for(i=0; i <cantidad; i++)
    {
        if(estudiantes[i].cursoact > 5)
        {
            disponible= true;
        }
    }
    if(disponible== true)
    {
        cout <<endl<<endl;
        cout << "==============================================================================\n";
        cout <<"\t\t\t DE ESTUDIENTES DE BACHILLERATO\n";

        //este ciclo recorrera todos los estudiantes y se verificara que el curso actual sea mayor a grado 5//
        for(i=0; i<cantidad; i++)
        {
            if(estudiantes[i].cursoact > 5)
            {
                if(estudiantes[i].sexo =='f')
                {
                    genero= "femenino";
                }
                else
                {
                    genero= "masculino";
                }
                cout <<endl;
                cout <<"ESTUDIANTE: "<<estudiantes[i].nombre<<endl;
                cout <<"DATOS DEL ESTUDIANTE: \n";
                cout << "--------------------------------------------------------------------------------\n";

                cout <<"\tID: "<<estudiantes[i].id<<"\t"<<"CURSO ACTUAL : "<<estudiantes[i].cursoact<<"\t"<<"TELEFONO : "<<estudiantes[i].telefono<<endl;
                cout <<"\tCIUDAD: "<<estudiantes[i].ubicacion.ciudad<<"\t"<<"DIRECCION : "<<estudiantes[i].ubicacion.direccion<<endl;
                cout <<"\tNACIMIENTO (DD/MM/AA): "<<estudiantes[i].cumpleanios.diacumple<<" | "<<estudiantes[i].cumpleanios.mescumple<<" / "<<estudiantes[i].cumpleanios.aniocumple<<endl;
                cout <<"\tSEXO: "<<genero<<endl<<endl;
                cout <<"\tCANTIDAD DE ANIOS: "<<estudiantes[i].estudi.cantianios<<endl;
                for(j=0; j<estudiantes[i].estudi.cantianios; j++)
                {
                    cout << "\t\t\tANIO "<<j+1<<": "<<" puesto: "<<estudiantes[i].estudi.puesto[j]<<"/ promedio: "<<estudiantes[i].estudi.promedio[j]<<endl;

                }
                cout <<endl;
                cout << "\tCANTIDAD DE ACUDIENTES: "<<estudiantes[i].cant_acud<<endl;
                cout <<"\tACUDIENTES: "<<endl;
                for(j=0; j < estudiantes[i].cant_acud; j++)
                {
                    cout<<"\t\t\t"<<estudiantes[i].nom_acud[j]<<endl;
                }
                cout <<"_______________________________________________________________________________\n";
                cout <<endl;

            }

        }
        cout << "================================================================================\n";
    }
    else
    {
        cout << "__________________________________________________\n";
        cout << "| no hay estudientes de bachillerato registrados |\n ";
        cout << "__________________________________________________\n";
    }
}
void funcion3(estudiante estudiantes[maximo], int cantidad)
{
    string genero;
    int mayor=-1,i,j;
    estudiante mayorest;
    for(int i=0; i<cantidad; i++)
        if(mayor<estudiantes[i].contador_primer)
        {
            mayorest=estudiantes[i];
            mayor=estudiantes[i].contador_primer;
        }
    if(mayorest.contador_primer!=0)
    {
        cout<<"el que ocupo mayor veces el primer puesto es"<<endl;
        if(mayorest.sexo =='f')
        {
            genero= "femenino";
        }
        else
        {
            genero= "masculino";
        }
        cout <<endl;
        cout <<"ESTUDIANTE: "<<mayorest.nombre<<endl;
        cout <<"DATOS DEL ESTUDIANTE: \n";
        cout << "--------------------------------------------------------------------------------\n";

        cout <<"\tID: "<<mayorest.id<<"\t"<<"CURSO ACTUAL : "<<mayorest.cursoact<<"\t"<<"TELEFONO : "<<mayorest.telefono<<endl;
        cout <<"\tCIUDAD: "<<mayorest.ubicacion.ciudad<<"\t"<<"DIRECCION : "<<mayorest.ubicacion.direccion<<endl;
        cout <<"\tNACIMIENTO (DD/MM/AA): "<<mayorest.cumpleanios.diacumple<<" / "<<mayorest.cumpleanios.mescumple<<" / "<<mayorest.cumpleanios.aniocumple<<endl;
        cout <<"\tSEXO: "<<genero<<endl<<endl;
        cout <<"\tCANTIDAD DE ANIOS: "<<mayorest.estudi.cantianios<<endl;
        for(j=0; j<mayorest.estudi.cantianios; j++)
        {
            cout << "\t\t\tANIO "<<j+1<<": "<<" puesto: "<<mayorest.estudi.puesto[j]<<"/ promedio: "<<mayorest.estudi.promedio[j]<<endl;

        }
        cout <<endl;
        cout << "\tCANTIDAD DE ACUDIENTES: "<<mayorest.cant_acud<<endl;
        cout <<"\tACUDIENTES: "<<endl;
        for(j=0; j < mayorest.cant_acud; j++)
        {
            cout<<"\t\t\t"<<mayorest.nom_acud[j]<<endl;
        }
        cout <<"_______________________________________________________________________________\n";
        cout <<endl;
    }
    else
    {
        cout <<"================================================================================\n";
        cout<<endl<<"nadie ocupo el primer puesto al menos una vez"<<endl;
        cout <<"================================================================================\n";
    }
}
void funcion4(estudiante estudiantes[maximo], int cantidad)
{
// lista de acudientes de estudientes femenino de primaria//
    int i,j;
    bool bandera;
    cout <<"================================================================================\n";
    for(i=0; i<cantidad; i++)
    {
        if((estudiantes[i].sexo == 'f')&&(estudiantes[i].cursoact < 6))
        {
            bandera=true;
        }
    }
    if(bandera==true)
    {


        cout <<"\t\tLISTA DE ACUDIENTES DE ESTUDIENTES FEMENINO DE PRIMARIA\n\n";
        for(i=0; i<cantidad; i++)
        {
            if((estudiantes[i].sexo == 'f')&&(estudiantes[i].cursoact < 6))
            {
                cout << "ESTUDIANTE: "<< estudiantes[i].nombre<<" CURSO ACTUAL: "<<estudiantes[i].cursoact<<endl;
                cout << "ACUDIENTES DEL ESTUDIENTE : "<<endl;
                cout << "-------------------------------------------------------------------------------\n";
                for(j=0; j < estudiantes[i].cant_acud; j++)
                {
                    cout << "Acudiente numero "<<j+1<<" : "<<estudiantes[i].nom_acud[j]<<endl;


                }
                cout <<"_______________________________________________________________________________\n";
                cout <<endl<<endl;
            }

        }
        cout << "==============================================================================\n";
    }

    else
    {
        cout << "no se han encontrado estudientes femeninos en primaria\n";
    }
}
int funcion5(estudiante estudiantes[maximo], int cantidad)
{
    int puesto;
    bool encontrado=false;
    char opcion;
    string borrar, genero;
    cout << endl << "Ingrese nombre del estudiante a eliminar de la lista: ";
    cin >> borrar;
    for(puesto=0; puesto<cantidad&&encontrado==false; puesto++)
    {
        if(borrar==estudiantes[puesto].nombre)
        {
            if(estudiantes[puesto].sexo =='f')
            {
                genero= "femenino";
            }
            else
            {
                genero= "masculino";
            }
            cout <<endl;
            cout <<"\tESTUDIANTE: "<<estudiantes[puesto].nombre<<endl;
            cout <<"\tDATOS DEL ESTUDIANTE: \n";
            cout << "--------------------------------------------------------------------------------\n";

            cout <<"\tID: "<<estudiantes[puesto].id<<"\t"<<"CURSO ACTUAL : "<<estudiantes[puesto].cursoact<<"\t"<<"TELEFONO: "<<estudiantes[puesto].telefono<<endl;
            cout <<"\tCIUDAD: "<<estudiantes[puesto].ubicacion.ciudad<<"\t"<<"DIRECCION : "<<estudiantes[puesto].ubicacion.direccion<<endl;
            cout <<"\tNACIMIENTO (DD/MM/AA): "<<estudiantes[puesto].cumpleanios.diacumple<<" / "<<estudiantes[puesto].cumpleanios.mescumple<<" / "<<estudiantes[puesto].cumpleanios.aniocumple<<endl;
            cout <<"\tSEXO: "<<genero<<endl<<endl;
            cout <<"\tCANTIDAD DE ANIOS: "<<estudiantes[puesto].estudi.cantianios<<endl;
            for(int j=0; j<estudiantes[puesto].estudi.cantianios; j++)
            {
                cout << "\t\t\tANIO "<<j+1<<": "<<" puesto: "<<estudiantes[puesto].estudi.puesto[j]<<" | promedio: "<<estudiantes[puesto].estudi.promedio[puesto]<<endl;

            }
            cout <<endl;
            cout << "\tCANTIDAD DE ACUDIENTES: "<<estudiantes[puesto].cant_acud<<endl;
            cout <<"\tACUDIENTES: "<<endl;
            for(int j=0; j < estudiantes[puesto].cant_acud; j++)
            {
                cout<<"\t\t\t"<<estudiantes[puesto].nom_acud[j]<<endl;
            }
            cout <<"_______________________________________________________________________________\n";
            cout <<"_______________________________________________________________________________\n";
            cout << endl;
            cout << "===============================================================================\n";
            cout<<"Desea eliminar al alumno (s/n): ";
            cin >>opcion;
            if(opcion == 's')
            {
                encontrado=true;
                cout << "===============================================================================\n";
                cout<<"Alumno eliminado.\n";
                cout << "===============================================================================\n";
            }

        }
    }
    puesto=puesto-1;
    if(encontrado)
        while(puesto<cantidad-1)
        {
            estudiantes[puesto]=estudiantes[puesto+1];
            puesto++;
        }
    else
    {
        cout << "===============================================================================\n";
        cout<<borrar<<" no existe";
        cout << "===============================================================================\n";
        return cantidad;
    }
    cantidad=cantidad-1;
    return cantidad;
}
int funcion6(estudiante estudiantes[maximo], int cantidad)
{
    cout <<"Ingreso a 6";
    bool bandera=true;
    cout << "\nIngrese ID: ";
    cin >> estudiantes[cantidad].id;
    if ( estudiantes[cantidad].id <= 0)
    {
        cout << endl << "ID invalido. Intentar de nuevo.";
        cout<<"\n-------------------------------------------------------\n";
    }
    for(int i=0; i<cantidad; i++)
    {
        if(estudiantes[i].id == estudiantes[cantidad].id)
            bandera=false;
    }
    if(bandera==true)
    {
        bool bisiesto;
        int diasmes, contadorpuesto;
        contadorpuesto=0;
        cout <<"\nIngrese nombre del estudiante: ";
        cin >> estudiantes[cantidad].nombre;
        do
        {
            cout << "\nIngrese telefono del estudiante: ";
            cin >> estudiantes[cantidad].telefono;
            if ( estudiantes[cantidad].telefono < 0)
            {
                cout << endl << "Telefono invalido. Intente de nuevo";
                cout<<"\n-------------------------------------------------------\n";
            }
        }
        while (estudiantes[cantidad].telefono < 0);
        cout << "\nIngrese direccion del estudiante: ";
        cin >> estudiantes[cantidad].ubicacion.direccion;
        cout << "\nIngrese ciudad del estudiante: ";
        cin >> estudiantes[cantidad].ubicacion.ciudad;
        do
        {
            cout << "Ingrese cantidad de acudientes (Minimo: 1 Maximo: 5): ";
            cin >> estudiantes[cantidad].cant_acud;
            if( estudiantes[cantidad].cant_acud < 1 || estudiantes[cantidad].cant_acud > 5)
            {
                cout << endl << "Cantidad de acudientes invalido. Intente de nuevo";
                cout<<"\n-------------------------------------------------------\n";
            }
        }
        while( estudiantes[cantidad].cant_acud < 1 || estudiantes[cantidad].cant_acud > 5);
        for (int h=0; h< estudiantes[cantidad].cant_acud ; h++)
        {
            cout<<"Ingrese nombre del acudiente: ";
            cin>> estudiantes[cantidad].nom_acud[h];
        }
        cout << "\nIngrese dia de cumpleanios del estudiante: ";
        cin >>estudiantes[cantidad].cumpleanios.diacumple;
        cout << "\nIngrese mes de cumpleanios del estudiante: ";
        cin >> estudiantes[cantidad].cumpleanios.mescumple;
        cout << "\nIngrese anio de cumpleanios del estudiante: ";
        cin >> estudiantes[cantidad].cumpleanios.aniocumple;
        bisiesto = aniobisiesto(estudiantes[cantidad].cumpleanios.aniocumple);
        diasmes = diames( estudiantes[cantidad].cumpleanios.mescumple , bisiesto);
        do
        {
            if(estudiantes[cantidad].cumpleanios.diacumple > diasmes || estudiantes[cantidad].cumpleanios.diacumple<1)
            {
                cout << "Dia Invalido. Intente de nuevo";
                cout << "\nIngrese dia de cumpleanios del estudiante: ";
                cin >>estudiantes[cantidad].cumpleanios.diacumple;
            }
        }
        while(estudiantes[cantidad].cumpleanios.diacumple > diasmes || estudiantes[cantidad].cumpleanios.diacumple<1);
        do
        {
            if(estudiantes[cantidad].cumpleanios.mescumple > 12 || estudiantes[cantidad].cumpleanios.mescumple<1)
            {
                cout << "Mes Invalido. Intente de nuevo";
                cout << "\nIngrese mes de cumpleanios del estudiante: ";
                cin >>estudiantes[cantidad].cumpleanios.mescumple;
            }
        }
        while(estudiantes[cantidad].cumpleanios.mescumple > 12 || estudiantes[cantidad].cumpleanios.mescumple<1);
        do
        {
            if(estudiantes[cantidad].cumpleanios.aniocumple > 2015 || estudiantes[cantidad].cumpleanios.aniocumple < 1900)
            {
                cout << "Anio Invalido. Intente de nuevo";
                cout << "\nIngrese anio de cumpleanios del estudiante: ";
                cin >>estudiantes[cantidad].cumpleanios.aniocumple;
            }
        }
        while(estudiantes[cantidad].cumpleanios.aniocumple > 2015 || estudiantes[cantidad].cumpleanios.aniocumple<1900);
        do
        {
            cout<< "\nIngrese cantidad de años que ha estado en el colegio: ";
            cin >>estudiantes[cantidad].estudi.cantianios ;
            if ( estudiantes[cantidad].estudi.cantianios < 0)
            {
                cout << endl << "Cantidad de cursos invalida. Intenta de nuevo.";
                cout<<"\n-------------------------------------------------------\n";
            }
        }
        while ( estudiantes[cantidad].estudi.cantianios < 0);
        for (int k = 0; k < estudiantes[cantidad].estudi.cantianios ; k++)
        {
            cout << "\nIngrese numero de puesto del estudiante en el anio " << k+1 << ": ";
            cin >> estudiantes[cantidad].estudi.puesto[k];
            if ( estudiantes[cantidad].estudi.puesto[k] == 1)
            {
                contadorpuesto = contadorpuesto + 1;
            }
            cout << "\nIngrese promedio del estudiante en el anio " << k+1 << ": ";
            cin >> estudiantes[cantidad].estudi.promedio[k] ;
        }
        estudiantes[cantidad].contador_primer = contadorpuesto;
        do
        {
            cout << "\nIngrese curso actual del estudiante: " << estudiantes[cantidad].nombre << ": ";
            cin >> estudiantes[cantidad].cursoact ;
            if ( estudiantes[cantidad].cursoact < 1 || estudiantes[cantidad].cursoact > 11 )
            {
                cout << endl << "Curso actual invalido. Intente de nuevo";
                cout<<"\n-------------------------------------------------------\n";
            }
        }
        while( estudiantes[cantidad].cursoact < 1 || estudiantes[cantidad].cursoact > 11 );
        do
        {
            cout << "\nIngrese sexo del estudiante ( f / m ): ";
            cin >> estudiantes[cantidad].sexo;
            if (estudiantes[cantidad].sexo != 'f' && estudiantes[cantidad].sexo != 'm')
            {
                cout << endl << "Sexo invalido. Intente de nuevo";
                cout<<"\n-------------------------------------------------------\n";
            }
        }
        while (estudiantes[cantidad].sexo != 'f' && estudiantes[cantidad].sexo != 'm');
        cout<< endl <<"==========================================================" << endl;
        cantidad++;
        return cantidad;
        cout <<"Se ha agregado exitosamente.";
        cout<< endl <<"==========================================================" << endl;
    }
    else
    {
        cout<< endl <<"==========================================================" << endl;
        cout<<"Estudiante existente.";
        cout<< endl <<"==========================================================" << endl;
        return cantidad;
    }

}
bool aniobisiesto(int anio)
{
    if (anio % 4 == 0)
    {
        if (anio % 100 == 0)
        {
            if (anio % 400 == 0)
                return true;
        }
    }
    return false;
}
int diames(int mescumple, bool bisiesto)
{
    int diames;
    if(mescumple == 2)
    {
        if (bisiesto == true)
            diames = 29;
        else
            diames = 28;
    }
    else
    {
        if (mescumple % 2 == 0)
            diames = 31;
        else
        {
            diames = 30;
        }
    }
    return diames;
}
void sustentacion(estudiante estudiantes[maximo], int cantidad)
{
    bool bandera, almenosuno=false;
    string genero;
    for(int i=0; i<cantidad; i++)
    {
        bandera=false;
        for(int h=0; h<estudiantes[i].estudi.cantianios; h++)
        {
            if(estudiantes[i].estudi.promedio[h] < 3)
            {
                almenosuno = true;
                bandera = true;
            }
        }
        if(bandera)
        {
            if(estudiantes[i].sexo =='f')
            {
                genero= "femenino";
            }
            else
            {
                genero= "masculino";
            }
            cout <<endl;
            cout <<"ESTUDIANTE: "<<estudiantes[i].nombre<<endl;
            cout <<"DATOS DEL ESTUDIANTE: \n";
            cout << "--------------------------------------------------------------------------------\n";

            cout <<"\tID: "<<estudiantes[i].id<<"\t"<<"CURSO ACTUAL : "<<estudiantes[i].cursoact<<"\t"<<"TELEFONO : "<<estudiantes[i].telefono<<endl;
            cout <<"\tCIUDAD: "<<estudiantes[i].ubicacion.ciudad<<"\t"<<"DIRECCION : "<<estudiantes[i].ubicacion.direccion<<endl;
            cout <<"\tNACIMIENTO (DD/MM/AA): "<<estudiantes[i].cumpleanios.diacumple<<" / "<<estudiantes[i].cumpleanios.mescumple<<" / "<<estudiantes[i].cumpleanios.aniocumple<<endl;
            cout <<"\tSEXO: "<<genero<<endl<<endl;
            cout <<"\tCANTIDAD DE ANIOS: "<<estudiantes[i].estudi.cantianios<<endl;
            for(int j=0; j<estudiantes[i].estudi.cantianios; j++)
            {
                cout << "\t\t\tANIO "<<j+1<<": "<<" puesto: "<<estudiantes[i].estudi.puesto[j]<<"/ promedio: "<<estudiantes[i].estudi.promedio[j]<<endl;

            }
            cout <<endl;
            cout << "\tCANTIDAD DE ACUDIENTES: "<<estudiantes[i].cant_acud<<endl;
            cout <<"\tACUDIENTES: "<<endl;
            for(int g=0; g < estudiantes[i].cant_acud; g++)
            {
                cout<<"\t\t\t"<<estudiantes[i].nom_acud[g]<<endl;
            }
            cout <<"_______________________________________________________________________________\n";
            cout <<endl;
        }
    }
    if(!almenosuno)
        {
            cout <<"\n_______________________________________________________________________________\n";
            cout<<"\nNingun estudiante ha obtenido un promedio por debajo de 3.0 en sus anios en el colegio.";
            cout <<"\n_______________________________________________________________________________\n";
        }
}
