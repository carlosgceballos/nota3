#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Pets {
private:
    string filename;

public:
    Pets(const string &filename) : filename(filename) {}

    void AgregarMascota() {
        string ID, nombre, tipo, raza, cedulaOwner;
        cout << "Ingrese el ID de la mascota: ";
        cin >> ID;
        cout << "Ingrese el nombre de la mascota: ";
        cin >> nombre;
        cout << "Ingrese el tipo de la mascota (Perro, Gato, etc): ";
        cin >> tipo;
        cout << "Ingrese la raza de la mascota: ";
        cin.ignore();
        getline(cin, raza);
        cout << "Ingrese la cedula del owner: ";
        cin >> cedulaOwner;

        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << ID << "," << nombre << "," << tipo << "," << raza << "," << cedulaOwner << "\n";
            file.close();
            cout << "Mascota registrada correctamente.\n"<<"\n";
        } else {
            cerr << "Error al abrir el archivo " << filename << "\n";
        }
    }

    void leerPets() {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            cout << "ID | Nombre | Tipo | Raza | Cedula del owner |\n";
            while (getline(file, line)) {
                cout << line << "\n";
            }
            cout<<"\n";
            file.close();
        } else {
            cerr << "Error al abrir el archivo " << filename << "\n";
        }
    }

    void ActuPets() {
    string ID, newID, newName, newTipo, newRaza, newOwnerCed;
    bool exists = false;

    cout << "Ingrese el ID de la mascota a actualizar: ";
    cin >> ID;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << filename << "\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.substr(0, line.find(',')) == ID) {
            exists = true;
            break;
        }
    }
    file.close();

    if (!exists) {
        cout << "No se encontro una mascota con el ID: " << ID << ".\n";
        return;
    }

    cout<<"Status: Modificando\n";
    cout << "   Ingrese el nuevo ID de la mascota: ";
    cin >> newID;
    cout << "   Ingrese el nuevo nombre de la mascota: ";
    cin >> newName;
    cout << "   Ingrese el nuevo tipo de la mascota: ";
    cin >> newTipo;
    cout << "   Ingrese la nueva raza de la mascota: ";
    cin.ignore();
    getline(cin,newRaza);
    cout << "   Ingrese la nueva cedula del owner: ";
    cin >> newOwnerCed;

    string updatedData = newID + "," + newName + "," + newTipo + "," + newRaza + "," + newOwnerCed;

    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error al abrir el archivo " << filename << "\n";
        return;
    }

    ofstream tempFile("temp.csv");
    if (!tempFile.is_open()) {
        cerr << "Error al abrir el archivo temporal\n";
        return;
    }

    bool updated = false;

    while (getline(inputFile, line)) {
        if (line.substr(0, line.find(',')) == ID) {
            tempFile << updatedData << "\n"; 
            updated = true;
        } else {
            tempFile << line << "\n";
        }
    }

    inputFile.close();
    tempFile.close();

    remove(filename.c_str());
    rename("temp.csv", filename.c_str());

    if (updated)
        cout << "La mascota con el ID: " << ID << " fue actualizada correctamente.\n"<<"\n";
    else
        cout << "Hubo un error al actualizar la mascota.\n";
}


    void deletePet() {
        string ID;

        cout << "Ingrese el ID de la mascota a eliminar: ";
        cin >> ID;

        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error al abrir el archivo " << filename << "\n";
            return;
        }

        ofstream tempFile("temp.csv");
        if (!tempFile.is_open()) {
            cerr << "Error al abrir el archivo temporal\n";
            return;
        }

        string line;
        bool deleted = false;
        while (getline(file, line)) {
            if (line.substr(0, line.find(',')) == ID) {
                deleted = true;
            } else {
                tempFile << line << "\n";
            }
        }

        file.close();
        tempFile.close();

        remove(filename.c_str());
        rename("temp.csv", filename.c_str());

        if (deleted)
            cout << "La mascota con el ID: " << ID << " fue eliminada correctamente.\n";
        else
            cout << "No se encontro una mascota con el ID: " << ID << ".\n";
    }
};
