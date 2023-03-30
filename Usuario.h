#include "Inicio.h"
#include "Inventario.h"
#include <iostream>
using namespace std;

class Usuario {
public:
  Inventario *carrito;
  string nombre;

  Usuario(string n) {
    nombre = n;
    carrito = new Inventario();
  }
  virtual void mostrar_menu(Inventario *lista_inicial) {}

  void volver_menu(Inventario *inventario_inicial) {
    int eleccion;
    cout << " ¿Desea acceder de nuevo al menu de este usuario?" << endl
         << " 1. Si" << endl
         << " 2. NO" << endl;
    cin >> eleccion;
    if (eleccion == 1) {
      mostrar_menu(inventario_inicial);
    }
    else if (eleccion == 2) {
      
      cout << " Gracias. " << endl;
    }
    else if(eleccion != 1){
      cout<<"Esta elección no está disponible. Inténtelo nuevamente"<<endl;
      volver_menu(inventario_inicial);
    }
  }
};

class Cliente : public Usuario {
public:
  Cliente(string n) : Usuario(n) {}

  void mostrar_menu(Inventario *inventario_inicial) {

    string n = this->nombre;
    int decision;
    cout << " Cliente " << n << " ¿que desea hacer?:" << endl;
    cout << " 1. Agregar artículo al carrito" << endl;
    cout << " 2. Modificar cantidad de un artículo" << endl;
    cout << " 3. Eliminar un artículo del carrito" << endl;
    cout << " 4. Pagar articulos" << endl;
    cin >> decision;
    switch (decision) {
    case 1: {
      agregar_al_carrito(inventario_inicial, this->carrito);
      volver_menu(inventario_inicial);
      break;
    }
    case 2: {
      int id_modificar;
      int cantidad;
      cout << " Por favor ingrese el Id del producto" << endl;
      cin >> id_modificar;
      if (inventario_inicial->existe(id_modificar)) {
        cout << " Por favor ingrese la nueva cantidad que desea" << endl;
        cin >> cantidad;
        Node *nodo_inventario = inventario_inicial->head;
        Node *nodo_carrito = carrito->head;
        if (carrito->existe(id_modificar)) {
          while (nodo_inventario->producto->id != id_modificar) {
            nodo_inventario = nodo_inventario->next;
          }
          while (nodo_carrito->producto->id != id_modificar) {
            nodo_carrito = nodo_carrito->next;
          }

          if (cantidad <= (nodo_inventario->producto->cantidad +
                           nodo_carrito->producto->cantidad)) {
            if (cantidad > nodo_carrito->producto->cantidad) {
              nodo_inventario->producto->cantidad =
                  nodo_inventario->producto->cantidad +
                  nodo_carrito->producto->cantidad - cantidad;

            } else if (cantidad < nodo_carrito->producto->cantidad) {
              nodo_inventario->producto->cantidad =
                  nodo_inventario->producto->cantidad +
                  nodo_carrito->producto->cantidad - cantidad;
            }
            nodo_carrito->producto->cantidad = cantidad;
            cout << " La cantidad del artículo ha sido modificada a "
                 << cantidad << endl
                 << "Carrito:" << endl;
            carrito->imprimir();
            cout << "Inventario: " << endl;
            inventario_inicial->imprimir();
            volver_menu(inventario_inicial);

          } else {
            cout << " La cantidad indicada excede el número de unidades "
                    "disponibles"
                 << endl;
            volver_menu(inventario_inicial);
          }
        } else {
          cout << " El ID del artículo que usted ingresó no se encuentra en su "
                  "carrito"
               << endl;
          volver_menu(inventario_inicial);
        }
      } else {
        cout << " El ID que usted ingresó no corresponde con ningún artículo"
             << endl;
        volver_menu(inventario_inicial);
      }
      break;
    }

    case 3: {
      int id_eliminar;
      cout << " Por favor ingrese el Id del producto" << endl;
      cin >> id_eliminar;
      Node *nodo_inventario = inventario_inicial->head;
      Node *nodo_carrito = carrito->head;
      if (inventario_inicial->existe(id_eliminar)) {
        if (carrito->existe(id_eliminar)) {
          while (nodo_inventario->producto->id != id_eliminar) {
            nodo_inventario = nodo_inventario->next;
          }
          while (nodo_carrito->producto->id != id_eliminar) {
            nodo_carrito = nodo_carrito->next;
          }
          nodo_inventario->producto->cantidad =
              nodo_inventario->producto->cantidad +
              nodo_carrito->producto->cantidad;
          carrito->eliminar(id_eliminar);
          cout << " El artículo ha sido eliminado de su carrito" << endl
               << "Carrito:" << endl;
          carrito->imprimir();
          cout << endl 
               <<"Inventario: " << endl;
          inventario_inicial->imprimir();
          volver_menu(inventario_inicial);
        } else {
          cout << " El ID del artículo que usted ingresó no se encuentra en su "
                  "carrito"
               << endl;
          volver_menu(inventario_inicial);
        }
      } else {
        cout << " El ID que usted ingresó no corresponde con ningún artículo"
             << endl;
        volver_menu(inventario_inicial);
      }
      break;
    }

    case 4: {
      float precio = calcular_precio_carrito(this->carrito, inventario_inicial);
      //cout<<" El precio del carrito es de: "<<precio<<endl;
      //Node *nodo_inventario = inventario_inicial->head;
      //Node *nodo_carrito = carrito->head;
      pagar_o_cancelar(precio, inventario_inicial, carrito);
      volver_menu(inventario_inicial);
    }
    default: {
      cout << " Eleccion incorrecta, intentelo de nuevo" << endl;
      mostrar_menu(inventario_inicial);
    }
      
    }
  }

  void agregar_al_carrito(Inventario *inventario_inicial, Inventario *carrito) {
    cout<<"INVENTARIO"<<endl;
      inventario_inicial->imprimir();
    int id;
    cout << " Ingrese el Id del producto que quiere comprar" << endl;
    cin >> id;

    
    if (inventario_inicial->existe(id) == true) {
      Node *temp = inventario_inicial->head;
      Node *nodo_inventario;
      while (temp) {
       
        if (temp->producto->id == id) {
          nodo_inventario = temp;
          break;
        } else {
          temp = temp->next;
        }
      }
      
      cambiar_cant_inventario_carrito(nodo_inventario, carrito);
      cout << endl << endl << "CARRITO" << endl;
      this->carrito->imprimir();
    } else {
      cout << " El Id de producto que ingresó no existe. Por favor verifíquelo "
              "e intente nuevamente";
      agregar_al_carrito(inventario_inicial, carrito);
    }
    int eleccion;
    cout << " ¿Desea agregar otro producto al carrito?" << endl
         << " 1. Si" << endl
         << " 2. No" << endl;
    cin >> eleccion;
    if (eleccion != 1 and eleccion != 2) {
      cout << "Eleccion incorrecta intentelo de nuevo" << endl;
    }
    switch (eleccion) {
    case 1: {
      cout << "CARRITO" << endl;
      agregar_al_carrito(inventario_inicial, carrito);
    }
    }
  }

  void cambiar_cant_inventario_carrito(Node *nodo_inventario,
                                       Inventario *carrito) {
    
    if (nodo_inventario->producto->disponibilidad == false) {
      cout << " El producto seleccionado no cuenta con disponibilidad" << endl;
    } else {
      int cant_carrito;
      cout << " Ingrese la cantidad  del producto que desea comprar" << endl;
      cin >> cant_carrito;
      cout << cant_carrito << endl;
      if (cant_carrito <= nodo_inventario->producto->cantidad) {
        string n = nodo_inventario->producto->nombre;
        string tipo = nodo_inventario->producto->tipo;
        int precio = nodo_inventario->producto->precio;
        int impuesto = 0;

        
        if(dynamic_cast<Extranjero*>(nodo_inventario->producto)){
          Extranjero* producto = dynamic_cast<Extranjero*>(nodo_inventario->producto);
          impuesto = producto->impuesto;
          carrito->agregar_al_final(n, tipo, cant_carrito, precio, impuesto);
        } else {
          carrito->agregar_al_final(n, tipo, cant_carrito, precio);
        }


      
        
        nodo_inventario->producto->cantidad = nodo_inventario->producto->cantidad - cant_carrito;

      
        
        if (nodo_inventario->producto->cantidad > 0) {
          nodo_inventario->producto->disponibilidad = true;
        } else {
          nodo_inventario->producto->disponibilidad = false;
        }

       
        
        Node *temp = carrito->head;
       cout<<temp->producto->nombre;
    
        while (temp) {
          
          cout << temp->producto << endl;
          if (temp->next == NULL) {
            temp->producto->id = nodo_inventario->producto->id;
          }
          temp = temp->next;
        }

        cout << " Producto agregado al carrito" << endl;
      } else {
        cout << " La cantidad ingresada supera el numero de existencias"
             << endl;
        cambiar_cant_inventario_carrito(nodo_inventario, carrito);
      }
    }
  }

  float calcular_precio_carrito(Inventario *carrito,
                              Inventario *inventario_inicial) {
    Node *temp = carrito->head;
    float total = 0;
    if (temp == NULL) {
      cout << "El carrito esta vacio. " << endl;
      volver_menu(inventario_inicial);
    } else {
      while (temp != NULL) {
        total = total + temp->producto->calcular_pago();
        temp = temp->next;
      }
    }
    return total;
  }

  void pagar_o_cancelar(int total, Inventario *inventario_inicial,
                    Inventario *carrito){
    Node *temp = carrito->head;
    Node *aux;
    
    cout << " El total a pagar es: " << total << endl;
    cout << " ¿Desea continuar?" << endl;
    int decision;
    cout << " 1. Pagar" << endl << " 2. Cancelar pago" << endl;
    cin >> decision;
    if (decision != 1 and decision != 2) {
      cout << " Elección incorrecta. Inténtelo nuevamente " << endl;
      pagar_o_cancelar(total, inventario_inicial, carrito);
    }

    if (decision == 1) {
      cout << " Pagando ...." << endl;
    
      Node *temp = this->carrito->head;
      Node* aux;
      while (temp!=NULL) {
        aux=temp->next;
        delete temp;
        temp=aux;
      }
      this->carrito->head=NULL;
    }
    if (decision == 2) {
      cout << " Cancelando pago del carrito. El carrito será vaciado." << endl;
      this->cancelar_carrito(inventario_inicial);
      cout<<" INVENTARIO"<<endl;
      inventario_inicial->imprimir();
    }
  }
  void buscar_nodo(Inventario *inventario_inicial, Node *nodo_carrito,
                   Node *nodo_encontrado) {
    Node *temp = inventario_inicial->head;
    int id = nodo_carrito->producto->id;
    if (temp != NULL) {
      if (inventario_inicial->existe(id)) {
        while (temp) {
          if (temp->producto->id == id) {
            nodo_encontrado = temp;
            break;
          } else {
            temp = temp->next;
          }
        }
      } else {
        inventario_inicial->agregar_al_final(
            nodo_carrito->producto->nombre, nodo_carrito->producto->tipo,
            nodo_carrito->producto->cantidad, nodo_carrito->producto->precio);
      }
    } else {
      inventario_inicial->agregar_al_final(
          nodo_carrito->producto->nombre, nodo_carrito->producto->tipo,
          nodo_carrito->producto->cantidad, nodo_carrito->producto->precio);
    }
  }
  void vaciar_carrito(Inventario *inventario_inicial, Inventario *carrito) {
    Node *temp = carrito->head;
    Node *aux;
    Node *nodo_encontrado;
    while (temp) {
      buscar_nodo(inventario_inicial, temp, nodo_encontrado);
      if (nodo_encontrado != NULL) {
        nodo_encontrado->producto->cantidad += temp->producto->cantidad;
        aux = temp->next;
        delete temp;
        temp = aux;
      } else {
        aux = temp->next;
        delete temp;
        temp = aux;
      }
    }
  }

  void cancelar_carrito (Inventario *inventario_inicial) {
    Node *temp_carrito = this->carrito->head;
    Node *temp_inventario = inventario_inicial->head;
    int id_carrito;
    if (temp_carrito != NULL) {
      while (temp_carrito) {
        Node *aux;
        id_carrito = temp_carrito->producto->id;
        if (inventario_inicial->existe(id_carrito)) {
          Node *nodo_encontrado;
          while (temp_inventario) {

            if (temp_inventario->producto->id == id_carrito) {
              nodo_encontrado = temp_inventario;
              break;
            } else {
              temp_inventario = temp_inventario->next;
            }
          }
          if (nodo_encontrado->producto->id == temp_carrito->producto->id) {
            nodo_encontrado->producto->cantidad +=
                temp_carrito->producto->cantidad;
          }
          aux = temp_carrito->next;
          delete temp_carrito;
          temp_carrito = aux;
        } else {

          aux = temp_carrito->next;
          delete temp_carrito;
          temp_carrito = aux;
        }
      }

    } else {
      cout << " El carrito esta vacio" << endl;
    }
    this->carrito->head=NULL;
  }
};

class Coordinador : public Usuario {
public:
  Coordinador(string n) : Usuario(n) {}

  void mostrar_menu(Inventario *inventario_inicial) {
    Inicio in;
    string n = this->nombre;
    int decision;
    cout << " ¿Qué desea hacer, coordinador " << n << "?:" << endl;
    cout << " 1. Agregar artículo" << endl;
    cout << " 2. Modificar artículo" << endl;
    cout << " 3. Eliminar artículo" << endl;
  
    cin >> decision;
    switch (decision) {
    case 1: {
      string nombre = in.pedir_nombre();
      string tipo = in.pedir_tipo();
      int cant = in.pedir_cantidad();
      int precio = in.pedir_precio();
       if(tipo=="extranjero"){
        int impuesto= in.pedir_impuesto();
          inventario_inicial->agregar_al_final(nombre, tipo, cant, precio, impuesto);
      }
       else{
        inventario_inicial->agregar_al_final(nombre, tipo, cant, precio);
       }
      cout << endl << "INVENTARIO: " << endl;
      inventario_inicial->imprimir();
      volver_menu(inventario_inicial);
      break;
    }
    case 2: {
      inventario_inicial->modificar_articulo();
      cout << endl << "INVENTARIO: " << endl;
      inventario_inicial->imprimir();
      volver_menu(inventario_inicial);
      break;
    }

    case 3: {
      int id_eliminar = in.pedir_Id();
      inventario_inicial->eliminar(id_eliminar);
      cout << " El artículo ha sido eliminado con éxito" << endl;
      volver_menu(inventario_inicial);
      cout << endl << "INVENTARIO: " << endl;
      inventario_inicial->imprimir();
      break;
    }
    default: {
      cout << " Eleccion incorrecta, intentelo de nuevo" << endl;
      mostrar_menu(inventario_inicial);
    }
    }
  }
};