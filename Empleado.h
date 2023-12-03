#include <iostream>
#include <string>
using namespace std;
#ifndef Empleado_H
#define Empleado_H

class Empleado {
private:
    //Declaramos nuestros atributos
    string nombre;
    string ID;
    double salario;

public:
    Empleado(string nombre = "", string iden = "", double salario = 0); //Inicializacion de parametros

    // Método para establecer el nombre del empleado
    void setNombre(string n);

    // Método para obtener el nombre del empleado
    string getNombre();

    // Método para establecer su ID
    void setID(string iden);

    // Método para obtener su ID
    string getID();

    // Método para establecer el salario
    void setSalario(double s);

    // Método para obtener el salario
    double getSalario();

    // Método para aumentar los bonos al empleado
    void modificacionSalario(double m);

    // Método para mostrar datos generales de los empleados
    void muestra();

    // Método para mostrar los datos generales del empleado de acuerdo a su ID
    void muestraPorID(string idBuscar);


};

#endif
