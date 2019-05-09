#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleoyeeFunctions.h"
#include "validations.h"

void initializeEmpleoyeeArray ( sEmployee* list, int len )
{
    int i ;
    for ( i = 0 ; i < len ; i++ )
    {
        list[i].id = 0 ;
        list[i].isEmpty = 1 ;
        list[i].salary = 0 ;
        list[i].sector = 0 ;
        strcpy ( list[i].name, " " ) ;
        strcpy ( list[i].lastName, " " ) ;
    }

}
void deleteInvalidData ( sEmployee* list , int index )
{
    list[index].id = 0 ;
    list[index].isEmpty = 1 ;
    list[index].salary = 0 ;
    list[index].sector = 0 ;
    strcpy ( list[index].name, "" ) ;
    strcpy ( list[index].lastName, "" ) ;
}
int initEmployees( sEmployee* list, int len )
{
    int i ;
    int itsDone = 0 ;
    for ( i = 0 ; i < len ; i++ )
    {
        list[i].isEmpty = 1 ;
    }
    for ( i = 0 ; i < len ; i++ )
    {
        if ( list[i].id != 1 )
        {
            itsDone = -1 ;
        }
    }
    return itsDone ;
}
int addEmployee( sEmployee* list, int len, int identification, char name [], char lastName [], double salary, int sector, int index )
{
    int itsDone ;
    if ( index < 0 )
    {
        itsDone = -1 ;
    }
    else
    {
        addID ( list , index , identification ) ;
        addSalary ( list , index , salary ) ;
        addSector ( list , index , sector ) ;
        addName ( list , index , name ) ;
        addLastName ( list , index , lastName ) ;
        list[index].isEmpty = 0 ;
        itsDone = 0 ;
    }
    return itsDone ;
}
int findEmployeeById ( sEmployee* list, int givenLen , int givenID, int* index )
{
    int i ;
    int itExist = 0 ;
    for ( i = 0 ; i < givenLen ; i++ )
    {
        if ( list[i].id == givenID )
        {
            if ( list[i].isEmpty == 0 )
            {
                index[0] = i ;
                itExist = 1 ;
                break ;
            }
        }
    }
    return itExist ;
}
void removeEmployee ( sEmployee* list, int index )
{
    list[index].isEmpty = 1 ;
}
int sortEmployees( sEmployee* list, int len, int order )
{
    int i ;
    int j ;
    sEmployee aux ;
    int comparison ;
    int itsDone = -1 ;
    //menor a mayor
    if ( order )
    {
        for ( i = 0 ; i < ( len - 1 ) ; i++ )
        {
            if ( list[i].isEmpty == 0 )
            {
                for ( j = i+1 ; j < len ; j++ )
                {
                    if ( list[j].isEmpty == 0 )
                    {
                        if ( list[i].sector > list[j].sector )
                        {
                            aux = list[i] ;
                            list[i] = list[j] ;
                            list[j] = aux;
                        }
                        else if ( list[i].sector == list[j].sector )
                        {
                            comparison = strcasecmp ( list[i].lastName, list[j].lastName ) ;
                            if ( comparison > 0 )
                            {
                                aux = list[i] ;
                                list[i] = list[j] ;
                                list[j] = aux;
                            }
                            else if ( comparison == 0 )
                            {
                                comparison = strcasecmp ( list[i].name, list[j].name ) ;
                                if ( comparison > 0 )
                                {
                                    aux = list[i] ;
                                    list[i] = list[j] ;
                                    list[j] = aux;
                                }
                                else if ( comparison == 0 )
                                {
                                    if ( list[i].id > list[j].id )
                                    {
                                        aux = list[i] ;
                                        list[i] = list[j] ;
                                        list[j] = aux;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            itsDone = 0 ;
        }
    }
    else //mayor a menor
    {
        for ( i = 0 ; i < ( len - 1 ) ; i++ )
        {
            if ( list[i].isEmpty == 0 )
            {
                for ( j = i+1 ; j < len ; j++ )
                {
                    if ( list[j].isEmpty == 0 )
                    {
                        if ( list[i].sector < list[j].sector )
                        {
                            aux = list[i] ;
                            list[i] = list[j] ;
                            list[j] = aux;
                        }
                        else if ( list[i].sector == list[j].sector )
                        {
                            comparison = strcasecmp ( list[i].lastName, list[j].lastName ) ;
                            if ( comparison < 0 )
                            {
                                aux = list[i] ;
                                list[i] = list[j] ;
                                list[j] = aux;
                            }
                            else if ( comparison == 0 )
                            {
                                comparison = strcasecmp ( list[i].name, list[j].name ) ;
                                if ( comparison < 0 )
                                {
                                    aux = list[i] ;
                                    list[i] = list[j] ;
                                    list[j] = aux;
                                }
                                else if ( comparison == 0 )
                                {
                                    if ( list[i].id < list[j].id )
                                    {
                                        aux = list[i] ;
                                        list[i] = list[j] ;
                                        list[j] = aux;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            itsDone = 0 ;
        }
    }
    return itsDone ;
}
void printEmployees ( sEmployee* list, int len )
{
    int i ;
    system ( "cls" ) ;
    headerEmployee() ;
    for ( i = 0 ; i < len ; i++ )
    {
        printOneEmployee( list[i] ) ;
    }
    printf ( "----------------------------------------------------------------------------------------------------\n" ) ;
    system( "pause" ) ;
}
int getEmptySpace ( sEmployee* list, int len )
{
    int i ;
    int index = -1 ;
    for ( i = 0 ; i < len ; i++ )
    {
        if ( list[i].isEmpty )
        {
            index = i ;
            break ;
        }
    }
    return index ;
}
void printOneEmployee ( sEmployee employee )
{
    int namLen ;
    int lasNamLen ;
    if ( employee.isEmpty == 0 )
    {
        namLen = strlen( employee.name ) ;
        lasNamLen = strlen( employee.lastName ) ;
        printf ( "| " ) ;
        printf ( "%d\t  |", employee.id ) ;
        if ( lasNamLen < 10 )
        {
            printf ( " %s\t\t    |", employee.lastName ) ;
        }
        else
        {
            printf ( " %s\t\t|", employee.lastName ) ;
        }
        if ( namLen < 10 )
        {
            printf ( " %s\t\t    |", employee.name ) ;
        }
        else
        {
            printf ( " %s\t\t|", employee.name ) ;
        }
        if ( employee.sector <= 0 )
        {
            printf ( "unassigned |") ;
        }
        else
        {
            printf ( "\t%d\t|", employee.sector ) ;
        }
        if ( employee.salary <= 0 )
        {
            printf ( " unassigned |") ;
        }
        else
        {
            printf ( " %.02f", employee.salary ) ;
        }
        printf ( "\t|\n" ) ;
    }
}
int printMenuGetOption ()
{
    int input = 0 ;
    do {
        system ( "cls" ) ;
        printf ( "1. ALTAS\n" ) ;
        printf ( "2. MODIFICAR\n" ) ;
        printf ( "3. BAJAS\n" ) ;
        printf ( "4. INFORME\n" ) ;
        printf ( "5. SALIR\n\n" ) ;
        printf ( "Ingrese una opcion:   " ) ;
        fflush ( stdin ) ;
        scanf ( "%d" , &input ) ;
    }
    while ( input > 5 || input < 1 ) ;
    return input ;
}
int thereIsData ( sEmployee* list, int len )
{
    int i;
    int thereIs = 0 ;
    for ( i = 0 ; i < len ; i++)
    {
        if ( list[i].isEmpty == 0 )
        {
            thereIs = 1 ;
            break;
        }
    }
    return thereIs ;
}
int getData ( sEmployee* list, int len )
{
    int i ;
    int canDo = -1 ;
    char name [51] ;
    char lastName [51] ;
    int nameIsAGo = 0 ;
    int lastNameIsAGo = 0 ;
    int salaryIsAGo = 0 ;
    int sectorIsAGo = 0 ;
    double salary ;
    int sector ;
    int identification ;
    int itsDone = 0 ;
    canDo = getEmptySpace( list, len ) ;
    if ( canDo > -1 )
    {
        if ( list[canDo].isEmpty  )
        {
            deleteInvalidData( list , canDo ) ;
        }
        list[canDo].isEmpty = 0;
        system( "cls" ) ;
        printf ( "Bienvenido al menu de altas. El ID se generara automaticamente, el resto de los datos se le pediran.\n\n" ) ;
        system ( "pause" ) ;
        identification = getNewID( list, len ) ;
        addID ( list , canDo , identification ) ;
        for ( i = 1 ; i < 6 ; i++ )
        {
            system ( "cls" ) ;
            headerEmployee() ;
            printOneEmployee ( list[canDo] ) ;
            printf ( "----------------------------------------------------------------------------------------------------\n" ) ;
            switch ( i )
            {
                case 1:
                    lastNameIsAGo = getLastName( lastName ) ;
                    if ( lastNameIsAGo )
                    {
                        addLastName ( list , canDo , lastName ) ;
                    }
                    break ;
                case 2:
                    nameIsAGo = getName( name ) ;
                    if ( nameIsAGo )
                    {
                        addName ( list , canDo , name ) ;
                    }
                    break ;
                case 3:
                    sectorIsAGo = getSector( &sector ) ;
                    if ( sectorIsAGo )
                    {
                        addSector ( list , canDo , sector ) ;
                    }
                    break ;
                case 4:
                    salaryIsAGo = getSalary( &salary ) ;
                    if ( salaryIsAGo )
                    {
                        addSalary ( list , canDo , salary ) ;
                    }
                    break ;
                case 5:
                    printf( "Cargando datos..." ) ;
                    system( "pause" ) ;
                    break ;
            }
        }
        if ( salaryIsAGo && sectorIsAGo && nameIsAGo && lastNameIsAGo )
        {
          itsDone = addEmployee( list, len, identification, name, lastName, salary, sector, canDo ) ;
        } else
        {
            deleteInvalidData( list , canDo ) ;
            system ( "cls" ) ;
            printf( "Error. Campos incompletos o invalidos. Vuelva a intentar\n" ) ;
            system ( "pause" ) ;
        }
    } else
    {
        system ( "cls" ) ;
        printf ( "Error. No hay espacio libre." ) ;
        system ( "pause" ) ;
    }
    return itsDone ;
}
int getNewID ( sEmployee* list, int len )
{
    int i ;
    int maxID = 0 ;
    for ( i = 0 ; i < len ; i++ )
    {
        if ( list[i].id > maxID )
        {
            maxID = list[i].id ;
        }
    }
    maxID++;
    return maxID ;
}
void modifyEmployee ( sEmployee* list, int index )
{
    char auxLastName [51] ;
    char auxName  [51] ;
    int auxSector ;
    double auxSalary ;
    int ln ;
    int fn ;
    int slry ;
    int sctr ;
    int option ;
    if ( list[index].isEmpty == 0 )
    {

    do
    {
        system ( "cls" ) ;
        headerEmployee() ;
        printOneEmployee ( list[index] ) ;
        printf ( "----------------------------------------------------------------------------------------------------\n" ) ;
        printf ( "\n\nIngrese parametro a modificar:\n" ) ;
        printf ( "1. Apellido\n" ) ;
        printf ( "2. Nombre\n" ) ;
        printf ( "3. Sector\n" ) ;
        printf ( "4. Salario\n" ) ;
        printf ( "5. Salir\n" ) ;
        fflush ( stdin ) ;
        scanf ( "%d" , &option ) ;
        switch ( option )
        {

        case 1:
            ln = getLastName( auxLastName ) ;
            if ( ln != 1 )
            {
                printf ( "Hubo un error. Vuelva a intentar" ) ;
            }
            else
            {
                strcpy ( list[index].lastName, auxLastName ) ;
            }
            break;
        case 2:
            fn = getName( auxName ) ;
            if ( fn != 1 )
            {
                printf ( "Hubo un error. Vuelva a intentar" ) ;
            }
            else
            {
                strcpy ( list[index].name , auxName ) ;
            }
            break;
        case 3:
            sctr = getSector( &auxSector ) ;
            if ( sctr != 1 )
            {
                printf ( "Hubo un error. Vuelva a intentar" ) ;
            }
            else
            {
                list[index].sector = auxSector ;
            }
            break;
        case 4:
            slry = getSalary( &auxSalary ) ;
            if ( slry != 1 )
            {
                printf ( "Hubo un error. Vuelva a intentar" ) ;
            }
            else
            {
                list[index].salary = auxSalary ;
            }
            break;
        case 5:
            break ;
        default:
            system ( "cls" ) ;
            printf ( "Opcion invalida" ) ;
            system ( "pause" ) ;
            break;
        }
    }
    while ( option != 5 ) ;
    }
}
int getLastName ( char* lastName )
{
    int itsDone = -1 ;
    int count = 0 ;
    printf ( "\n\nIngrese el apellido:  " ) ;
    fflush ( stdin ) ;
    gets ( lastName ) ;
    count++ ;
    while ( ( itsName(lastName) ) == 0 )
    {
        system ( "cls" ) ;
        printf ( "Error. Dato Invalido.\n" ) ;
        printf ( "Ingrese el apellido:  " ) ;
        fflush ( stdin ) ;
        gets ( lastName ) ;
        count++ ;
        if ( count > 5 )
        {
            break ;
        }
    }
    if ( itsName( lastName ) )
    {
        itsDone = 1 ;
    }
    return itsDone ;
}
int getName ( char* name )
{
    int itsDone = 0 ;
    int itsValid ;
    int len ;
    int count = 0 ;
    //system ( "cls" ) ;
    printf ( "\n\nIngrese el nombre:  " ) ;
    fflush ( stdin ) ;
    gets ( name ) ;
    while ( itsName ( name ) == 0 )
    {
        system ( "cls" ) ;
        printf ( "Error. Dato Invalido.\n" ) ;
        printf ( "Ingrese el nombre:  " ) ;
        fflush ( stdin ) ;
        gets ( name ) ;
        count ++ ;
        if ( count > 5 )
        {
            break ;
        }
    }
    itsValid = itsName( name ) ;
    len = strlen( name ) ;
    if ( itsValid )
    {
        if ( len > 3 )
        {
            itsDone = 1 ;
        }
    }
    return itsDone ;
}
int getSalary ( double* salary )
{
    char salaryInput [51] ;
    int count = 0 ;
    int itsDone = -1 ;
    //system ( "cls" ) ;
    printf ( "\n\nIngrese el salario:  " ) ;
    fflush ( stdin ) ;
    gets ( salaryInput ) ;
    itsDone = validateFloatingPointNumber ( salaryInput , salary ) ;
    while ( itsDone == 0 )
    {
        //system ( "cls" ) ;
        printf ( "\nError. Dato Invalido\n" ) ;
        printf ( "Ingrese el salario:  " ) ;
        fflush ( stdin ) ;
        gets ( salaryInput ) ;
        itsDone = validateFloatingPointNumber ( salaryInput , salary ) ;
        count++ ;
        if ( count > 5 )
        {
            printf ( "Hubo un error. Vuelva a intentar." ) ;
            break;
        }
    }
    if ( salary[0] < 0 )
    {
        salary[0] = -1 ;
        itsDone = -1 ;
    }
    else {
        itsDone = 1 ;
    }
    return itsDone ;
}
int getSector ( int* sector )
{
    int count = 0 ;
    int itsDone = 1 ;
    char sectorInput [10] ;
    //system ( "cls" ) ;
    printf ( "\n\nIngrese el sector:  " ) ;
    fflush ( stdin ) ;
    gets ( sectorInput ) ;
    while ( itsInteger ( sectorInput ) == 0 )
    {
        //system ( "cls" ) ;
        printf ( "Error. Dato Invalido. \n" ) ;
        printf ( "Ingrese el sector:  " ) ;
        fflush ( stdin ) ;
        gets ( sectorInput ) ;
        count++ ;
        if ( count > 5 )
        {
            itsDone = -1 ;
            break;
        }
    }
    if ( itsDone )
    {
    sector[0] = atoi ( sectorInput ) ;
    }
    return itsDone ;
}
void exitSignature ()
{
    printf( " ,---.                                           ,--.   ,--.                                        \n" ) ;
    printf( "'   .-' ,--.,--. ,--,--.,--.--. ,---. ,-----.    |   `.'   |,--.,--.,--.--.,--.--. ,--,--.,--. ,--. \n" ) ;
    printf( "`.  `-. |  ||  || ,-.  ||  .--'| .-. :`-.  /     |  |'.'|  ||  ||  ||  .--'|  .--'' ,-.  | `  '  /  \n" ) ;
    printf( ".-'    |'  ''  '| '-'  ||  |   |   --. /  `-.    |  |   |  |'  ''  '|  |   |  |   | '-'  |  `   '   \n" ) ;
    printf( "`-----'  `----'  `--`--'`--'    `----'`-----'    `--'   `--' `----' `--'   `--'    `--`--'.-'  /    \n" ) ;
    printf( "                                                                                          `---'     \n" ) ;
}
void addID ( sEmployee* list , int index , int ident )
{
    list[index].id = ident ;
}
void addName ( sEmployee* list , int index , char* name )
{
    strcpy ( list[index].name, name ) ;
}
void addLastName ( sEmployee* list , int index , char* lastName )
{
    strcpy ( list[index].lastName, lastName ) ;
}
void addSector ( sEmployee* list , int index , int sector )
{
    list[index].sector = sector ;
}
void addSalary ( sEmployee* list , int index , double salary )
{
    list[index].salary = salary ;
}
void headerEmployee ()
{
    printf ( "____________________________________________________________________________________________________\n" ) ;
    printf ( "|   ID   |\t      Last Name\t        |\t\tName\t\t|  Sector  |\t Salary\t    |\n" ) ;
    printf ( "----------------------------------------------------------------------------------------------------\n" ) ;
}
void forTestingPorpuses ( sEmployee* list )
{
    char names [10] [51] = { "alberto" , "arturo" , "carlos" , "daniel" , "juana" , "laura" , "belen" , "matias" , "joel" , "julia" , } ;
    char lastNames [10] [51] = { "riglos" , "zarrelli" , "lepre" , "ramos" , "romero" , "pervieux" , "lopez" , "perez" , "gutierres" , "saraza" ,} ;
    int sector [10] = { 1 , 2 , 3 , 1 , 2 , 3 , 1 , 2 , 3 , 1 } ;
    float salaray [10] = { 100 , 200 , 300 , 400 , 500 , 600 , 700 , 800 , 900 , 1000 } ;
    int i;
    for( i = 0 ; i < 10 ; i++ )
    {
        list[i].id = getNewID( list , 1000 ) ;
        list[i].sector = sector[i] ;
        list[i].salary = salaray[i] ;
        strcpy ( list[i].lastName , lastNames[i] ) ;
        strcpy ( list[i].name , names[i] ) ;
        list[i].isEmpty = 0 ;
    }

}

