#include "TerminoBinomio.h"

TerminoBinomio::TerminoBinomio(long long coef, int expX, int expY) {
	coeficiente = coef;
	exponenteX = expX;
	exponenteY = expY;
}

long long TerminoBinomio::getCoeficiente() const {
	return coeficiente;
}

int TerminoBinomio::getExponenteX() const {
	return exponenteX;
}

int TerminoBinomio::getExponenteY() const {
	return exponenteY;
}

long long TerminoBinomio::setCoeficiente(long long coef) {
	coeficiente = coef;
	return coeficiente;
}

int TerminoBinomio::setExponenteX(int expX) {
	exponenteX = expX;
	return exponenteX;
}

int TerminoBinomio::setExponenteY(int expY) {
	exponenteY = expY;
	return exponenteY;
}