#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funciones_TP1.h"
int main()
{
    double operador_1 = 0 ;
    double operador_2 = 0 ;
    int flag_operador1 = 0 ;
    int flag_operador2 = 0 ;
    int opcionElejida ;
    int flag_estaTodoListo = 0 ;
    int quiereSalir = 0 ;
    double resultado_suma ;
    double resultado_resta ;
    double resultado_division ;
    double resultado_multiplicacion ;
    double resultado_factorial_A ;
    double resultado_factorial_B ;
    do
    {
        opcionElejida = imprimirMenuDeOpciones ( operador_1, operador_2, flag_operador1, flag_operador2 ) ;
        printf ("%d", opcionElejida ) ;
        switch ( opcionElejida )
        {
        case 1 :
            operador_1 = tomarOperando () ;
            flag_operador1 = 1 ;
            break ;
        case 2 :
            operador_2 = tomarOperando () ;
            flag_operador2 = 1 ;
            break ;
        case 3 :
            if ( flag_operador1 == 0 || flag_operador2 == 0 )
            {
                system ( "cls" ) ;
                printf ( "Error. Los dos operadores deben estar definidos.\n\n\n" ) ;
                system ( "pause" ) ;
            }
            else
            {
                hacerCuentitas ( operador_1, operador_2 , &resultado_suma , &resultado_resta , &resultado_division , &resultado_multiplicacion , &resultado_factorial_A , &resultado_factorial_B ) ;
                flag_estaTodoListo = 1 ;
            }
            break ;
        case 4 :
            if ( flag_estaTodoListo == 0 )
            {
                system ( "cls" ) ;
                printf ( "Error. Calculos aun no realizados.\n\n\n" ) ;
                system ( "pause" ) ;
            }
            else
            {
                entregarResultados ( operador_1, operador_2 , resultado_suma , resultado_resta , resultado_division , resultado_multiplicacion , resultado_factorial_A , resultado_factorial_B ) ;
            }
            break ;
        case 5 :
            quiereSalir = 1 ;
            break ;
        }
    }
    while ( quiereSalir == 0 ) ;
}
