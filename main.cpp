#include "Sistema.h"
#include <iostream>
using namespace std;

int main() {

  Sistema run;
  Inventario *inventario_inicial = new Inventario();
  inventario_inicial->agregar_al_final("termo", "deportivo",10,10000);
  inventario_inicial->agregar_al_final("celular", "tecnologico",10,10000);
  inventario_inicial->agregar_al_final("pc", "tecnologico",80,10000);
  inventario_inicial->agregar_al_final("carro", "extranjero",80,10000,10);
  
  inventario_inicial->imprimir();
  
  run.iniciar(inventario_inicial);
  Usuario* coordinador= new Coordinador(" cordinador");
  Usuario* cliente= new Cliente("cliente");
  
  
  cliente->mostrar_menu(inventario_inicial);
  return 0;
}

/* Checklist:
  agregar_al_inicio OK
  imprimir OK
  agregar_al_final OK
  eliminar OK
  existe OK
  modificar OK

  Carrito de compras NO
  Usuarios NO


*/