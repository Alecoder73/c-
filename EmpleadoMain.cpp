
//Integrantes: Azul Paniagua Bucio y Alejandra Galván Bojórquez

#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

Empleado::Empleado(string n, string iden, double s) : nombre(n), ID(iden), salario(s) {}

// Método para establecer el nombre del empleado
void Empleado::setNombre(string n) {
    nombre = n;
}

// Método para obtener el nombre del empleado
string Empleado::getNombre() {
    return nombre;
}

// Método para establecer su ID
void Empleado::setID(string iden) {
    ID = iden;
}

// Método para obtener su ID
string Empleado::getID() {
    return ID;
}

// Método para establecer el salario
void Empleado::setSalario(double s) {
    salario = s;
}

// Método para actualizar el salario segun los bonos o penalizaciones del empleado
void Empleado::modificacionSalario(double m) {
    salario += m;
}

// Método para obtener el salario
double Empleado::getSalario() {
    return salario;
}

// Método para mostrar datos generales de los empleados
void Empleado::muestra() {
    cout << "Nombre: " << nombre << " ID: " << ID << " ";
}

// Método para mostrar datos generales del empleado de acuerdo a su ID
void Empleado::muestraPorID(string idBuscar) {
    if (ID == idBuscar) {
        cout << "Nombre: " << nombre << " ID: " << ID << " ";
    }
}






int main() {

    //Declaramos la contraseña del programa
    string contrasena = "1234";
    string password = "";
    cout << "Ingrese la contrasena: ";
    cin >> password;
    //Validacion de la contraseña
    while (password != contrasena) {
        cout << "Contrasena incorrecta. Vuelva a intentar: ";
        cin >> password;

    }
    cout << "Acceso concedido. Bienvenido. \n"
         << "\n";
    //Declaramos el resto de las variables que contempla el programa
    string nombre;
    string iden;
    double salario;
    bool salir=false;
    int MAX_EMPLEADOS;
    char opcion;

    cout << "Numero de empleados en la empresa: ";
    cin >> MAX_EMPLEADOS;

    Empleado empleadoArray[MAX_EMPLEADOS];
    int anadidos = 0;
    int decision;
    string idBuscar;
    int horas;
    double bonoPorHora;
    int actividades;
    double bonoPorActividad;
    double modificacionSalario;
    int penalizaciones;
    double restaPorPenalizacion;
    bool encontrado = false;

    do {
        cout << "\n"
             << "Menu de Opciones: \n"
             << "a) Agregar Empleado \n"
             << "b) Mostrar Empleados \n"
             << "c) Modificar Empleado \n"
             << "d) Eliminar Empleado \n"
             << "e) Salarios, Bonos y Penalizaciones \n"
             << "f) Salir \n"
             << "Ingrese su opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 'a': {
                if (anadidos < MAX_EMPLEADOS){
                    cout << "Ingrese el nombre del empleado: ";
                    cin.ignore(); 
                    getline(cin, nombre);  // Para que acepte apellidos
                    cout << "Ingrese el ID del empleado: ";
                    cin >> iden;
                    salario = 0;
                    bool validar = false;
                    Empleado persona(nombre, iden, salario); //Creamos un objeto para almacenar el nombre, ID y salario de la persona
                    for (int i=0;i<anadidos;i++){
                        if (empleadoArray[i].getID() == iden){ //Validacion del ID para evitar empleados repetidos
                            cout << "Ya existe un empleado con ese ID \n";
                            validar = true;
                            break;
                        }
                    }
                    if (validar == false) { //Añade a la persona en nuestro arreglo de empleados
                        empleadoArray[anadidos] = persona;
                        anadidos += 1;
                    }
                } else {
                    cout << "Limite de empleados alcanzado \n";
                }
                break;

            }
            case 'b': { //Menu para mostrar todos los empleados o por un ID en especifico
                cout << "Menu de opciones: \n"
                     << "1. Mostrar todos \n"
                     << "2. Buscar por ID \n"
                     << "Ingrese su opcion: ";
                cin >> decision;
                if (decision == 1 || decision == 2){
                    switch (decision) {
                        case 1: {
                            for (int i=0; i<anadidos; i++){ //Recorre todo el arreglo de los empleados para mostrarlos
                                empleadoArray[i].muestra();
                                cout << "\n";
                            }
                            break;
                        }
                        case 2: {
                            cout << "Ingrese el ID del empleado: ";
                            encontrado = false;
                            cin >> idBuscar;
                            for (int i = 0; i < anadidos; i++) { //Busca en el array el ID ingresado y muestra al empleado correspondiente
                                empleadoArray[i].muestraPorID(idBuscar);
                                if (empleadoArray[i].getID() == idBuscar) {
                                    encontrado = true;
                                    break;
                                }
                            }
                            if (encontrado==false) {
                                cout << "Empleado no encontrado \n";
                            }
                            break;
                        }
                    }
                } else {
                    cout << "La opcion no es valida. \n";
                }
                break;

            }
            case 'c': { //Menu para modificar el nombre, ID o salario del empleado
                cout << "Menu de opciones \n"
                     << "1. Cambiar nombre \n"
                     << "2. Cambiar ID \n"
                     << "3. Cambiar salario \n"
                     << "Ingrese su opcion: ";
                cin >> decision;
                switch (decision) {
                    case 1: {
                        cout << "Ingrese el ID del empleado a modificar: ";
                        cin >> idBuscar;
                        encontrado = false;
                        for (int i = 0; i < anadidos; i++) {
                            if (empleadoArray[i].getID() == idBuscar) {
                                encontrado = true;
                                cout << "Ingrese el nuevo nombre del empleado: ";
                                cin >> nombre;
                                empleadoArray[i].setNombre(nombre);
                                cout << "Empleado modificado con exito \n";
                                break;
                            }
                        }
                        if (encontrado==false) {
                            cout << "Empleado no encontrado \n";
                        }
                        break;
                    }
                    case 2: {
                        cout << "Ingrese el ID del empleado a modificar: ";
                        cin >> idBuscar;
                        encontrado = false;
                        for (int i=0;i<anadidos;i++) {
                            if (empleadoArray[i].getID() == idBuscar) {
                                encontrado = true;
                                cout << "Ingrese el nuevo ID del empleado: ";
                                cin >> iden;
                                empleadoArray[i].setID(iden);
                                cout << "Empleado modificado con exito \n";
                                break;
                            }
                        }
                        if (encontrado==false) {
                            cout << "Empleado no encontrado \n";
                        }

                        break;
                    }
                    case 3: {
                        cout << "Ingrese el ID del empleado a modificar: ";
                        cin >> idBuscar;
                        encontrado = false;
                        for (int i=0;i<anadidos;i++) {
                            if (empleadoArray[i].getID() == idBuscar) {
                                encontrado = true;
                                cout << "Ingrese el nuevo salario del empleado: ";
                                cin >> salario;
                                empleadoArray[i].setSalario(salario);
                                cout << "Empleado modificado con exito \n";
                                break;
                            }
                        }
                        if (encontrado==false) {
                            cout << "Empleado no encontrado \n";
                        }
                        break;
                    }
                    default: {
                        cout << "La opcion no es valida \n";
                        break;
                    }
                }
                break;
            }
            case 'd': {
                cout << "Ingrese el ID del empleado a eliminar: ";
                cin >> idBuscar;
                encontrado = false;
                for (int i=0;i<anadidos;i++) {
                    if (empleadoArray[i].getID() == idBuscar) {
                        encontrado = true;
                        for (int j = i; j < anadidos - 1; j++) {
                            empleadoArray[j] = empleadoArray[j + 1]; //Reemplazamos el empleado eliminado por el empleado en la posición siguiente
                        }
                        anadidos -= 1; //Actualizamos el numero de añadidos
                        cout << "Empleado eliminado con exito \n";
                        break;
                    }
                }
                if (encontrado==false) {
                    cout << "Empleado no encontrado \n";
                }
                break;
            }
            case 'e': {
                cout << "Menu de opciones \n"
                     << "1. Asignar salario \n"
                     << "2. Aplicar Bonos \n"
                     << "3. Aplicar Penalizaciones \n"
                     << "4. Consultar salarios \n"
                     << "Ingrese su opcion: ";
                int decision;
                cin >> decision;
                switch (decision) {
                    case 1: { //Asigna el salario
                        cout << "Ingrese el ID del empleado al que se le quiere asignar el salario: ";
                        encontrado = false;
                        cin >> idBuscar;
                        for (int i = 0; i < anadidos; i++) {
                            if (empleadoArray[i].getID() == idBuscar) { //Recorremos nuestro arreglo de empleados hasta encontrar el ID
                                cout << "Ingrese el salario base del empleado: ";
                                cin >> salario;
                                empleadoArray[i].setSalario(salario); //Asignamos el valor del salario
                                encontrado=true;
                                break;
                            }
                        }
                        if (encontrado==false) {
                            cout << "Empleado no encontrado \n";
                        }
                        break;
                    }
                    case 2: { //Aplica el bono
                        cout << "Ingrese el ID del empleado al que se le quiere aplicar un bono: ";
                        string idBuscar;
                        bool encontrado = false;
                        cin >> idBuscar;
                        //Obtenemos las horas y actividades extras realizadas, asi como el bono correspondiente a cada una
                        cout << "Ingrese las horas extras trabajadas por el empleado: ";
                        cin >> horas;
                        cout << "Ingrese el bono por hora extra: ";
                        cin >> bonoPorHora;
                        cout << "Ingrese las actividades extra realizadas por el empleado: ";
                        cin >> actividades;
                        cout << "Ingrese el bono por actividades extra: ";
                        cin >> bonoPorActividad;
                        modificacionSalario = (horas*bonoPorHora)+(actividades*bonoPorActividad); //Calculamos la cantidad total ganada por bonos
                        for (int i = 0; i < anadidos; i++) {
                            if (empleadoArray[i].getID() == idBuscar) {
                                empleadoArray[i].modificacionSalario(modificacionSalario);
                                encontrado=true;
                                cout << "Salario total del empleado: " << empleadoArray[i].getSalario() << endl;
                                break;
                            }
                        }
                        if (encontrado==false) {
                            cout << "Empleado no encontrado \n";
                        }
                        break;
                    }
                    case 3: {
                        cout << "Ingrese el ID del empleado al que se le quiere aplicar una penalización: ";
                        string idBuscar;
                        bool encontrado = false;
                        cin >> idBuscar;
                        //Obtenemos el numero de penalizaciones y el decremento al que equivale cada una
                        cout << "Ingrese el numero de penalizaciones del empleado: ";
                        cin >> penalizaciones;
                        cout << "Ingrese el decremento de salario por penalización: ";
                        cin >> restaPorPenalizacion;
                        modificacionSalario = (penalizaciones*restaPorPenalizacion)*(-1); //Calculamos la cantidad total perdida por penalizacion
                        for (int i = 0; i < anadidos; i++) {
                            if (empleadoArray[i].getID() == idBuscar) {
                                empleadoArray[i].modificacionSalario(modificacionSalario);
                                encontrado=true;
                                cout << "Salario total del empleado: " << empleadoArray[i].getSalario() << endl;
                                break;
                            }
                        }
                        if (encontrado==false) {
                            cout << "Empleado no encontrado \n";
                        }
                        break;
                    }
                    case 4: { //Consulta de salarios total o por ID
                        cout << "Menu de opciones \n"
                             << "1. Consultar salario de todos los empleados \n"
                             << "2. Consultar salario de un empleado \n"
                             << "Ingrese su opcion: ";
                        cin >> decision;
                        switch (decision) {
                            case 1: { //Imprime el salario de todos los empleados
                                for (int i=0;i<anadidos;i++) {
                                    empleadoArray[i].muestra();
                                    cout << "Salario total: " << empleadoArray[i].getSalario() << endl;
                                }
                                break;
                            }
                            case 2: { //Imprime el salario de un ID de empleado especifico
                                cout << "Ingrese el ID del empleado: ";
                                encontrado = false;
                                cin >> idBuscar;
                                for (int i = 0; i < anadidos; i++) {
                                    empleadoArray[i].muestraPorID(idBuscar);
                                    if (empleadoArray[i].getID() == idBuscar) {
                                        cout << "Salario total: " << empleadoArray[i].getSalario() << endl;
                                        encontrado = true;
                                        break;
                                    }
                                }
                                if (encontrado==false) {
                                    cout << "Empleado no encontrado \n";
                                }
                                break;
                            }
                            default: {
                                cout << "La opcion no es valida \n";
                                break;
                            }
                        }
                        break;
                    }
                    default: {
                        cout << "La opcion no es valida \n";
                        break;
                    }
                }
                break;
            }
            case 'f': {
                cout << "El programa ha sido cerrado con exito";
                salir = true;
                break;
            }
            default: {
                cout << "La opcion no es valida \n";
                break;
            }
        }
    } while (salir==false);

    return 0;
}