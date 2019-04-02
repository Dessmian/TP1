#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funciones_TP1.h"
int imprimirMenuDeOpciones ( double operador1, double operador2, int flag1, int flag2 )
{
    int opcion = 0 ;
    if ( flag1 == 0 && flag2 == 0 )
    {
        system ( "cls" ) ;
        printf ( "1. Ingresar primer operando.\n" ) ;
        printf ( "2. Ingresar segundo operando.\n" ) ;
        printf ( "3. Calcular todas las operaciones. \n" ) ;
        printf ( "4. Informar resultados. \n" ) ;
        printf ( "5. Salir. \n" ) ;
        printf ( "Seleccione una opcion:  " ) ;
        scanf ( "%d", &opcion ) ;
        fflush ( stdin ) ;
        while ( opcion > 5 || opcion < 1 )
        {
            system ( "cls" ) ;
            printf ( "Error. opcion invalida.\n\n" ) ;
            printf ( "1. Ingresar primer operando.\n" ) ;
            printf ( "2. Ingresar segundo operando.\n" ) ;
            printf ( "3. Calcular todas las operaciones. \n" ) ;
            printf ( "4. Informar resultados. \n" ) ;
            printf ( "5. Salir. \n" ) ;
            printf ( "Seleccione una opcion:  " ) ;
            scanf ( "%d", &opcion ) ;
            fflush ( stdin ) ;
        }
        return opcion ;
    }
    if ( flag1 == 1 && flag2 == 0 )
    {
        system ( "cls" ) ;
        printf ( "1. Ingresar primer operando. (A = %.02f)\n", operador1 ) ;
        printf ( "2. Ingresar segundo operando.\n" ) ;
        printf ( "3. Calcular todas las operaciones. \n" ) ;
        printf ( "4. Informar resultados. \n" ) ;
        printf ( "5. Salir. \n" ) ;
        printf ( "Seleccione una opcion:  " ) ;
        scanf ( "%d", &opcion ) ;
        fflush ( stdin ) ;
        while ( opcion > 5 || opcion < 1 )
        {
            system ( "cls" ) ;
            printf ( "Error. opcion invalida.\n\n" ) ;
            printf ( "1. Ingresar primer operando. (A = %.02f)\n", operador1 ) ;
            printf ( "2. Ingresar segundo operando.\n" ) ;
            printf ( "3. Calcular todas las operaciones. \n" ) ;
            printf ( "4. Informar resultados. \n" ) ;
            printf ( "5. Salir. \n" ) ;
            printf ( "Seleccione una opcion:  " ) ;
            scanf ( "%d", &opcion ) ;
            fflush ( stdin ) ;
        }
        return opcion ;
    }
    if ( flag1 == 0 && flag2 == 1 )
    {
        system ( "cls" ) ;
        printf ( "1. Ingresar primer operando. \n" ) ;
        printf ( "2. Ingresar segundo operando. (B = %.02f)\n", operador2 ) ;
        printf ( "3. Calcular todas las operaciones. \n" ) ;
        printf ( "4. Informar resultados. \n" ) ;
        printf ( "5. Salir. \n" ) ;
        printf ( "Seleccione una opcion:  " ) ;
        scanf ( "%d", &opcion ) ;
        fflush ( stdin ) ;
        while ( opcion > 5 || opcion < 1 )
        {
            system ( "cls" ) ;
            printf ( "Error. opcion invalida.\n\n" ) ;
            printf ( "1. Ingresar primer operando. \n" ) ;
            printf ( "2. Ingresar segundo operando.(B = %.02f)\n", operador2 ) ;
            printf ( "3. Calcular todas las operaciones. \n" ) ;
            printf ( "4. Informar resultados. \n" ) ;
            printf ( "5. Salir. \n" ) ;
            printf ( "Seleccione una opcion:  " ) ;
            scanf ( "%d", &opcion ) ;
            fflush ( stdin ) ;
        }
        return opcion ;
    }
    if ( flag1 == 1 && flag2 == 1 )
    {
        system ( "cls" ) ;
        printf ( "1. Ingresar primer operando. (A = %.02f)\n", operador1 ) ;
        printf ( "2. Ingresar segundo operando. (B = %.02f)\n", operador2 ) ;
        printf ( "3. Calcular todas las operaciones. \n" ) ;
        printf ( "4. Informar resultados. \n" ) ;
        printf ( "5. Salir. \n" ) ;
        printf ( "Seleccione una opcion:  " ) ;
        scanf ( "%d", &opcion ) ;
        fflush ( stdin ) ;
        while ( opcion > 5 || opcion < 1 )
        {
            system ( "cls" ) ;
            printf ( "Error. opcion invalida.\n\n" ) ;
            printf ( "1. Ingresar primer operando. (A = %.02f)\n", operador1 ) ;
            printf ( "2. Ingresar segundo operando.(B = %.02f)\n", operador2 ) ;
            printf ( "3. Calcular todas las operaciones. \n" ) ;
            printf ( "4. Informar resultados. \n" ) ;
            printf ( "5. Salir. \n" ) ;
            printf ( "Seleccione una opcion:  " ) ;
            scanf ( "%d", &opcion ) ;
            fflush ( stdin ) ;
        }
        return opcion ;
    }
    return 5 ;
}
double tomarOperando ()
{
    char operando [32] ;
    int esValido ;
    double numeroValidado ;
    system ( "cls" ) ;
    printf ( "Ingrese el operando:  " ) ;
    scanf ( "%s", operando ) ;
    fflush ( stdin ) ;
    esValido = validarNumeroFlotante ( operando ) ;
    while ( esValido == 0 )
    {
        system ( "cls" ) ;
        printf ( "Error, dato invalido. Ingrese el operando:  " ) ;
        scanf ( "%s", operando ) ;
        fflush ( stdin ) ;
        esValido = validarNumeroFlotante ( operando ) ;
    }
    numeroValidado = atof ( operando ) ;
    operando [0] = '\0' ;
    return numeroValidado ;
}
int validarNumeroFlotante ( char datoParaValidar [] )
{
    int CantidadPuntos = 0 ;
    int indice = 0 ;
    int esNegativo = 0 ;
    for ( indice = 0 ; indice < strlen ( datoParaValidar ) ; indice++ )
    {
        if ( indice == 0 )
        {
            if ( datoParaValidar [ indice ] == '\0' )
            {
                return 0 ;
            }
            if ( datoParaValidar [ indice ] < '0' || datoParaValidar [ indice ] > '9' )
            {
                if ( datoParaValidar [ indice ] == '-' )
                {
                    esNegativo = 1 ;
                }
                else
                {
                    return 0 ;
                }
            }
        }
        else
        {
            if ( indice == 1 && esNegativo == 1 )
            {
                if ( datoParaValidar [ indice ] == '.' || datoParaValidar [ indice ] == '\0' )
                {
                    return 0 ;
                }
            }
            else
            {
                if ( datoParaValidar [ indice ] == '\0' )
                {
                    return 1 ;
                }
                if ( datoParaValidar [ indice ] < '0' || datoParaValidar [ indice ] > '9' )
                {
                    if ( datoParaValidar [ indice ] == '.' )
                    {
                        CantidadPuntos ++ ;
                        if ( CantidadPuntos > 1 )
                        {
                            return 0 ;
                        }
                    }
                    else
                    {
                        return 0 ;
                    }
                }
            }
        }
    }
    return 1 ;
}
int hacerCuentitas ( double op1, double op2 , double *resultado_suma , double *resultado_resta , double *resultado_division , double *resultado_multiplicacion , double *resultado_factorial_A , double *resultado_factorial_B )
{
    system ( "cls" ) ;
    printf ( "Se realizaran las siguientes operaciones:  \n\n" ) ;
    printf ( "a) Calcular la suma ( A + B ) \n" ) ;
    printf ( "b) Calcular la resta ( A - B ) \n" ) ;
    printf ( "c) Calcular la division ( A / B ) \n" ) ;
    printf ( "d) Calcular la multiplicacion ( A * B ) \n" ) ;
    printf ( "e) Calcular el factorial ( A! ) & ( B! ) \n" ) ;
    system ( "pause" ) ;
    *resultado_suma = sumarDosNumeros ( op1, op2 ) ;
    *resultado_resta = restarDosNumeros( op1, op2 ) ;
    if ( op2 != 0 )
    {
        *resultado_division = dividirDosNumeros( op1, op2 ) ;
    }
    *resultado_multiplicacion = multiplicarDosNumeros( op1, op2 ) ;
    if ( op1 < 171 && op1 >= 0 )
    {
        *resultado_factorial_A = factorialDeUnNumero ( op1 ) ;
    }
    if ( op2 < 171 && op2 >= 0 )
    {
        *resultado_factorial_B = factorialDeUnNumero ( op2 ) ;
    }
    return 1 ;
}
double sumarDosNumeros ( double op1, double op2 )
{
    double resultado ;
    resultado = op1 + op2 ;
    return resultado ;
}
double restarDosNumeros ( double op1, double op2 )
{
    double resultado ;
    resultado = op1 - op2 ;
    return resultado ;
}
double dividirDosNumeros ( double op1, double op2 )
{
    double resultado ;
    resultado = op1 / op2 ;
    return resultado ;
}
double multiplicarDosNumeros ( double op1, double op2 )
{
    double resultado ;
    resultado = op1 * op2 ;
    return resultado ;
}
double factorialDeUnNumero ( double op )
{
    double resultado = 1 ;
    int i ;
    double operador ;
    operador = trunc ( op ) ;
    if ( operador > 170 )
    {
        resultado = 0;
        return resultado ;
    }
    if ( operador < 0 )
    {
        resultado = 0 ;
        return resultado ;
    }
    if ( operador == 0 )
    {
        resultado = 1 ;
        return resultado ;
    }
    if ( operador == 1 )
    {
        resultado = 1 ;
        return resultado ;
    }
    for ( i = operador ; i > 1 ; i-- )
    {
        resultado = resultado * i ;
    }
    return resultado ;
}
void entregarResultados ( double op1, double op2, double resultado_suma, double resultado_resta, double resultado_division, double resultado_multiplicacion, double resultado_factorial_A, double resultado_factorial_B )
{
    system ( "cls" ) ;
    printf ( "Los resultados son:  \n\n" ) ;
    printf ( "a) ( A + B ) = %.02f \n", resultado_suma ) ;
    printf ( "b) ( A - B ) = %.02f \n", resultado_resta ) ;
    if ( op2 == 0 )
    {
        printf ( "c) No es posible dividir por 0 \n" ) ;
    }
    else
    {
        printf ( "c) ( A / B ) = %.02f \n", resultado_division ) ;
    }
    printf ( "d) ( A * B ) = %.02f \n", resultado_multiplicacion ) ;
    if ( ( op1 >= 171 || op1 < 0 ) && ( op2 >= 171 || op2 < 0 ) )
    {
        printf ( "e) Valores fuera de rango. No puede factorizar. \n" ) ;
    }
    if ( ( op1 < 171 && op1 >= 0 ) && ( op2 >= 171 || op2 < 0 ) )
    {
        printf ( "e) ( A! ) = %.02f & ( B! ) = Fuera de rango. \n", resultado_factorial_A ) ;
    }
    if ( (op1 >= 171 || op1 < 0 ) && (op2 < 171 && op2 >= 0 ) )
    {
        printf ( "e) ( A! ) = Fuera de rango. & ( B! ) = %.02f \n", resultado_factorial_B ) ;
    }
    if ( (op1 < 171 && op1 >= 0 ) && (op2 < 171 && op2 >= 0 ) )
    {
        printf ( "e) ( A! ) = %.02f & ( B! ) = %.02f \n", resultado_factorial_A, resultado_factorial_B ) ;
    }
    system ( "pause" ) ;
}
