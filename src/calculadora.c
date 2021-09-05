#include <stdio.h>
#include <stdlib.h>
int operacionSuma (int operadorUno, int operadorDos);
int operacionResta (int operadorUno, int operadorDos);
int operacionMultiplicacion (int operadorUno, int operadorDos);
float operacionDivicion (int operadorUno, int operadorDos, float* returnResultado);
int pedirNumero (float* pNumero, float minimo, float maximo, int reintentos, char* variableTextoSolicitudNumero, char* variableTextoFueraDeRango);
#define REINTENTOS 3
int main(void) {
	float numeroUno;
	float numeroDos;
	char operador;
	int calculoInt;
	float resultado;
	int retError;
	setbuf (stdout, NULL);

	if (pedirNumero (&numeroUno, 0.0, 1000.0, REINTENTOS, "Ingrese el primer numero", "usted se encuentra fuera del rango") == 0){
		printf ("Ingresaste %.2f ", numeroUno);
	}else{
		printf ("\nError. estas fuera del rango");
		exit (0);
	}
	fflush(stdin);
	printf ("\nIngrese la operacion a realizar (s-suma; r-resta; m-multiplicacion; d-divicion):");
	scanf ("%c", &operador);

	if (pedirNumero (&numeroDos, 0.0, 1000.0, REINTENTOS, "Ingrese el segundo numero", "usted se encuentra fuera del rango") == 0){
			printf ("Ingresaste %.2f ", numeroDos);
		}else{
			printf ("\nError. estas fuera del rango");
			exit (0);
		}
	switch (operador){
	case 's':
		calculoInt = operacionSuma (numeroUno, numeroDos);
	break;

	case 'r':
		calculoInt = operacionResta (numeroUno, numeroDos);
	break;

	case 'm':
		calculoInt = operacionMultiplicacion (numeroUno, numeroDos);
	break;
	case 'd':
		retError = operacionDivicion (numeroUno, numeroDos, &resultado);
		if (retError == 1){
			printf ("Error. no se puede dividir por 0");
		}else {
			printf ("El resultado es %.2f", resultado);
		}
	break;
	}

	if (operador != 'd'){
		printf ("\nEl resultado es %d", calculoInt);
	}
	return 0;
}

int operacionSuma (int operadorUno, int operadorDos){
	int resultado;
	resultado = operadorUno + operadorDos;
	return resultado;

}

int operacionResta (int operadorUno, int operadorDos){
	int resultado;
	resultado = operadorUno - operadorDos;
	return resultado;
}

int operacionMultiplicacion (int operadorUno, int operadorDos){
	int resultado;
	resultado = operadorUno * operadorDos;
	return resultado;
}
float operacionDivicion (int operadorUno, int operadorDos, float* returnResultado){
	float resultado;
	int huboError;

	if (operadorDos != 0){
		resultado = (float)operadorUno / operadorDos;
		(*returnResultado) = resultado;
		huboError = 0;
	}else{
		huboError = 1;
	}
	return huboError;
}
int pedirNumero (float* pNumero, float minimo, float maximo, int reintentos, char* variableTextoSolicitudNumero, char* variableTextoFueraDeRango){
	float aux;
	int huboError;
	int i;
	if (minimo < maximo){
	for (i = 0; i < reintentos; i++){
	printf ("%s \n", variableTextoSolicitudNumero);
	fflush (stdin);
	scanf ("%f", &aux);

	if (aux >= minimo && aux <= maximo){
		(*pNumero) = aux;
		huboError = 0;
		break;
	}else
	{
		huboError = 1;
		printf ("%s\n",variableTextoFueraDeRango);
	}
}
	}
	return huboError;
}

