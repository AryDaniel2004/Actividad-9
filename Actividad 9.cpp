#include <iostream>
using namespace std;

const int MAX_ESTUDIANTES = 100;

struct Estudiante {
    int id;
    string nombre;
    string apellido;
    double notas[4];
    double promedio;
    bool aprobado;
};

int main() {
    int n;
    Estudiante estudiantes[MAX_ESTUDIANTES];

    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    // Leer información de los estudiantes
    for (int i = 0; i < n; i++) {
        Estudiante e;
        cout << "Ingrese la información del estudiante " << i+1 << ":" << endl;
        cout << "ID: ";
        cin >> e.id;
        cout << "Nombres: ";
        cin >> e.nombre;
        cout << "Apellidos: ";
        cin >> e.apellido;
        cout << "Notas (separadas por espacio): ";
        for (int j = 0; j < 4; j++) {
            cin >> e.notas[j];
            e.promedio += e.notas[j];
        }
        e.promedio /= 4;
        e.aprobado = (e.promedio >= 60);
        estudiantes[i] = e;
    }

    // Imprimir información de los estudiantes
    cout << "Información de los estudiantes:" << endl;
    for (int i = 0; i < n; i++) {
        Estudiante e = estudiantes[i];
        cout << "ID: " << e.id << endl;
        cout << "Nombres: " << e.nombre << endl;
        cout << "Apellidos: " << e.apellido << endl;
        cout << "Notas: ";
        for (int j = 0; j < 4; j++) {
            cout << e.notas[j] << " ";
        }
        cout << endl;
        cout << "Promedio: " << e.promedio << endl;
        if (e.aprobado) {
            cout << "Estado: Aprobado" << endl;
        } else {
            cout << "Estado: Reprobado" << endl;
        }
        cout << endl;
    }

    return 0;
}