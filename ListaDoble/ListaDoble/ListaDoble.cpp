#include "stdafx.h"
#include <iostream>

using namespace System;
using namespace std;

struct nodo
{
	nodo* siguiente;
	nodo* anterior;
	int valor;

	nodo();
	~nodo();
};

struct lista
{
	nodo* cabeza;

	void Insertar(int posicion, int valor);
	void InsertarInicio(int valor);
	void InsertarFinal(int valor);

	void Eliminar(int posicion);

	void MostrarElementos();
	void MostrarCantidad();
	void BuscarNumero(int busqueda);
	void NumeroMinimo();
	void NumeroMaximo();

	lista();
	~lista();
};

nodo::nodo()
{
	this->siguiente = NULL;
	this->anterior = NULL;
}

nodo::~nodo()
{
}

lista::lista()
{
	cabeza = NULL;
}

lista::~lista()
{
}

void lista::InsertarFinal(int valor)
{
	//Se crea nodo a ingresar a la lista
	nodo* tmp = new nodo;
	tmp->valor = valor;


	if (cabeza == NULL) //Validar si hay nodos en la lista
	{
		cabeza = tmp;
	}
	else
	{
		//Recorrer lista

		nodo* tmp2 = cabeza; //Nodo anterior

		while (tmp2 != NULL)
		{
			if (tmp2->siguiente == NULL)
			{
				tmp2->siguiente = tmp;
				tmp->anterior = tmp2;
				break;
			}
			else
			{
				tmp2 = tmp2->siguiente; //Siguient posicion en la lista
			}
		}
	}
}

void lista::InsertarInicio(int valor)
{
	//Se crea nodo a ingresar a la lista
	nodo* tmp = new nodo;
	tmp->valor = valor;


	if (cabeza == NULL) //Validar si hay nodos en la lista
	{
		cabeza = tmp;
	}
	else
	{
		//Recorrer lista

		nodo* tmp2 = cabeza; //Primer Nodo

		//Covertir nodo ingresao en la nueva cabeza
		tmp->siguiente = tmp2;
		tmp2->anterior = tmp;
		cabeza = tmp;

	}
}

void lista::Insertar(int posicion, int valor)
{
	//Se crea nodo a ingresar a la lista
	nodo* tmp = new nodo;
	tmp->valor = valor;
	int i = 0;

	if (cabeza == NULL) //Validar si hay nodos en la lista
	{
		cabeza = tmp;
	}
	else
	{
		//Recorrer lista

		nodo* anterior = NULL;
		nodo* actual = cabeza; //Nodo anterior

		while (actual != NULL)
		{
			if (i == posicion)
			{
				anterior->siguiente = tmp;
				tmp->siguiente = actual;

				actual->anterior = tmp;
				tmp->anterior = anterior;

				break;
			}
			else
			{
				//Siguiente posicion en la lista
				anterior = actual;
				actual = actual->siguiente;

				if (actual == NULL)
				{
					cout << "La posición ingresada está fuera de rango" << endl;
				}
				i++;
			}
		}
	}
}

void lista::Eliminar(int posicion)
{
	//Se crea nodo a ingresar a la lista
	nodo* tmp = new nodo;
	int i = 0;

	if (cabeza == NULL) //Validar si hay nodos en la lista
	{
		cout << "La lista está vacía" << endl;
	}
	else
	{
		//Recorrer lista

		nodo* anterior = NULL;
		nodo* actual = cabeza;

		while (actual != NULL)
		{
			if (i == posicion)
			{
				anterior->siguiente = actual->siguiente;
				actual->siguiente->anterior = anterior;

				break;
			}
			else
			{
				//Siguiente posicion en la lista
				anterior = actual;
				actual = actual->siguiente;

				if (actual == NULL)
				{
					cout << "La posición ingresada está fuera de rango";
				}
				i++;
			}
		}
	}
}

void lista::MostrarElementos()
{
	cout << "Elementos:" << endl;

	if (cabeza == NULL) //Validar si hay nodos en la lista
	{
		cout << "La lista está vacía" << endl;
	}
	else
	{
		//Recorrer lista

		nodo* actual = cabeza;

		while (actual != NULL)
		{
			cout << "->" << actual->valor << " ";

			//Siguiente posicion en la lista
			actual = actual->siguiente;
		}

		cout << endl;
	}
}

void lista::MostrarCantidad()
{
	cout << "Cantidad Elementos: ";

	if (cabeza == NULL) //Validar si hay nodos en la lista
	{
		cout << "La lista está vacía" << endl;
	}
	else
	{
		//Recorrer lista

		nodo* actual = cabeza;
		int i = 0;

		while (actual != NULL)
		{
			//Siguiente posicion en la lista
			actual = actual->siguiente;
			i++;
		}

		cout << i << endl;
	}
}

void lista::BuscarNumero(int busqueda)
{
	nodo* tmp = cabeza;
	int posicion = 0;

	if (tmp == NULL)
	{
		cout << "La lista está vacía" << endl;
	}
	else
	{
		while (tmp != NULL) //Mientras aun existan elementos en la lista a recorrer 
		{
			if (tmp->valor == busqueda)
			{
				cout << "El numero se encuentra en la posicion: ";
				cout << posicion << endl;
				break;
			}
			else
			{
				tmp = tmp->siguiente;
				posicion++;
				if (tmp == NULL)
				{
					cout << "El numero no fue encontrado...\n";
					break;
				}
			}
		}
	}
}

void lista::NumeroMinimo()
{
	nodo* tmp = cabeza;
	int resultado;

	if (tmp == NULL)
	{
		cout << "La lista está vacía" << endl;
	}
	else
	{
		resultado = tmp->valor; //Valor por default

		while (tmp != NULL) //Mientras aun existan elementos en la lista a recorrer 
		{
			if (tmp->valor < resultado) //Comparar si es mayor
			{
				resultado = tmp->valor;
			}

			tmp = tmp->siguiente;
		}

		cout << "El numero mas pequeño es: ";
		cout << resultado << endl;
	}
}

void lista::NumeroMaximo()
{
	nodo* tmp = cabeza;
	int resultado;

	if (tmp == NULL)
	{
		cout << "La lista está vacía" << endl;
	}
	else
	{
		resultado = tmp->valor; //Valor por default

		while (tmp != NULL) //Mientras aun existan elementos en la lista a recorrer 
		{
			if (tmp->valor > resultado) //Comparar si es menor
			{
				resultado = tmp->valor;
			}

			tmp = tmp->siguiente;
		}

		cout << "El numero mas grande es: ";
		cout << resultado << endl;
	}
}

int main()
{
	bool salir = false;
	lista list;
	int opcion;

	int valor;
	int posicion;

	do
	{
		system("CLS");
		cout << "MENU PRINCIPAL\n";
		cout << "Elige una opcion:\n";

		cout << "1. Agregar elemento a inicio de lista\n";
		cout << "2. Agregar elemento al final de la lista\n";
		cout << "3. Agregar elemento en cualquier posicion de la lista\n";
		cout << "4. Eliminar elemento\n";
		cout << "5. Mostrar cantidad de elementos\n";
		cout << "6. Encontrar numero minimo\n";
		cout << "7. Encontrar numero maximo\n";
		cout << "8. Encontrar elemento\n";
		cout << "9. Imprimir elementos\n";
		cout << "10. Salir\n";

		try
		{
			cin >> opcion;

			system("CLS");

			switch (opcion)
			{
			case 1:
				cout << "1. Agregar elemento a inicio de lista\n";

				cout << "Ingrese el valor a ingresar: \n";

				cin >> valor;
				list.InsertarInicio(valor);

				cout << "Valor ingresado exitosamente!\n";
				system("pause");
				break;
			case 2:
				cout << "2. Agregar elemento al final de la lista\n";

				cout << "Ingrese el valor a ingresar: \n";

				cin >> valor;
				list.InsertarFinal(valor);

				cout << "Valor ingresado exitosamente!\n";
				system("pause");
				break;
			case 3:
				cout << "3. Agregar elemento en cualquier posicion de la lista\n";

				cout << "Ingrese el valor a ingresar: \n";

				cin >> valor;

				cout << "Ingrese la posicion (Empieza en 0): \n";

				cin >> posicion;
				list.Insertar(posicion, valor);

				cout << "Valor ingresado exitosamente!\n";

				system("pause");
				break;
			case 4:
				cout << "4. Eliminar elemento\n";

				cout << "Ingrese la posicion a eliminar (Empieza en 0): \n";

				cin >> posicion;
				list.Eliminar(posicion);

				system("pause");
				break;
			case 5:
				cout << "5. Mostrar cantidad de elementos\n";

				list.MostrarCantidad();

				system("pause");
				break;
			case 6:
				cout << "6. Encontrar numero minimo\n";

				list.NumeroMinimo();

				system("pause");
				break;
			case 7:
				cout << "7. Encontrar numero maximo\n";

				list.NumeroMaximo();

				system("pause");
				break;
			case 8:
				cout << "8. Encontrar elemento\n";

				cout << "Ingrese el valor a buscar: \n";

				cin >> valor;

				list.BuscarNumero(valor);

				system("pause");
				break;
			case 9:
				cout << "9. Imprimir elementos\n";

				list.MostrarElementos();

				system("pause");
				break;
			case 10:
				salir = true;
				break;
			default:
				cout << "Valor invalido";
				break;
			}
		}
		catch (const std::exception&)
		{
			cout << "Valor invalido: Ingrese un numero." << endl;
			system("pause");
		}

	} while (!salir);

}

