#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleoyeeFunctions.h"
#define S 1000

int main()
{
    sEmployee employeeList [S] ;
    initializeEmpleoyeeArray( employeeList, S ) ;
    //forTestingPorpuses( employeeList ) ;
    int option ;
    int itsDone ;
    int identification ;
    int itsPosible = 0 ;
    int employeeExist = 0 ;
    int employeeIndex = -1 ;
    int itsSorted ;
    char confirm ;
    do
    {
        option = printMenuGetOption();
        switch ( option )
        {
        case 1:
            itsDone = getData ( employeeList, S ) ;
            if ( itsDone == 0 )
            {
                system ( "cls" ) ;
                printf ( "Datos cargados exitosamente.\n" ) ;
            }
            else
            {
                system ( "cls" ) ;
                printf ( "No se pudo cargar datos. Vuelva a intentar.\n" ) ;
            }
            break ;
        case 2:
            itsPosible = thereIsData ( employeeList, S ) ;
            if ( itsPosible )
            {
                printf ( "Ingrese el ID del empleado a modificar: " ) ;
                fflush ( stdin ) ;
                scanf ( "%d" , &identification ) ;
                employeeExist = findEmployeeById ( employeeList, S, identification, &employeeIndex ) ;
                if ( employeeExist )
                {
                   modifyEmployee( employeeList , employeeIndex ) ;
                }
                else
                {
                    system ( "cls" ) ;
                    printf ( "No existe empleado con ese ID. Vuelva a intentar.\n" ) ;
                    system ( "pause" ) ;
                }
            }
            else
            {
                system ( "cls" ) ;
                printf ( "No hay datos cargados." ) ;
            }
            break ;
        case 3:
            itsPosible = thereIsData ( employeeList, S ) ;
            if ( itsPosible )
            {
                 printf ( "\nIngrese el ID del empleado a dar de baja: " ) ;
                 fflush ( stdin ) ;
                 scanf ( "%d" , &identification ) ;
                 employeeExist = findEmployeeById ( employeeList , S , identification , &employeeIndex ) ;
                 if ( employeeExist )
                 {
                    printf ( "\n\nEsta seguro que desea continuar con la baja?\n\nIngrese S para continuar. Ingrese cualquier otro caracter para salir.\n" ) ;
                    fflush ( stdin ) ;
                    confirm = getc( stdin ) ;
                    if ( confirm == 's' || confirm == 'S' )
                    {
                        removeEmployee ( employeeList , employeeIndex ) ;
                        printf ( "\nBaja exitosa." );
                        system ( "pause" ) ;
                    }
                 }
                 else
                 {
                     system ( "cls" ) ;
                     printf ( "No existe empleado con ese ID. Vuelva a intentar.\n" ) ;
                     system ( "pause" ) ;
                 }
            }
            break ;
        case 4:
            itsPosible = thereIsData ( employeeList, S ) ;
            if ( itsPosible )
            {
                itsSorted = sortEmployees( employeeList, S, 1 ) ;
                if ( itsSorted == 0 )
                {
                    printEmployees ( employeeList , S ) ;
                }
                else
                {
                    printf ( "Error. Vuelva a intentar." ) ;
                    system ( "pause" ) ;
                }
            }
            else
            {
                    printf ( "Error. No hay datos cargados." ) ;
                    system ( "pause" ) ;
            }
            break ;
        case 5:
            exitSignature() ;
            break;
        default:
            system ( "cls" ) ;
            printf ( "Opcion invalida." ) ;
            system ( "pause" ) ;
            break ;
        }
    }
    while ( option != 5 ) ;
    return 0;
}
