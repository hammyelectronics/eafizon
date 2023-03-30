#include "Usuario.h"
#include <iostream>

using namespace std;
class Sistema {
public:
  void iniciar(Inventario *inventario_inicial) {
    string nombre_usuario;
    cout << " Bienvenido a Eafizon" << endl
         << " Ingrese su nombre por favor" << endl;
    cin >> nombre_usuario;
    cout << " " << nombre_usuario
         << ", indique por favor que que tipo de usuario es" << endl
         << " 1. Coordinador" << endl
         << " 2. Cliente" << endl;
    int caso;
    cin >> caso;
    switch (caso) {
    case 1: {
      Usuario *c1 = new Coordinador(nombre_usuario);
      c1->mostrar_menu(inventario_inicial);
      cout << " Coordinador " << nombre_usuario << " cerrando sesion...."
           << endl;
      iniciar(inventario_inicial);
      break;
    }
    case 2: {
      Usuario *c1 = new Cliente(nombre_usuario);
      c1->mostrar_menu(inventario_inicial);
      cout << " Cliente " << nombre_usuario << " cerrando sesion...." << endl;
      iniciar(inventario_inicial);
      break;
    }
    default:{
      cout<<" Eleccion incorrecta"<<endl;
      iniciar(inventario_inicial);
    }
    }
  }
};