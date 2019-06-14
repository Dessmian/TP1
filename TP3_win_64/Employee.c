#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "LinkedList.h"
#include "validations.h"
#include "prints.h"
#include "Controller.h"

/* Los setter deben contener validaciones
    -pido memoria
    -cargo campos
    -si hay error libero memoria
    */
/** \brief crea un puntero a empleado y reserva memoria en el heap para dicho puntero
 *
 * \return Employee* - puntero a empleado
 *
 */
Employee* employee_new()
{
    int tries = 0;
    Employee* retEmp = NULL;
    do
    {
        retEmp =(Employee*) malloc(sizeof(Employee));
        tries++;
    }
    while (retEmp==NULL&&tries<10);
    return retEmp;
}
/** \brief crea un nuevo empleado y lo carga con los datos pasados
 *
 * \param idStr char* - ID en formato char*
 * \param nombreStr char* - nombre
 * \param horasTrabajadasStr char* - horas trabajadas
 * \param sueldoStr char* - sueldo
 * \return Employee* - puntero a empleado (si los datos son invalido el puntero sera NULL)
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* new_employee = NULL;
    if (idStr!=NULL&&nombreStr!=NULL&&horasTrabajadasStr!=NULL&&sueldoStr!=NULL)
    {
        int idOk = 0, nombreOK = 0, horasOK = 0, sueldoOK = 0;
        new_employee = employee_new();
        if (new_employee!=NULL)
        {
            if (isInt(idStr,strlen(idStr)))
            {
                int auxID = atoi(idStr);
                idOk = employee_setId(new_employee,auxID);
            }
            if (isName(nombreStr,strlen(nombreStr)))
            {
                strcpy(new_employee->nombre,nombreStr);
                nombreOK = 1;
            }
            if (isInt(horasTrabajadasStr,strlen(horasTrabajadasStr)))
            {
                int auxHoras = atoi(horasTrabajadasStr);
                horasOK = employee_setHorasTrabajadas(new_employee,auxHoras);
            }
            if (isInt(sueldoStr,strlen(sueldoStr)))
            {
                int auxSueldo = atoi(sueldoStr);
                sueldoOK = employee_setSueldo(new_employee,auxSueldo);
            }
        }
        if (idOk==0 || nombreOK == 0 || horasOK == 0 || sueldoOK == 0)
        {
            free(new_employee);
            new_employee = NULL;
        }
    }
    return new_employee;
}
/** \brief recibe un puntero a employee(auxiliar) y verifica que los datos sean validos, si lo son, reserva memoria en el heap
 *         y asigna los valores.
 *
 * \param ptrBuffer - puntero a empleado, auxiliar.
 * \return retEmployee - puntero a empleado, validado y en el heap. Si no hay memoria o se pasa un puntero nulo, devuelve un puntero nulo
 *
 */

Employee* employee_newParametrosBinarios (Employee* ptrBuffer)
{
    Employee* retEmployee = NULL;
    if (ptrBuffer!=NULL)
    {
        if ((employee_isValid(ptrBuffer)) == 1)
        {
            retEmployee = (Employee*)malloc(sizeof(Employee));
            if (retEmployee!=NULL)
            {
                retEmployee->id = ptrBuffer->id;
                strcpy(retEmployee->nombre,ptrBuffer->nombre);
                retEmployee->horasTrabajadas = ptrBuffer->horasTrabajadas;
                retEmployee->sueldo = ptrBuffer->sueldo;
            }
        }
    }
    return retEmployee;
}
/** \brief crea un nuevo empleado y lo carga con los datos pasados
 *
 * \param int inputID - char* inputName
 * \param int inputHours - int inputSalary
 * \return Employee* - puntero a empleado (si los datos son invalidos el puntero sera NULL)
 *
 */
Employee* employee_newParametrosInt (int inputID,char* inputName,int inputHours,int inputSalary)
{
    Employee* retEmployee = NULL;
    if (inputID>0&&inputName!=NULL&&inputHours>0&&inputSalary>0)
    {
        retEmployee = employee_new();
        if (retEmployee!=NULL)
        {
            retEmployee->id = inputID;
            strcpy(retEmployee->nombre,inputName);
            retEmployee->horasTrabajadas = inputHours;
            retEmployee->sueldo = inputSalary;
        }
    }
    return retEmployee;
}
/** \brief libera memoria
 *
 * \param ptrEmp Employee*
 * \return void
 *
 */
void employee_delete(Employee* ptrEmp)
{
    if (ptrEmp!=NULL)
    {
        free(ptrEmp);
    }
}
/** \brief toma un puntero a empleado y define el valor de ID
 *
 * \param ptrEmp Employee* - puntero a empleado
 * \param sueldo int* - puntero en donde guardar el valor
 * \return int - 0 si no se pudo - 1 si se pudo
 *
 */
int employee_setId(Employee* ptrEmp,int id)
{
    int retVal = 0;
    if (ptrEmp!=NULL)
    {
        if (id>0)
        {
            ptrEmp->id = id;
            retVal = 1;
        }
    }
    return retVal;
}
/** \brief toma un puntero a empleado y retorna el valor de ID
 *
 * \param ptrEmp Employee* - puntero a empleado
 * \param sueldo int* - puntero en donde guardar el valor
 * \return int - 0 si no se pudo - 1 si se pudo
 *
 */
int employee_getId(Employee* ptrEmp,int* id)
{
    int retVal = 0;
    if (ptrEmp!=NULL&&id!=NULL)
    {
        *id = ptrEmp->id;
        retVal = 1;
    }
    return retVal;
}
/** \brief toma un puntero a empleado y define el valor de Nombre
 *
 * \param ptrEmp Employee* - puntero a empleado
 * \param sueldo int* - puntero en donde guardar el valor
 * \return int - 0 si no se pudo - 1 si se pudo
 *
 */
int employee_setNombre(Employee* ptrEmp,char* nombre)
{
    int retVal = 0;
    if (ptrEmp!=NULL&&nombre!=NULL)
    {
        if (isName(nombre,strlen(nombre)))
        {
            strcpy(ptrEmp->nombre,nombre);
            retVal = 1;
        }
    }
    return retVal;
}
/** \brief toma un puntero a empleado y retorna el valor de Nombre
 *
 * \param ptrEmp Employee* - puntero a empleado
 * \param sueldo int* - puntero en donde guardar el valor
 * \return int - 0 si no se pudo - 1 si se pudo
 *
 */
int employee_getNombre(Employee* ptrEmp,char* nombre)
{
    int retVal = 0;
    if (ptrEmp!=NULL&&nombre!=NULL)
    {
        strcpy(nombre,ptrEmp->nombre);
        retVal = 1;
    }
    return retVal;
}
/** \brief toma un puntero a empleado y define el valor de Horas Trabajadas
 *
 * \param ptrEmp Employee* - puntero a empleado
 * \param sueldo int* - puntero en donde guardar el valor
 * \return int - 0 si no se pudo - 1 si se pudo
 *
 */
int employee_setHorasTrabajadas(Employee* ptrEmp,int horasTrabajadas)
{
    int retVal = 0;
    if (ptrEmp!=NULL)
    {
        if (horasTrabajadas>0)
        {
            ptrEmp->horasTrabajadas = horasTrabajadas;
            retVal = 1;
        }
    }
    return retVal;
}
/** \brief toma un puntero a empleado y retorna el valor de Horas Trabajadas
 *
 * \param ptrEmp Employee* - puntero a empleado
 * \param sueldo int* - puntero en donde guardar el valor
 * \return int - 0 si no se pudo - 1 si se pudo
 *
 */
int employee_getHorasTrabajadas(Employee* ptrEmp,int* horasTrabajadas)
{
    int retVal = 0;
    if (ptrEmp!=NULL&&horasTrabajadas!=NULL)
    {
        *horasTrabajadas = ptrEmp->horasTrabajadas;
        retVal = 1;
    }
    return retVal;
}
/** \brief toma un puntero a empleado y define el valor de Sueldo
 *
 * \param ptrEmp Employee* - puntero a empleado
 * \param sueldo int* - puntero en donde guardar el valor
 * \return int - 0 si no se pudo - 1 si se pudo
 *
 */
int employee_setSueldo(Employee* ptrEmp,int sueldo)
{
    int retVal = 0;
    if (ptrEmp!=NULL)
    {
        if (sueldo>0)
        {
            ptrEmp->sueldo = sueldo;
            retVal = 1;
        }
    }
    return retVal;
}
/** \brief toma un puntero a empleado y retorna el valor de sueldo
 *
 * \param ptrEmp Employee* - puntero a empleado
 * \param sueldo int* - puntero en donde guardar el valor
 * \return int - 0 si no se pudo - 1 si se pudo
 *
 */
int employee_getSueldo(Employee* ptrEmp,int* sueldo)
{
    int retVal = 0;
    if (ptrEmp!=NULL&&sueldo!=NULL)
    {
        *sueldo = ptrEmp->sueldo;
    }
    return retVal;
}
void printEmpHeader ()
{
    printf("\n ID  |  Nombre\t\t\t| Horas Trabajadas | Sueldo\n");
}
/** \brief imprime un empleado en consola
 *
 * \param ptrEmp Employee* - puntero al empleado a imprimir
 * \return
 *
 */
void printOneEmployee (Employee* ptrEmp)
{
    if (ptrEmp!=NULL)
    {
        char bufferName[128];
        int bufferID , bufferHours , bufferSalary;
        employee_getId(ptrEmp,&bufferID);
        employee_getNombre(ptrEmp,bufferName);
        employee_getHorasTrabajadas(ptrEmp,&bufferHours);
        employee_getSueldo(ptrEmp,&bufferSalary);
        printf(" %d  | %s\t\t| %d\t\t| %d\n",bufferID,bufferName,bufferHours,bufferSalary);
    }
}
/** \brief - interactua con el usuario y llama a las funciones correspondientes para modificar
 * los campos de un empleado
 *
 * \param ptrEmployee Employee* - puntero a empleado a modificar
 * \param pArrayListEmployee void* - puntero a LinkedList (para verificar que no se repita el id)
 * \return int - 0 si no se pudo - 1 si se modifico
 *
 */
int employee_modify (Employee* ptrEmployee,void* pArrayListEmployee)
{
    int retVal = 0;
    pArrayListEmployee = (LinkedList*)pArrayListEmployee;
    if (ptrEmployee!=NULL)
    {
        Employee* bufferEmployee = employee_newParametrosBinarios(ptrEmployee);
        if (bufferEmployee!=NULL)
        {
            int option = 0;
            while (option!=6)
            {
                clearScreen();
                printf("Datos Originales:\n");
                printEmpHeader();
                printOneEmployee(ptrEmployee);
                printf("Datos Nuevos:\n");
                printEmpHeader();
                printOneEmployee(bufferEmployee);
                newLine();
                print_employee_empModifyMenu();
                getOption(&option);
                switch (option)
                {
                case 1:
                    controller_askfor_ID(bufferEmployee);
                    break;
                case 2:
                    controller_askfor_name(bufferEmployee);
                    break;
                case 3:
                    controller_askfor_hours(bufferEmployee);
                    break;
                case 4:
                    controller_askfor_salary(bufferEmployee);
                    break;
                case 5:
                    if (employee_isValid(bufferEmployee)==1)
                    {
                        if (controller_compare_ID(pArrayListEmployee,bufferEmployee->id)==0)
                        {
                            employee_overwrite(ptrEmployee,bufferEmployee);
                            printf("\n\nCambios guardados");
                            pause();
                        }
                        else
                        {
                            if (ptrEmployee->id==bufferEmployee->id)
                            {
                                employee_overwrite(ptrEmployee,bufferEmployee);
                                printf("\n\nCambios guardados");
                                newLine();
                                pause();
                            }
                            else
                            {
                                printf("\n\nError. ID ya esta en uso\n");
                                pause();
                            }
                        }
                    }
                    else
                    {
                        printf("\n\nError. No se pueden guardar datos invalidos");
                        newLine();
                        pause();
                    }
                    break;
                default:
                    break;
                }
            }
        }
        free(bufferEmployee);
    }
    return retVal;
}
/** \brief verifica si los datos cargados para un empleado son validos
 *
 * \param ptrEmp Employee* - puntero al empleado
 * \return 0 si no son validos o el puntero es nulo - 1 si esta todo bien
 *
 */
int employee_isValid (Employee* ptrEmp)
{
    int retVal = 0;
    if (ptrEmp!=NULL)
    {
        int idOk = 0, nameOk = 0, hoursOk = 0, salaryOk = 0;
        if (ptrEmp->id > 0)
        {
            idOk = 1;
        }
        if ((isName(ptrEmp->nombre,strlen(ptrEmp->nombre)))== 1)
        {
            nameOk = 1;
        }
        if (ptrEmp->horasTrabajadas > 0)
        {
            hoursOk = 1;
        }
        if (ptrEmp->sueldo > 0)
        {
            salaryOk = 1;
        }
        if (idOk&&nameOk&&hoursOk&&salaryOk)
        {
            retVal = 1;
        }
    }
    return retVal;
}
/** \brief Busca sobre una lista a un empleado de id determinado
 *
 * \param pArrayListEmployee LinkedList* - lista empleados
 * \param IDentification int - el id a matchear
 * \return int - 0 si no se pudo - >0 (index) si lo encontro
 *
 */
int employee_getEmployeeByID(void* pArrayListEmployee, int IDentification)
{
    int retVal = 0;
    pArrayListEmployee = (LinkedList*)pArrayListEmployee;
    if (pArrayListEmployee!=NULL&&IDentification>0)
    {
        int i , lenght;
        Employee* auxPtr = NULL;
        lenght = ll_len(pArrayListEmployee);
        if (lenght>0)
        {
            for (i=0;i<lenght;i++)
            {
                auxPtr = (Employee*)ll_get(pArrayListEmployee,i);
                if (auxPtr!=NULL)
                {
                    if (auxPtr->id==IDentification)
                    {
                        retVal = i;
                        break;
                    }
                }
            }
        }
    }
    return retVal;
}
/** \brief busca sobre ua lista un empleado de nomre determinado
 *
 * \param pArrayListEmployee LinkedList*
 * \param name char*
 * \return int
 *
 */
int employee_getEmployeeByName(void* pArrayListEmployee, char* name)
{
    pArrayListEmployee = (LinkedList*)pArrayListEmployee;
    int retVal = 0;
    if (pArrayListEmployee!=NULL&&name!=NULL)
    {
        int i , lenght;
        Employee* auxPtr = NULL;
        lenght = ll_len(pArrayListEmployee);
        if (lenght>0)
        {
            for (i=0;i<lenght;i++)
            {
                auxPtr = (Employee*)ll_get(pArrayListEmployee,i);
                if (auxPtr!=NULL)
                {
                    if ( (stricmp(auxPtr->nombre,name))==0 )
                    {
                        retVal = i;
                        break;
                    }
                }
            }
        }
    }
    return retVal;
}
/** \brief recorre una lista de empleados y busca el maximo id
 *
 * \param pArraylistEmployee LinkedList* - lista de empleados
 * \return int - -1 si el puntero es nulo o la lista esta vacia - el id maximo que encuentre +1
 *
 */
int employee_getNewID (void* pArraylistEmployee)
{
    pArraylistEmployee = (LinkedList*)pArraylistEmployee;
    int retID = -1;
    if (pArraylistEmployee!=NULL)
    {
        int lenght = ll_len(pArraylistEmployee);
        if (lenght>0)
        {
            int i, maxID = 0;
            Employee* auxEmp = NULL;
            for (i=0; i<lenght; i++)
            {
                auxEmp = (Employee*)ll_get(pArraylistEmployee,i);
                if (auxEmp!=NULL)
                {
                    if ((auxEmp->id)>maxID)
                    {
                        maxID = (auxEmp->id);
                    }
                }
            }
            if (i==lenght)
            {
                retID = maxID +1;
            }
        }
    }
    return retID;
}
/** \brief compara el id de dos empleados
 *
 * \param ptrEmp1 void* - puntero a empleado
 * \param ptrEmpTwo void* - puntero a empleado
 * \return int - 0 si son iguales - 1 si el premero es mayor - -1 si el primero es menor
 *
 */
int employee_sortByID(void* ptrEmp1 ,void* ptrEmpTwo)
{
    int retVal = 0;
    if (ptrEmp1!=NULL&&ptrEmpTwo!=NULL)
    {
        ptrEmp1 = (Employee*)ptrEmp1;
        ptrEmpTwo = (Employee*)ptrEmpTwo;
        int auxInt1 , auxIntTwo;
        employee_getId(ptrEmp1,&auxInt1);
        employee_getId(ptrEmpTwo,&auxIntTwo);
        if (auxInt1>auxIntTwo)
        {
            retVal = 1;
        }
        else if (auxInt1<auxIntTwo)
        {
            retVal = -1;
        }
    }
    return retVal;
}
/** \brief compara el nombre de dos empleados
 *
 * \param ptrEmp1 void* - puntero a empleado
 * \param ptrEmpTwo void* - puntero a empleado
 * \return int - 0 si son iguales - 1 si el premero es mayor - -1 si el primero es menor
 *
 */
int employee_sortByName(void* ptrEmp1 ,void* ptrEmpTwo)
{
    int retVal = 0;
    if (ptrEmp1!=NULL&&ptrEmpTwo!=NULL)
    {
        ptrEmp1 = (Employee*)ptrEmp1;
        ptrEmpTwo = (Employee*)ptrEmpTwo;
        char auxName1 [128] , auxNameTwo [128];
        int compared;
        employee_getNombre(ptrEmp1, auxName1);
        employee_getNombre(ptrEmpTwo, auxNameTwo);
        compared = strcmp(auxName1,auxNameTwo);
        if (compared>0)
        {
            retVal = 1;
        }
        else if (compared<0)
        {
            retVal = -1;
        }
    }
    return retVal;
}
/** \brief compara las horas trabajadas de dos empleados
 *
 * \param ptrEmp1 void* - puntero a empleado
 * \param ptrEmpTwo void* - puntero a empleado
 * \return int - 0 si son iguales - 1 si el premero es mayor - -1 si el primero es menor
 *
 */
int employee_sortByHours(void* ptrEmp1 ,void* ptrEmpTwo)
{
    int retVal = 0;
    if (ptrEmp1!=NULL&&ptrEmpTwo!=NULL)
    {
        ptrEmp1 = (Employee*)ptrEmp1;
        ptrEmpTwo = (Employee*)ptrEmpTwo;
        int auxInt1 , auxIntTwo;
        employee_getHorasTrabajadas(ptrEmp1,&auxInt1);
        employee_getHorasTrabajadas(ptrEmpTwo,&auxIntTwo);
        if (auxInt1>auxIntTwo)
        {
            retVal = 1;
        }
        else if (auxInt1<auxIntTwo)
        {
            retVal = -1;
        }
    }
    return retVal;
}
/** \brief compara el salario de dos empleados
 *
 * \param ptrEmp1 void* - puntero a empleado
 * \param ptrEmpTwo void* - puntero a empleado
 * \return int - 0 si son iguales - 1 si el premero es mayor - -1 si el primero es menor
 *
 */
int employee_sortBySalary(void* ptrEmp1 ,void* ptrEmpTwo)
{
    int retVal = 0;
    if (ptrEmp1!=NULL&&ptrEmpTwo!=NULL)
    {
        ptrEmp1 = (Employee*)ptrEmp1;
        ptrEmpTwo = (Employee*)ptrEmpTwo;
        int auxInt1 , auxIntTwo;
        employee_getSueldo(ptrEmp1,&auxInt1);
        employee_getSueldo(ptrEmpTwo,&auxIntTwo);
        if (auxInt1>auxIntTwo)
        {
            retVal = 1;
        }
        else if (auxInt1<auxIntTwo)
        {
            retVal = -1;
        }
    }
    return retVal;
}
/** \brief toma dos punteros a empleado y sobreescribe los datos de uno sobre el otro.
 *
 * \param ptrToWriteOn Employee* - puntero a sobreescribir
 * \param ptrToReadFrom Employee* - puntero de donde se leen los datos
 * \return int - 1 si pudo - 0 si no pudo
 *
 */
int employee_overwrite(Employee* ptrToWriteOn,Employee* ptrToReadFrom)
{
    int retVal = 0;
    if (ptrToWriteOn!=NULL&&ptrToReadFrom!=NULL)
    {
        char bufferName[128];
        int bufferID , bufferHours , bufferSalary;
        employee_getId(ptrToReadFrom,&bufferID);
        employee_getNombre(ptrToReadFrom,bufferName);
        employee_getHorasTrabajadas(ptrToReadFrom,&bufferHours);
        employee_getSueldo(ptrToReadFrom,&bufferSalary);
        //
        employee_setId(ptrToWriteOn,bufferID);
        employee_setNombre(ptrToWriteOn,bufferName);
        employee_setHorasTrabajadas(ptrToWriteOn,bufferHours);
        employee_setSueldo(ptrToWriteOn,bufferSalary);
        retVal = 1;
    }
    return retVal;
}













































