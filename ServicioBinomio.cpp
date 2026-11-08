#include "ServicioBinomio.h"
#include <stdexcept>

using namespace std;

long long ServicioBinomio::calcularCoeficiente(int n, int k) {
	if (k < 0 || k > n) {
		throw invalid_argument("El valor de k debe estar entre 0 y n.");
	}
	long long coeficiente = 1;
	for (int i = 0; i < k; ++i) {
		coeficiente *= (n - i);
		coeficiente /= (i + 1);
	}
	return coeficiente;
}

long long ServicioBinomio::calcularPotencia(long long base, int exponente) {
	if (exponente < 0) {
		throw invalid_argument("El exponente no puede ser negativo.");
	}
	long long resultado = 1;
	for (int i = 0; i < exponente; ++i) {
		resultado *= base;
	}
	return resultado;
}

vector<TerminoBinomio> ServicioBinomio::expandirBinomio(const TerminoBinomio& termino1, const TerminoBinomio& termino2, int exponente) {
    if (exponente < 0 || exponente > 10) {
        throw invalid_argument(
            "El exponente debe estar entre 0 y 10."
        );
    }

    if (termino1.getCoeficiente() < -10 || termino1.getCoeficiente() > 10 || termino2.getCoeficiente() < -10 || termino2.getCoeficiente() > 10) {
        throw invalid_argument(
            "La constante debe estar entre -10 y 10."
        );
    }

    std::vector<TerminoBinomio> terminos;

    for (int k = 0; k <= exponente; k++) {

        long long coeficiente =
            calcularCoeficiente(exponente, k);

        long long potencia =
            calcularPotencia(termino2.getCoeficiente(), k);

        coeficiente *= potencia;

        int expX = exponente - k;
        int expY = k;

        TerminoBinomio termino(
            coeficiente,
            expX,
            expY
        );

        terminos.push_back(termino);
    }

    return terminos;
}

TerminoBinomio ServicioBinomio::encontrarTermino(int indice, const vector<TerminoBinomio>& terminos) {
    if (indice < 0 || indice >= terminos.size()) {
        throw invalid_argument("El índice está fuera de los límites del vector de términos.");
    }
    return terminos[indice-1];
}

long long ServicioBinomio::encontrarCoeficiente(int indice, const vector<TerminoBinomio>& terminos) {
	if (indice < 0 || indice >= terminos.size()) {
		throw invalid_argument("El índice está fuera de los límites del vector de términos.");
	}
	return terminos[indice-1].getCoeficiente();
}