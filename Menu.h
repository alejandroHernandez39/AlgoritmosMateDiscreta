#pragma once

#ifndef MENU_H
#define MENU_H

class Menu {
	private:
		int opcion;

	public:
		Menu();

		void mostrarMenu(); // Muestra el menu principal
		void  mostrarSubmenuBinomio(); // Muestra el submenu del binomio de Newton
		void mostrarSubmenuTeorema(); // Muestra el submenu del teorema fundamental de la aritmetica
		void mostrarSubmenuEuclides(); // Muestra el submenu del algoritmo de Euclides

		int seleccionarOpcion();
		void ejecutar();
};

#endif