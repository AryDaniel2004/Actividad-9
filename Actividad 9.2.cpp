#include <iostream>
#include <fstream>
using namespace std;

struct Estudiante {
    int id;
    string nombre;
    string apellido;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float promedio;
    bool aprobado;
};

void calcularPromedio(Estudiante* est) {
    est->promedio = (est->nota1 + est->nota2 + est->nota3 + est->nota4) / 4;
    est->aprobado = (est->promedio >= 60);
}

void escribirArchivo(Estudiante* estudiantes, int n) {
    ofstream archivo("notas.dat", ios::binary);
    archivo.write(reinterpret_cast<char*>(&n), sizeof(int));
    archivo.write(reinterpret_cast<char*>(estudiantes), n * sizeof(Estudiante));
    archivo.close();
}

void leerArchivo(Estudiante*& estudiantes, int& n) {
    ifstream archivo("notas.dat", ios::binary);
    if (!archivo) {
        cout << "No se pudo abrir el archivo notas.dat" << endl;
        return;
    }
    archivo.read(reinterpret_cast<char*>(&n), sizeof(int));
    estudiantes = new Estudiante[n];
    archivo.read(reinterpret_cast<char*>(estudiantes), n * sizeof(Estudiante));
    archivo.close();
}

int main() {
    int n = 0;
    Estudiante* estudiantes = nullptr;

    cout << "Bienvenido al programa de registro de notas." << endl;
    while (true) {
        cout << "¿Desea agregar un estudiante? (S/N): ";
        char respuesta;
        cin >> respuesta;
        if (respuesta != 'S' && respuesta != 's') {
            break;
        }

        n++;
        Estudiante* nuevosEstudiantes = new Estudiante[n];
        if (estudiantes != nullptr) {
            for (int i = 0; i < n-1; i++) {
                nuevosEstudiantes[i] = estudiantes[i];
            }
            delete[] estudiantes;
        }
        estudiantes = nuevosEstudiantes;

        Estudiante& est = estudiantes[n-1];
        cout << "Ingrese el id del estudiante: ";
        cin >> est.id;
        cout << "Ingrese el nombre del estudiante: ";
        cin >> est.nombre;
        cout << "Ingrese el apellido del estudiante: ";
        cin >> est.apellido;
        cout << "Ingrese la nota 1 del estudiante: ";
        cin >> est.nota1;
        cout << "Ingrese la nota 2 del estudiante: ";
        cin >> est.nota2;
        cout << "Ingrese la nota 3 del estudiante: ";
        cin >> est.nota3;
        cout << "Ingrese la nota 4 del estudiante: ";
        cin >> est.nota4;

        calcularPromedio(&est);
    }

    escribirArchivo(estudiantes, n);

    delete[] estudiantes;

    cout << "Datos guardados en el archivo notas.dat." << endl;

    while (true) {
        cout << "¿Desea ver los registros? (S/N): ";
        char respuesta;
        cin >> respuesta;
        if (respuesta != 'S' && respuesta != 's') {
            break;
        }

        leerArchivo(estudiantes, n);

        for (int i = 0; i < n; i++) {
            Estudiante& est = estudiantes[i];
            cout << "Estudiante " << i+1 << endl;
            cout << "Id: " << est.id << endl;
            cout << "Nombre: " << est.nombre << endl;
            cout << "Apellido: " << est.apellido << endl;
            cout << "Nota 1: " << est.nota1 << endl;
            cout << "Nota 2: " << est.nota2 << endl;
            cout << "Nota 3: " << est.nota3 << endl;
            cout << "Nota 4: " << est.nota4 << endl;
            cout << "Promedio: " << est.promedio << endl;
            cout << "Resultado: " << (est.aprobado ? "Aprobado" : "Reprobado") << endl;
        }

        delete[] estudiantes;
    }

    return 0;
}