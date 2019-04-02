#ifndef FUNCIONES_TP1_H_INCLUDED
#define FUNCIONES_TP1_H_INCLUDED
/** \brief Limpia la pantalla e imprime el menu de opciones, si los parametros estan definidos, los imprime en el lugar correspondiente.
 *
 * \param operador1 y operador2 son los numeros a imprimir en pantalla.
 * \param flag1 y flag2 se usan para saber si los respectivos operadores estan definidos. Si los flags valen 1 imprime los resultados, si valen 2 no los imprime. No es necesario que los flags valgan lo mismo.
 * \return Retorna la opcion del que el ususario halla elegido, este valor sera un entero entre el 1 y el 5 inclusives.
 *
 */
int imprimirMenuDeOpciones ( double operador1, double operador2, int flag1, int flag2 ) ;

/** \brief Limpia la pantalla y pide un dato. Guarda el dato en un array de caracteres con maximo de 32 digitos. Y llama a otra funcion para validar que sea un numero.
 *
 * \param
 * \param
 * \return Retorna un numero validado y en formato double.
 *
 */
double tomarOperando () ;

/** \brief Toma un dato de tipo char [] y valida que sea un numero.
 *
 * \param Requiere un dato tipo char [].
 * \param
 * \return Si es un numero valido retorna 1. De lo contrario retorna 0.
 *
 */
int validarNumeroFlotante ( char datoParaValidar [] ) ;

/** \brief Toma dos numeros en formato double y los suma.
 *
 * \param Primer numero. op1
 * \param Segundo numero. op2
 * \return Retorna el resultado de la suma en formato double.
 *
 */
double sumarDosNumeros ( double op1, double op2 ) ;

/** \brief Toma dos numero y los resta ( op1 - op2 )
 *
 * \param Primer numero. op1
 * \param Segundo numero. op2
 * \return Retorna el resultado de la resta.
 *
 */
double restarDosNumeros ( double op1, double op2 ) ;

/** \brief Toma dos numero y divide op1 / op2 . No valida datos, va a intentar dividir por 0 si le dan la oportunidad.
 *
 * \param Primer numero. op1
 * \param Segundo numero. op2
 * \return Retorna el resultado de la division.
 *
 */
double dividirDosNumeros ( double op1, double op2 ) ;

/** \brief Toma dos numero y los multiplica. op1 * op2
 *
 * \param Primer numero. op1
 * \param Segundo numero. op2
 * \return Retorna el resultado de la multiplicacion.
 *
 */
double multiplicarDosNumeros ( double op1, double op2 ) ;

/** \brief Toma un numero, lo trunca y si es menor a 171 calcula el factorial.
 *
 * \param Numero, preferentemente positivo, en formato double.
 * \param
 * \return Si el numero ingresado en negativo retorna 0. Si el numero esta entre 0 y 170 retorna el factorial. Si el numero es mayor a 170 retorna 0.
 *
 */
double factorialDeUnNumero ( double op ) ;

/** \brief Toma datos... muchos datos. Entrega op1 y op2 a distintas funciones y entrega los retornos a los punteros correspondientes.
 *
 * \param op1 y op2 son los numeros s operar.
 * \param En las direcciones de memoria guarda los resultados correspondientes.
 * \return Retorna 1 luego de ejecutarse. (posible flag)
 *
 */
int hacerCuentitas ( double op1, double op2 , double *resultado_suma , double *resultado_resta , double *resultado_division , double *resultado_multiplicacion , double *resultado_factorial_A , double *resultado_factorial_B ) ;

/** \brief Limpia la pantalla y utiliza los datos tomados para imprimir los resultados.
 *
 * \param Usa op1 y op2 para saber si hay datos validos en las variables resultado_ . Tiene en cuenta divisiones por 0 y factoriales con mas de 309 digitos.
 * \param Las variables resultado deben contener los datos previamente a ser ingresadas a la funcion.
 * \return
 *
 */
void entregarResultados ( double op1, double op2, double resultado_suma, double resultado_resta, double resultado_division, double resultado_multiplicacion, double resultado_factorial_A, double resultado_factorial_B ) ;
#endif // FUNCIONES_TP1_H_INCLUDED
