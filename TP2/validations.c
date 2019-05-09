#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validations.h"
int itsFloat ( char* data )
{
    int i ;
    int len ;
    int commas = 0 ;
    int invalid = 0 ;
    int negative = 0 ;
    int isValid ;
    len = sizeof ( data ) ;
    for ( i = 0 ; i < len ; i++ )
    {
        if ( i == 0 )
        {
            if ( data [i] < '0' || data [i] > '9' )
            {
                if ( data [i] == '-' )
                {
                    negative = 1 ;
                }
                else
                {
                    invalid = 1 ;
                    break ;
                }
            }
        }
        else if ( i == 1 && negative )
        {
            if ( data [i] == '.' )
            {
                invalid = 1 ;
            }
        }
        else
        {
            if ( data [i] < '0' || data [i] > '9' )
            {
                if ( data [i] == '.' )
                {
                    commas ++ ;
                }
                else
                {
                    invalid = 1 ;
                    break ;
                }
            }
        }
    }
    if ( invalid || commas > 1 )
    {
        isValid = 0 ;
    }
    else
    {
        isValid = 1 ;
    }
    return isValid ;
}
int itsInteger ( char* data )
{
    int i ;
    int len ;
    int isValid = 1 ;
    len = sizeof ( data ) ;
    for ( i = 0 ; i < len ; i++  )
    {
        if ( data [i] < '0' || data [i] > '9' )
        {
            isValid = 1 ;
            break ;
        }
    }
    return isValid ;
}
int itsName ( char* data )
{
    int i;
    int len ;
    int spaces = 0 ;
    int isValid ;
    len = sizeof ( data ) ;
    for ( i = 0 ; i < len ; i++ )
    {
        if ( i == 0 )
        {
            if ( data[i] == ' ' )
            {
                isValid = 0 ;
                break ;
            }
        }
        if ( data[i] < 'a' || data[i] > 'z' )
        {
            if ( data[i] < 'A' || data[i] > 'Z' )
            {
                if ( data[i] == ' ' )
                {
                    spaces++;
                    if ( spaces > 4 )
                    {
                        isValid = 0 ;
                        break ;
                    }
                }
                else
                {
                    isValid = 0 ;
                    break ;
                }
            }
        }
        if ( data[i] == '\n' || data[i] == '\0' )
        {
            if ( i > 2 )
            {
                isValid = 1 ;
            }
        }

    }
    if ( len < 3 || len > 50 )
    {
        isValid = 0 ;
    }
    return isValid ;
}
int validateFloatingPointNumber ( char* givenData , double* number )
{
    int points = 0 ;
    int index = 0 ;
    int itsNegative = 0 ;
    int isValid = 1 ;
    for ( index = 0 ; index < strlen ( givenData ) ; index++ )
    {
        if ( index == 0 )
        {
            if ( givenData [ index ] == '\0' )
            {
                isValid = 0 ;
                break ;
            }
            if ( givenData [ index ] < '0' || givenData [ index ] > '9' )
            {
                if ( givenData [ index ] == '-' )
                {
                    itsNegative = 1 ;
                }
                else
                {
                    isValid = 0 ;
                    break ;
                }
            }
        }
        else
        {
            if ( index == 1 && itsNegative == 1 )
            {
                if ( givenData [ index ] == '.' || givenData [ index ] == '\0' )
                {
                    isValid = 0 ;
                    break ;
                }
            }
            else
            {
                if ( givenData [ index ] == '\0' )
                {
                    isValid = 1 ;
                    break ;
                }
                if ( givenData [ index ] < '0' || givenData [ index ] > '9' )
                {
                    if ( givenData [ index ] == '.' )
                    {
                        points ++ ;
                        if ( points > 1 )
                        {
                            isValid = 0 ;
                            break ;
                        }
                    }
                    else
                    {
                        isValid = 0 ;
                        break ;
                    }
                }
            }
        }
    }
    if ( isValid )
    {
        number[0] = atof( givenData ) ;
    }
    return isValid ;
}
