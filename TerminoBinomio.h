#pragma once

#ifndef TERMINOBINOMIO_H
#define TERMINOBINOMIO_H

#include <iostream>

class TerminoBinomio {
	private:
		long long coeficiente;
		int exponenteX;
		int exponenteY;

	public:
		TerminoBinomio(long long coef, int expX, int expY);

		// Getters
		long long getCoeficiente() const;
		int getExponenteX() const;
		int getExponenteY() const;

		// Setters
		long long setCoeficiente(long long coef);
		int setExponenteX(int expX);
		int setExponenteY(int expY);
};

#endif