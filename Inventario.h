#include "Nodo.h"
#include <iostream>
using namespace std;

// clase Inventario
class Inventario {
public:
  Node *head;
  int size;

  // Método Agregar_al_inicio
  
  // Método Agregar_al_final
  void agregar_al_final(string n, string tipo, int c, int p) {
    Node *nuevo_nodo = new Node(n, tipo, c, p);
    if (head == NULL) {
      head = nuevo_nodo;
    } else {
      if (head->next == NULL) {
        head->next = nuevo_nodo;
      } else {
        Node *current = head;
        while (current) {
          if (current->next == NULL) {
            current->next = nuevo_nodo;
            break;
          }
          current = current->next;
        }
      }
    }
  }
void agregar_al_final(string n, string tipo, int c, int p, int impuesto) {
    Node *nuevo_nodo = new Node(n, tipo, c, p, impuesto);
    if (head == NULL) {
      head = nuevo_nodo;
    } else {
      if (head->next == NULL) {
        head->next = nuevo_nodo;
      } else {
        Node *current = head;
        while (current) {
          if (current->next == NULL) {
            current->next = nuevo_nodo;
            break;
          }
          current = current->next;
        }
      }
    }
  }
  void agregar_nodo(Node *nuevo_nodo) {
    if (head == NULL) {
      head = nuevo_nodo;
    } else {
      if (head->next == NULL) {
        head->next = nuevo_nodo;
      } else {
        Node *current = head;
        while (current) {
          if (current->next == NULL) {
            current->next = nuevo_nodo;
            break;
          }
          current = current->next;
        }
      }
    }
  }

  // Imprimir la lista
  void imprimir() {
    // cout<<endl<<"Lista "<<endl;
    Node *current = head;
    cout << " DEPORTIVOS:" << endl;
    while (current!=NULL) {
      if (current->producto->tipo == "deportivo") {
        cout << "Nombre: " << current->producto->nombre
             << " - Cantidad: " << current->producto->cantidad
             << " - Precio: " << current->producto->precio;
        cout << " - ID: " << current->producto->id;
        if (current->producto->disponibilidad == true) {
          cout << " - Disponible" << endl << endl;
        } else {
          cout << " - NO Disponible" << endl << endl;
        }
      }
      current = current->next;
    }
    Node *current2 = head;
    cout << " TECNOLOGICOS:" << endl;
    while (current2!=NULL) {
      if (current2->producto->tipo == "tecnologico") {
        cout << "Nombre: " << current2->producto->nombre
             << " - Cantidad: " << current2->producto->cantidad
             << " - Precio: " << current2->producto->precio;
        cout << " - ID: " << current2->producto->id;
        if (current2->producto->disponibilidad == true) {
          cout << " - Disponible" << endl << endl;
        } else {
          cout << " - NO Disponible" << endl << endl;
        }
      }
      current2 = current2->next;
    }
    Node *current3 = head;
    cout << " EXTRANJEROS:" << endl;
    while (current3!=NULL) {
      if (current3->producto->tipo == "extranjero") {
        cout << "Nombre: " << current3->producto->nombre
             << " - Cantidad: " << current3->producto->cantidad
             << " - Precio: " << current3->producto->precio;
        cout << " - ID: " << current3->producto->id<<endl;
              
        if (current3->producto->disponibilidad == true) {
          cout << " - Disponible" << endl << endl;
        } else {
          cout << " - NO Disponible" << endl << endl;
        }
      }
      current3 = current3->next;
    }
    cout << endl
         << endl
         << endl
         << "||||||||||||||||||||||||||||||||||||||||||||||||||||||"
            "||||"
         << endl;
    
  }

  // metodo para eliminar
  void eliminar(int id) {

    if (head != NULL) {
      if (head->next == NULL) {
        if (head->producto->id == id) {
          head = NULL;
        }
      } else {
        Node *temporal = head;
        if (temporal->producto->id == id) {
          head = temporal->next;
        } else {
          while (temporal) {
            if (temporal->next->producto->id == id) {
              Node *nodo_eliminar = temporal->next;
              temporal->next = nodo_eliminar->next;
              delete nodo_eliminar;
              break;
            }

            temporal = temporal->next;
          }
        }
      }
    }
  }

  // metodo existe
  Node *buscar_nodo(int id) {
    if (existe(id) == true) {
      Node *nodo;
      Node *temp = this->head;
      while (temp) {
        if (temp->producto->id == id) {
          nodo = temp;
        } else {
          temp = temp->next;
        }
      }
    }
  }
  bool existe(int id) {
    bool existe = false;
    if (head != NULL) {
      if (head->next == NULL) {
        if (head->producto->id == id) {
          existe = true;
        } else {
          existe = false;
        }

      } else {
        Node *temp = head;
        while (temp) {
          if (temp->producto->id == id) {
            existe = true;
            break;
          } else {
            existe = false;
          }
          temp = temp->next;
        }
      }
    } else {
      cout << " No hay ningun elemento" << endl;
    }
    return existe;
  }

  // metodo modificar
  void modificar_articulo() {
    int id;
    cout << " Ingrese el Id del producto que quiere modificar" << endl;
    cin >> id;
    Node *temp = head;
    if (existe(id) == true) {
      Node *nuevo;
      while (temp) {
        if (temp->producto->id == id) {
          nuevo = temp;
          break;
        } else {
          temp = temp->next;
        }
      }
      cambiar(nuevo);
    } else {
      cout << " El Id de producto que ingreso no existe. Por favor verifíquelo "
              "e ingréselo nuevamente.";
      modificar_articulo();
    }
  }

  void cambiar(Node *nuevo) {

    cout << " ¿Que desea modificar?" << endl
         << " 1. Nombre" << endl
         << " 2. Cantidad" << endl
         << " 3. Precio" << endl;
    int eleccion;
    cin >> eleccion;
    switch (eleccion) {
    case 1:
      cout << "Ingrese el nuevo nombre del producto" << endl;
      cin >> nuevo->producto->nombre;
      break;
    case 2:
      cout << "Ingrese la nueva cantidad del producto" << endl;
      int cantidad;
      cin >> cantidad;
      nuevo->producto->cantidad = cantidad;
      if (cantidad > 0) {
        nuevo->producto->disponibilidad = true;
      } else {
        nuevo->producto->disponibilidad = false;
      }
      break;
    case 3:
      cout << "Ingrese el nuevo precio del producto" << endl;
      cin >> nuevo->producto->precio;
    }
    cout << " ¿Desea modificar de nuevo el producto? " << endl
         << " 1. Sí" << endl
         << " 2. No" << endl;
    int caso;
    cin >> caso;
    switch (caso) {
    case 1:
      cambiar(nuevo);
      break;
    case 2:
      cout << " Modificacion realizada con exito" << endl;
    }
  }
};