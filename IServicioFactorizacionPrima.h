#pragma once


#include<vector>
#include "FactorPrimo.h"

using namespace std;

class IServicioFactorizacionPrima{
	public:
		// Factoriza un número entero positivo en sus factores primos y devuelve un vector de objetos FactorPrimo que representan los factores primos y sus exponentes.
		virtual vector<FactorPrimo> factorizar(long long numero) = 0;
		
		// Devuelve la cantidad de divisores de un entero positivo
		virtual int divisores(const vector<FactorPrimo>& factores) = 0;

		virtual ~IServicioFactorizacionPrima() {}
};