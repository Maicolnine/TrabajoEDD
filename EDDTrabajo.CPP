#include <iostream>
using namespace std;

// Estructura del nodo
struct nodo {
    int id;
    char productos[20];         // Valor que almacena el nodo
    struct nodo *sig;  // Puntero al siguiente nodo
};

// Punteros globales para manipular la lista
struct nodo *cab = NULL, *aux = NULL, *aux2 = NULL;
    int contadorID = 1;
// Función para agregar un nuevo nodo al final de la lista

void addProducto() {
    // Se reserva memoria para un nuevo nodo
    aux = (struct nodo *) malloc(sizeof(struct nodo));

    // Se verifica si la memoria fue asignada correctamente
    if (aux == NULL) {
        cout << "Error: no se pudo asignar memoria." << endl;
        return;
    }

    // Solicita al usuario el valor a guardar
    cout << "Registre el Producto ";
    cin >> aux->productos;

    aux->id = contadorID++;
    // El nuevo nodo apunta a NULL (fin de lista)
    aux->sig = NULL;
    
    // Si la lista está vacía, el nuevo nodo será la cabeza
    if (cab == NULL) {
        cab = aux;
    } else {
        // Se recorre la lista hasta el último nodo
        aux2 = cab;
        while (aux2->sig != NULL) {
            aux2 = aux2->sig;
        }
        // Se enlaza el nuevo nodo al final
        aux2->sig = aux;
    }
    aux =  aux2 = NULL; // Se limpian los punteros auxiliares
    free(aux);          // Se libera la memoria de aux
    free(aux2);         // Se libera la memoria de aux2
}

// Función para mostrar todos los nodos de la lista
void viewProducto() {
    // Recorre desde la cabeza hasta NULL
    for (aux = cab; aux != NULL; aux = aux->sig) {
        cout << "El producto es: " << aux->productos << " ID: " << aux->id << endl;
    }
}

// Función para buscar un valor en la lista
int searchProducto() {
    char seed[20];
    cout << "Digite el ID a buscar: ";
    cin >> seed;

    // Recorre la lista comparando el valor
    for (aux = cab; aux != NULL; aux = aux->sig) {
        if (aux->productos == seed) {
            aux =  NULL; // Se limpian los punteros auxiliares
            free(aux);          // Se libera la memoria de aux
            return 1;  // Valor encontrado
        }
    }
    aux =  NULL; // Se limpian los punteros auxiliares
    free(aux);          // Se libera la memoria de aux
    return 0; // Valor no encontrado
}

//funcion de eliminar un producto por su ID
void eliminarProducto(){
    if(cab==NULL){
        cout<<"la lista esta vacia. No hay productos para eliminar";
}

int eliminarID;

cout << "ingrese el ID del prodcuto a eliminar";
cin >> eliminarID;
aux = cab;
aux2 = NULL;

//buscando el prodcuto a eliminar
while(aux != NULL){
    if(aux -> id == eliminarID){
        break;
    }
aux2 = aux;
aux = aux -> sig;
}
if(aux == NULL){
    cout <<"No se encontro un prodcuto con ID"<<eliminarID<<endl;
return;
}

if(aux == cab){
    cab = cab -> sig;
}else {
    aux2 -> sig = aux -> sig;
}

free(aux);//libera la memoria del producto eliminado
cout<<"Producto con ID, "<< eliminarID << "eliminado correctamente.\n";
}

// Función para liberar toda la memoria ocupada por la lista
void liberarMemoria() {
    aux = cab;
    // Recorre la lista y libera nodo por nodo
    while (aux != NULL) {
        aux2 = aux->sig; // Guarda el siguiente nodo
        free(aux);       // Libera el nodo actual
        aux = aux2;      // Avanza al siguiente
    }
    cab = NULL; // Después de liberar, cabeza queda en NULL
    cout << "Memoria liberada correctamente." << endl;
}


// Función principal con menú de opciones
int main() {
    int band, opc;

    do {
        // Muestra menú al usuario
        cout << "\n==== MENÚ ====\n";
        cout << "1. Registrar un producto\n";
        cout << "2. Mostrar\n";
        cout << "3. Buscar nodo\n";
        cout << "4 eliminar producto\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opc;

        switch(opc) {
            case 1:
                addProducto();
                break;
            case 2:
                viewProducto();
                break;
            case 3:
                band = searchProducto();
                if (band)
                    cout << "Nodo encontrado.\n";
                else
                    cout << "No encontrado.\n";
                break;
                case 4: 
                eliminarProducto();
                break;
        }

    } while(opc != 6);

    // Al salir del programa, se libera la memoria
    liberarMemoria();

    return 0;
}