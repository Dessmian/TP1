#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
Employee* employee_newParametrosBinarios (Employee* ptrBuffer);
Employee* employee_newParametrosInt (int inputID,char* inputName,int inputHours,int inputSalary);
void employee_delete();

int employee_setId(Employee* ptrEmp,int id);
int employee_getId(Employee* ptrEmp,int* id);

int employee_setNombre(Employee* ptrEmp,char* nombre);
int employee_getNombre(Employee* ptrEmp,char* nombre);

int employee_setHorasTrabajadas(Employee* ptrEmp,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* ptrEmp,int* horasTrabajadas);

int employee_setSueldo(Employee* ptrEmp,int sueldo);
int employee_getSueldo(Employee* ptrEmp,int* sueldo);

void printEmpHeader ();
void printOneEmployee (Employee* ptrEmp);

int employee_modify (Employee* ptrEmployee,void* pArrayListEmployee);

int employee_isValid (Employee* ptrEmp);

int employee_getEmployeeByID(void* pArrayListEmployee, int IDentification);
int employee_getEmployeeByName(void* pArrayListEmployee, char* name);
int employee_getNewID (void* pArraylistEmployee);

int employee_sortByID(void* ptrEmp1 ,void* ptrEmpTwo);
int employee_sortByName(void* ptrEmp1 ,void* ptrEmpTwo);
int employee_sortByHours(void* ptrEmp1 ,void* ptrEmpTwo);
int employee_sortBySalary(void* ptrEmp1 ,void* ptrEmpTwo);


#endif // employee_H_INCLUDED
