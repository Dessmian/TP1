#ifndef EMPLEOYEEFUNCTIONS_H_INCLUDED
#define EMPLEOYEEFUNCTIONS_H_INCLUDED
typedef struct
{
    int id ;
    char name [51] ;
    char lastName [51] ;
    double salary ;
    int sector ;
    int isEmpty ;
} sEmployee ;


#endif // EMPLEOYEEFUNCTIONS_H_INCLUDED
/** \brief initializes the array, fills every component of the structure to make sure that no trash is picked from the memory
 *
 * \param the structures array
 * \param the lenght of the array
 * \return
 *
 */
void initializeEmpleoyeeArray ( sEmployee* , int ) ;
/** \brief deletes the data from a given employee
 *
 * \param the employee array
 * \param the index of said employee
 * \return
 *
 */
void deleteInvalidData ( sEmployee* , int ) ;
/** \brief sets the isEmpty field to 1
 *
 * \param sEmployee*  the employee array
 * \param int  the employee array
 * \return int if the given data is valid returns 0 , else returns -1
 *
 */
int initEmployees( sEmployee* , int ) ;
/** \brief loads the given data on an empty spot on the array
 *
 * \param sEmployee* the employye array
 * \param int the lenght of the array
 * \param int  the id of the employee
 * \param [] char  the name of said employee
 * \param [] char   the las name of the employee
 * \param double the salary
 * \param int   the sector
 * \param int   the index
 * \return int  if the data is correct returns 0 , else returns -1
 *
 */
int addEmployee( sEmployee* , int , int , char [] , char [] , double , int , int ) ;
/** \brief fins an employee with a given id
 *
 * \param the employee list
 * \param the lenght of said list
 * \param the id
 * \param a place to store the wanted employee index
 * \return returns 1 if the employee exist, else returns 0
 *
 */
int findEmployeeById ( sEmployee* , int , int , int* ) ;
/** \brief sets the isEmpty field to 1
 *
 * \param employee list
 * \param employee index
 * \return
 *
 */
void removeEmployee ( sEmployee* , int ) ;
/** \brief sorts employes ; prioritizes sector ; then last name ; then name ; then id
 *
 * \param sEmployee* the list
 * \param int the lenght
 * \param int 1 for smallest to biggest ; 0 biggest to samllest
 * \return int once sorted returns 0 ; if failed returns -1
 *
 */
int sortEmployees( sEmployee* , int , int ) ;
/** \brief prints a list of all the employees ; includes a header
 *
 * \param employee array
 * \param lenght
 * \return
 *
 */
void printEmployees ( sEmployee* , int ) ;
/** \brief prints one employee ; has no header
 *
 * \param employee
 * \param
 * \return
 *
 */
void printOneEmployee ( sEmployee ) ;
/** \brief checks for loaded data
 *
 * \param employee array
 * \param lenght
 * \return returns 1 if the is loaded data ; else returns 0
 *
 */
int thereIsData ( sEmployee* , int ) ;
/** \brief prints an employee and gives options to modify it
 *
 * \param employee array
 * \param employee index
 * \return
 *
 */
void modifyEmployee ( sEmployee* , int ) ;
/** \brief prints the main menu and returns a selected option
 *
 * \param
 * \param
 * \return selected option
 *
 */
int printMenuGetOption () ;
/** \brief asks for the necesary data and fills an array slot
 *
 * \param employee array
 * \param lenght
 * \return 0 if it could't load the data ; 1 if it cuold
 *
 */
int getData ( sEmployee* , int ) ;
/** \brief generates a new id
 *
 * \param employee list
 * \param lenght
 * \return a new id
 *
 */
int getNewID ( sEmployee* , int ) ;
/** \brief ask for a last name and validates the data ( at least a little :) )
 *
 * \param a place to store the name ; max 51 characters
 * \param
 * \return 1 if loaded ; 0 if not
 *
 */
int getLastName ( char* ) ;
/** \brief finds space on the array
 *
 * \param the array
 * \param lenght
 * \return empty space index
 *
 */
int getEmptySpace ( sEmployee*, int ) ;
/** \brief ask for a salary validates a floating point number
 *
 * \param a place to store the salary
 * \param
 * \return 1 if everything ok ; 0 if not
 *
 */
int getSalary ( double* ) ;
/** \brief ask for a sector ; validates integer
 *
 * \param a place to store the sector
 * \param
 * \return 1 if everything ok ; 0 if not
 *
 */
int getSector ( int* ) ;
/** \brief ask for a name and validates the data ( at least a little :) )
 *
 * \param a place to store the name ; max 51 characters
 * \param
 * \return 1 if loaded ; 0 if not
 *
 */
int getName ( char* ) ;
/** \brief a cool exit screen
 *
 * \param
 * \param
 * \return
 *
 */
void exitSignature () ;
void addID ( sEmployee* , int , int ) ;             // brief loads a given value
void addName ( sEmployee* , int , char* ) ;         // param employee array
void addLastName ( sEmployee* , int , char* ) ;     // param lenght
void addSector ( sEmployee* , int , int ) ;         // param the value to load
void addSalary ( sEmployee* , int , double ) ;      //
/** \brief just a header
 *
 * \param
 * \param
 * \return
 *
 */
void headerEmployee () ;
/** \brief loads some data ; used for testing
 *
 * \param
 * \param
 * \return
 *
 */
void forTestingPorpuses ( sEmployee* ) ;

