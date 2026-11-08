#include "Menu.h"
#include "TerminoBinomio.h"
#include "ServicioBinomio.h"
#include "FactorPrimo.h"
#include "ServicioFactorizacionPrima.h"
#include "ServicioEuclides.h"
#include "ResultadoEuclides.h"

#include <iostream>
#include <cstdlib>
#include <limits>
#include <vector>
#include <exception>
#include <cmath>

using namespace std;


// Funciones para mostrar resultados
void mostrarExpansionBinomio(const vector<TerminoBinomio>& terminos) {
	cout << "Resultado de la expansion del binomio:\n";
	bool primerTermino = true;

	for (const auto& termino : terminos) {

		long long coef = termino.getCoeficiente();
		int exponente = termino.getExponenteX();

		if (coef == 0) {
			continue;
		}

		if (!primerTermino) {
			cout << (coef > 0 ? " + " : " - ");
		}
		else if (coef < 0) {
			cout << "-";
		}

		long long valorAbsoluto = llabs(coef);

		if (exponente == 0 || valorAbsoluto != 1) {
			cout << valorAbsoluto;
		}

		if (exponente > 0) {

			cout << "x";

			if (exponente > 1) {
				cout << "^" << exponente;
			}
		}

		primerTermino = false;
	}

	if (primerTermino) {
		cout << "0";
	}

	cout << "\n";
}
void mostrarTermino(const TerminoBinomio& termino) {
	cout << "Termino encontrado:\n";
	cout << termino.getCoeficiente() << "x" << "^" << termino.getExponenteX() << "\n";
}
void mostrarCoeficiente(long long coeficiente) {
	cout << "Coeficiente encontrado: " << coeficiente << "\n";
}

void mostrarFactorizacion(const vector<FactorPrimo>& factores) {
	cout << "Resultado de la factorizacion prima:\n";
	for (const auto& factor : factores) {
		cout << factor.getFactor() << "^" << factor.getExponente() << " ";
	}
	cout << "\n";
}
void mostrarDivisores(int cantidadDivisores) {
	cout << "Cantidad de divisores: " << cantidadDivisores << "\n";
}

void mostrarResultadoEuclides(const	ResultadoEuclides& resultado) {
	cout << "MCD: " << resultado.getMCD() << "\n";
	cout << "MCM: " << resultado.getMCM() << "\n";
}

// Constructor
Menu::Menu() {
	opcion = 0;
}

// Submenus del Binomio de Newton
void Menu::mostrarSubmenuBinomio() {
	cout << "\n";
	cout << "========================================\n";
	cout << "       EXPANSION DEL BINOMIO DE NEWTON  \n";
	cout << "========================================\n";
	cout << "  1. Expandir binomio\n";
	cout << "  2. Encontrar termino n del binomio expandido\n";
	cout << "  3. Encontrar coeficiente de un termino especifico\n";
	cout << "  4. Regresar al menu principal\n";
	cout << "========================================\n";
}

// Submenu del Teorema Fundamental de la Aritmetica
void Menu::mostrarSubmenuTeorema() {
	cout << "\n";
	cout << "========================================\n";
	cout << "   TEOREMA FUNDAMENTAL DE LA ARITMETICA \n";
	cout << "========================================\n";
	cout << "  1. Factorizar un numero entero positivo\n";
	cout << "  2. Calcular la cantidad de divisores de un numero entero positivo\n";
	cout << "  3. Regresar al menu principal\n";
	cout << "========================================\n";
}

// Submenu del Algoritmo de Euclides
void Menu::mostrarSubmenuEuclides() {
	cout << "\n";
	cout << "========================================\n";
	cout << "          ALGORITMO DE EUCLIDES         \n";
	cout << "========================================\n";
	cout << "  1. Calcular MCD y MCM de dos numeros\n";
	cout << "  2. Calcular MCD y MCM de varios numeros\n";
	cout << "  3. Regresar al menu principal\n";
	cout << "========================================\n";
}

// Mostrar el menú principal
void Menu::mostrarMenu() {
    cout << "\n";
    cout << "========================================\n";
    cout << "    PROYECTO FINAL MATEMATICA DISCRETA  \n";
    cout << "========================================\n";

    cout << "  1. Expansion del Binomio de Newton\n";
    cout << "  2. Teorema Fundamental de la Aritmetica\n";
    cout << "  3. Algoritmo de Euclides\n";
    cout << "  4. Salir\n";

    cout << "========================================\n";
}

// Seleccionar una opción del menú
int Menu :: seleccionarOpcion() {
	cout << "Ingrese una opcion: ";
	cin >> opcion;
	return opcion;
}

// Ejecutar menu
void Menu::ejecutar() {
	do {
		mostrarMenu();
		seleccionarOpcion();
		switch (opcion) {
		case 1: {
			mostrarSubmenuBinomio();
			seleccionarOpcion();
			switch (opcion) {
			case 1: {
				cout << "\n";
				cout << "========================================\n";
				cout << "       EXPANSION DEL BINOMIO DE NEWTON  \n";
				cout << "========================================\n";
				TerminoBinomio termino1(0, 0, 0);
				TerminoBinomio termino2(0, 0, 0);


				cout << "Ingrese el coeficiente del primer termino: ";
				long long coeficiente;
				cin >> coeficiente;
				termino1.setCoeficiente(coeficiente);

				cout << "Ingrese el exponente x del primer termino: ";
				int exponenteX1;
				cin >> exponenteX1;
				termino1.setExponenteX(exponenteX1);

				cout << "Ingrese el exponente y del primer termino: ";
				int exponenteY1;
				cin >> exponenteY1;
				termino1.setExponenteY(exponenteY1);

				cout << "Ingrese el coeficiente del segundo termino: ";
				long long coeficiente2;
				cin >> coeficiente2;
				termino2.setCoeficiente(coeficiente2);

				cout << "Ingrese el exponente x del segundo termino: ";
				int exponenteX2;
				cin >> exponenteX2;
				termino2.setExponenteX(exponenteX2);

				cout << "Ingrese el exponente y del segundo termino: ";
				int exponenteY2;
				cin >> exponenteY2;
				termino2.setExponenteY(exponenteY2);

				cout << "Ingrese el exponente del binomio: ";
				int exponenteBinomio;
				cin >> exponenteBinomio;

				ServicioBinomio servicio;
				vector<TerminoBinomio> terminos = servicio.expandirBinomio(termino1, termino2, exponenteBinomio);
				mostrarExpansionBinomio(terminos);
				break;
			} 
			case 2: {
				cout << "\n";
				cout << "========================================\n";
				cout << "       ENCONTRAR TERMINO DEL BINOMIO    \n";
				cout << "========================================\n";
				TerminoBinomio termino1(0, 0, 0);
				TerminoBinomio termino2(0, 0, 0);

				cout << "Ingrese el coeficiente del primer termino: ";
				long long coeficiente;
				cin >> coeficiente;
				termino1.setCoeficiente(coeficiente);

				cout << "Ingrese el exponente x del primer termino: ";
				int exponenteX1;
				cin >> exponenteX1;
				termino1.setExponenteX(exponenteX1);

				cout << "Ingrese el exponente y del primer termino: ";
				int exponenteY1;
				cin >> exponenteY1;
				termino1.setExponenteY(exponenteY1);

				cout << "Ingrese el coeficiente del segundo termino: ";
				long long coeficiente2;
				cin >> coeficiente2;
				termino2.setCoeficiente(coeficiente2);

				cout << "Ingrese el exponente x del segundo termino: ";
				int exponenteX2;
				cin >> exponenteX2;
				termino2.setExponenteX(exponenteX2);

				cout << "Ingrese el exponente y del segundo termino: ";
				int exponenteY2;
				cin >> exponenteY2;
				termino2.setExponenteY(exponenteY2);

				cout << "Ingrese el exponente del binomio: ";
				int exponenteBinomio;
				cin >> exponenteBinomio;

				int indice;
				cout << "Ingrese el indice del termino (0 a n): ";
				cin >> indice;


				ServicioBinomio servicio;
				vector<TerminoBinomio> terminos = servicio.expandirBinomio(termino1, termino2, exponenteBinomio);
				try {
					TerminoBinomio termino = servicio.encontrarTermino(indice, terminos);
					mostrarTermino(termino);
				}
				catch (const out_of_range& e) {
					cout << "Error: " << e.what() << "\n";
				}
				break;
			}
			case 3: {
				cout << "\n";
				cout << "========================================\n";
				cout << "       ENCONTRAR COEFICIENTE DEL TERMINO\n";
				cout << "========================================\n";
				TerminoBinomio termino1(0, 0, 0);
				TerminoBinomio termino2(0, 0, 0);

				cout << "Ingrese el coeficiente del primer termino: ";
				long long coeficiente;
				cin >> coeficiente;
				termino1.setCoeficiente(coeficiente);

				cout << "Ingrese el exponente x del primer termino: ";
				int exponenteX1;
				cin >> exponenteX1;
				termino1.setExponenteX(exponenteX1);

				cout << "Ingrese el exponente y del primer termino: ";
				int exponenteY1;
				cin >> exponenteY1;
				termino1.setExponenteY(exponenteY1);

				cout << "Ingrese el coeficiente del segundo termino: ";
				long long coeficiente2;
				cin >> coeficiente2;
				termino2.setCoeficiente(coeficiente2);

				cout << "Ingrese el exponente x del segundo termino: ";
				int exponenteX2;
				cin >> exponenteX2;
				termino2.setExponenteX(exponenteX2);

				cout << "Ingrese el exponente y del segundo termino: ";
				int exponenteY2;
				cin >> exponenteY2;
				termino2.setExponenteY(exponenteY2);

				cout << "Ingrese el exponente del binomio: ";
				int exponenteBinomio;
				cin >> exponenteBinomio;

				int indice;
				cout << "Ingrese el indice del termino (0 a n): ";
				cin >> indice;

				ServicioBinomio servicio;
				vector<TerminoBinomio> terminos = servicio.expandirBinomio(termino1, termino2, exponenteBinomio);
				try {
					long long coeficiente = servicio.encontrarCoeficiente(indice, terminos);
					mostrarCoeficiente(coeficiente);
				}
				catch (const out_of_range& e) {
					cout << "Error: " << e.what() << "\n";
				}
				break;
			}
			case  4:
				cout << "Regresando al menu principal...\n";
				break;
			}
			break;
		}
		case 2: {
			mostrarSubmenuTeorema();
			seleccionarOpcion();
			switch (opcion) {
				case 1: {
					cout << "\n";
					cout << "========================================\n";
					cout << "   FACTORIZACION DE UN NUMERO ENTERO    \n";
					cout << "========================================\n";
					long long numero;
					cout << "Ingrese un numero entero positivo: ";
					cin >> numero;
					if (numero <= 0) {
						cout << "Error: El numero debe ser positivo.\n";
						break;
					}
					ServicioFactorizacionPrima servicio;
					vector<FactorPrimo> factores = servicio.factorizar(numero);
					mostrarFactorizacion(factores);
					break;
				}
				case 2: {
					cout << "\n";
					cout << "========================================\n";
					cout << "   CANTIDAD DE DIVISORES DE UN NUMERO   \n";
					cout << "========================================\n";
					long long numero;
					cout << "Ingrese un numero entero positivo: ";
					cin >> numero;
					if (numero <= 0) {
						cout << "Error: El numero debe ser positivo.\n";
						break;
					}
					ServicioFactorizacionPrima servicio;
					vector<FactorPrimo> factores = servicio.factorizar(numero);
					int cantidadDivisores = servicio.divisores(factores);
					mostrarDivisores(cantidadDivisores);
					break;
				}
				case 3:
					cout << "Regresando al menu principal...\n";
					break;
				default:
					cout << "Opcion invalida. Por favor, intente nuevamente.\n";
			}
			break;
		}
		case 3: {
			mostrarSubmenuEuclides();
			seleccionarOpcion();
			switch (opcion) {
				case 1: {
					cout << "\n";
					cout << "========================================\n";
					cout << "     CALCULAR MCM Y MCD DE DOS NUMEROS  \n";
					cout << "========================================\n";
					long long n1;
					long long n2;
					cout << "Ingrese el primer numero: ";
					cin >> n1;
					cout << "Ingrese el segundo numero: ";
					cin >> n2;

					ServicioEuclides servicio;
					ResultadoEuclides resultado = servicio.calcular(n1, n2);

					mostrarResultadoEuclides(resultado);
					break;
				}
				case 2: {
					cout << "\n";
					cout << "========================================\n";
					cout << "     CALCULAR MCM Y MCD DE VARIOS NUMEROS\n";
					cout << "========================================\n";
					int cantidad;
					cout << "Ingrese la cantidad de numeros: ";
					cin >> cantidad;
					if (cantidad <= 0) {
						cout << "Error: La cantidad de numeros debe ser mayor que cero.\n";
						break;
					}

					vector<long long> numeros(cantidad);

					for (int i = 0; i < cantidad; ++i) {
						cout << "Ingrese el numero " << (i + 1) << ": ";
						cin >> numeros[i];
					}

					ServicioEuclides servicio;
					try {
						ResultadoEuclides resultado = servicio.calcular(cantidad, numeros);
						mostrarResultadoEuclides(resultado);
					}
					catch (const std::invalid_argument& e) {
						cout << "Error: " << e.what() << "\n";
					}
				}

			}
			break;
		}
		case 4:
			cout << "Saliendo del programa...\n";
			break;
		default:
			cout << "Opcion invalida. Por favor, intente nuevamente.\n";
		}

		if (opcion != 4) {
			cout << "Presione Enter para continuar...";
			cin.ignore();
			cin.get();
		}
	} while (opcion != 4);
}
