#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Owners {
private:
    string filename;

public:
    Owners(const string &filename) : filename(filename) {}

    void crearOwner() {
        string cedula, nombre, apellido, address, tlf;

        cout << "Ingrese la cedula del owner: ";
        cin >> cedula;
        cout << "Ingrese el nombre del owner: ";
        cin >> nombre;
        cout<<"Ingrese el apellido del owner: ";
        cin>>apellido;
        cout << "Ingrese la direccion del owner: ";
        cin.ignore(); 
        getline(cin, address);
        cout << "Ingrese el telefono del owner: ";
        cin >> tlf;

        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << cedula << "," << nombre << ","<<apellido<<","<< address << "," << tlf << "\n";
            file.close();
            cout << "Owner registrado correctamente.\n"<<"\n";
        } else {
            cerr << "Error al abrir el archivo " << filename << "\n";
        }
    }

    void LeerOwn() {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            cout << "Cedula: | Nombre: | Apellido: | Direccion: |Telefono: |\n";
            while (getline(file, line)) {
                cout << line << "\n";
            }
            file.close();
        } else {
            cerr << "Error al abrir el archivo " << filename << "\n";
        }
    }

void ActOwn() {
    string cedula, newCed, newNombre, newApell, newAddress, newPhone;
    bool exists = false;

    cout << "Ingrese la cedula del owner a actualizar: ";
    cin >> cedula;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << filename << "\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.substr(0, line.find(',')) == cedula) {
            exists = true;
            break;
        }
    }
    file.close();

    if (!exists) {
        cout << "No se encontro un owner con la cedula: " << cedula << ".\n"<<"\n";
        return;
    }

    cout<<"Status: Modificando\n";
    cout << "   Ingrese la cedula del owner: ";
    cin >> newCed;
    cout << "   Ingrese el nombre del owner: ";
    cin>>newNombre;
    cout << "     Ingrese el apellido del owner: ";
    cin>>newApell;
    cout << "   Ingrese la direccion del owner: ";
    cin.ignore();
    getline(cin, newAddress);
    cout << "   Ingrese el telefono del owner: ";
    cin >> newPhone;

    string updatedData = newCed + "," + newNombre + "," + newApell + "," + newAddress + "," + newPhone;

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
        if (line.substr(0, line.find(',')) == cedula) {
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
        cout << "El owner con la cedula: " << cedula << " fue actualizado correctamente.\n"<<"\n";
    else
        cout << "Hubo un error al actualizar el dueño.\n"<<"\n";
}


    void deleteOwner() {
        string Ced;

        cout << "Ingrese la cedula del owner a eliminar: ";
        cin >> Ced;

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
            if (line.substr(0, line.find(',')) == Ced) {
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
            cout << "El owner con la cedula: " << Ced << " fue eliminado correctamente.\n"<<"\n";
        else
            cout << "No se encontro un owner con la cedula: " << Ced << ".\n"<<"\n";
    }
};
