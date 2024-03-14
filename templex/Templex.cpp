#include <iostream>
#include "Cola.h"

using namespace std;

//template <typename T>
template <class T>
T sumar(T a, T b) {
	return a + b;
}

template <class T, class U>
class A {
public:
	T a;
	T b;
	U c;
	U d;
	A(T a, T b) : a(a), b(b) {}
	T sumar() {
		return a + b;
	}


};

int main() {
	string a, b;

	cout << "Ingrese su Nombre: ";
	cin >> a;
	cout << "Ingrese su Apellido: ";
	cin >> b;

	cout << "Bienvenido" << sumar<string>(string(a) + " ", string(b)) << endl;

	cout << "La suma de datos enteros es: " << sumar<int>(79, 3) << endl;
	cout << "La suma de datos con decimales es :" << sumar<float>(245, 874.15) << endl;
	cout << "Representacion de la cola" << endl;

	Cola<string> Cola(5);
	Cola.push("Juan");
	Cola.push("Pedro");
	Cola.push("Pablo");
	Cola.push("Mateo");
	Cola.push("Marcos");

	Cola.imprimir();
	Cola.push("Judas");



	string aux = Cola.pop();

	cout << "Sale el primer integrante e ingresa uno nuevo" << endl;
	Cola.push("Judas");

	Cola.imprimir();

	//cout << sumar<string>(string("Jose "), string("Luis")) << endl;
	//cout << sumar<int>(10, 23) << endl;
	return 0;
}