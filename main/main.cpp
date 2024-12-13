#include <iostream>
#include <string>
#include "../modulos/owners.cpp"
#include "../modulos/pets.cpp"

using namespace std;

int main() {
  Pets pets("csv/pets.csv");
  Owners owners("csv/owners.csv");
  int option;

  do {
    cout << "1. Gestion de Mascotas\n";
    cout << "2. Gestion de owners\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> option;
    cout<<"\n";

      if (option == 1) {
        int petOption;
          do {
            cout << "1. Agregar nueva mascota\n";
            cout << "2. Ver todas las mascotas\n";
            cout << "3. Actualizar datos de una mascota\n";
            cout << "4. Eliminar una mascota\n";
            cout << "0. Volver\n";
            cout << "Seleccione una opcion: ";
            cin >> petOption;
            cout<<"\n";

            switch (petOption) {
              case 1: 
              pets.AgregarMascota(); 
              break;

              case 2: 
              pets.leerPets(); 
              break;

              case 3: 
              pets.ActuPets(); 
              break;

              case 4: 
              pets.deletePet(); 
              break;

              case 0: 
              cout<<"Saliendo\n";
              cout<<"\n";
              break;

              default: 
              cout << "Opcion invalida.\n";
                }
            } while (petOption != 0);

        } else if (option == 2) {
            int ownerOption;
            do {
                cout << "1. Agregar nuevo owners\n";
                cout << "2. Ver todos los owners\n";
                cout << "3. Actualizar datos de un owners\n";
                cout << "4. Eliminar un owners\n";
                cout << "0. Volver\n";
                cout << "Seleccione una opcion: ";
                cin >> ownerOption;
                cout<<"\n";

                switch (ownerOption) {
                    case 1: 
                    owners.crearOwner();
                    break;

                    case 2: 
                    owners.LeerOwn(); 
                    break;

                    case 3: 
                    owners.ActOwn(); 
                    break;

                    case 4: 
                    owners.deleteOwner(); 
                    break;

                    case 0: 
                    cout<<"Saliendo\n";
                    cout<<"\n";
                    break;

                    default: 
                    cout << "Opción inválida. Intente de nuevo.\n";
                }
            } while (ownerOption != 0);
        } else if (option != 3) {
            cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (option != 3);

    cout << "Saliendo del programa...\n";
    return 0;
}
