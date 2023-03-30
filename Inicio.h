#include <algorithm>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;
class Inicio {
public:
  string pedir_nombre(){
    string nombre;
    cout << " Por favor ingrese el nombre del producto " << endl;
    cin >> nombre;
    transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);
    return nombre;
  }

  string pedir_tipo() {
    int tipo;
    bool retorna = false;
    cout << " Por favor ingrese el tipo del producto: " << endl
         << " 1. Deportivo" << endl
         << " 2. Tecnológico" << endl
        << " 3. Extranjero"<<endl;
    cin >> tipo;
    switch(tipo){
      case 1:{
        return "deportivo";
        break;
      }
      case 2:{
         return "tecnologico";
        break;
      }
      case 3:{
        return "extranjero";
      }
      default:{
       cout << "Sólo es posible agregar articulos de tipo Deportivo o Tecnologico"
          << endl;
      return pedir_tipo();
        break;
      }
    }
    
  }

  int pedir_cantidad() {
    int cantidad;
    cout << " Por favor ingrese la cantidad del producto" << endl;
    cin >> cantidad;
    return cantidad;
  }
int pedir_impuesto() {
    int impuesto;
    cout << " Por favor ingrese el impuesto del producto" << endl;
    cin >> impuesto;
    return impuesto;
  }

  int pedir_precio() {
    int precio;
    cout << " Por favor ingrese el precio del producto" << endl;
    cin >> precio;
    return precio;
  }

  int pedir_Id(){
    int Id;
    cout << " Por favor ingrese el Id del producto" << endl;
    cin >> Id;
    return Id;
  }
};