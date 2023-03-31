#include <iostream>
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

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    Estudiante* estudiantes = new Estudiante[n];

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el id del estudiante " << i+1 << ": ";
        cin >> estudiantes[i].id;
        cout << "Ingrese el nombre del estudiante " << i+1 << ": ";
        cin >> estudiantes[i].nombre;
        cout << "Ingrese el apellido del estudiante " << i+1 << ": ";
        cin >> estudiantes[i].apellido;
        cout << "Ingrese la nota 1 del estudiante " << i+1 << ": ";
        cin >> estudiantes[i].nota1;
        cout << "Ingrese la nota 2 del estudiante " << i+1 << ": ";
        cin >> estudiantes[i].nota2;
        cout << "Ingrese la nota 3 del estudiante " << i+1 << ": ";
        cin >> estudiantes[i].nota3;
        cout << "Ingrese la nota 4 del estudiante " << i+1 << ": ";
        cin >> estudiantes[i].nota4;

        calcularPromedio(&estudiantes[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << "Estudiante " << i+1 << endl;
        cout << "Id: " << estudiantes[i].id << endl;
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Apellido: " << estudiantes[i].apellido << endl;
        cout << "Nota 1: " << estudiantes[i].nota1 << endl;
        cout << "Nota 2: " << estudiantes[i].nota2 << endl;
        cout << "Nota 3: " << estudiantes[i].nota3 << endl;
        cout << "Nota 4: " << estudiantes[i].nota4 << endl;
        cout << "Promedio: " << estudiantes[i].promedio << endl;
        cout << "Estado: " << (estudiantes[i].aprobado ? "Aprobado" : "Reprobado") << endl;
        cout << endl;
    }

    delete[] estudiantes;
    return 0;
}