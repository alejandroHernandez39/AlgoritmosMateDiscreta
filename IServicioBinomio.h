#pragma once

#ifndef ISERVICIOBINOMIO_H
#define ISERVICIOBINOMIO_H


#include <vector>
#include "TerminoBinomio.h"

using namespace std;

class IServicioBinomio {
	public:
		// Calcula el coeficiente binomial C(n, k) = n! / (k! * (n - k)!)
		virtual vector <TerminoBinomio> expandirBinomio(const TerminoBinomio& termino1, const TerminoBinomio& termino2, int exponenteBinomio) = 0;

		// Encuentra un terminio n del binomio expandido dado un índice
		virtual TerminoBinomio encontrarTermino(int indice, const vector<TerminoBinomio>& terminos) = 0;

		// Encuentra el coeficiente de un termino especifico en el binomio expandido dado un índice
		virtual long long encontrarCoeficiente(int indice, const vector<TerminoBinomio>& terminos) = 0;

		virtual ~IServicioBinomio() = default;
};

#endif