#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// (a) f1(x) = x^5 − 2x^4 − 9x^3 + 22x^2 + 4x − 24
double f1(double x) {
    return pow(x, 5) - 2 * pow(x, 4) - 9 * pow(x, 3) + 22 * pow(x, 2) + 4 * x - 24;
}

// (b) f2(x) = sqrt(x) - cos(x)
double f2(double x) {
    return sqrt(x) - cos(x);
}

// (c) f3(x) = (sqrt(x) - 5) * exp(-x)
double f3(double x) {
    return (sqrt(x) - 5) * exp(-x);
}

// Exemplo x^2 - 2
double exemplo(double x) {
    return x * x - 2;
}

double bissecao(double (*f)(double), double a, double b, double eps, int *ok, int *passos);
double secante(double (*f)(double), double x0, double x1, double eps, int *ok, int *passos);
double derivada(double (*f)(double), double x);

int main(int argc, char const *argv[]){
    if(argc != 5) {
        printf("Uso: %s <bs|sec> <eps> <x0> <x1>\n", argv[0]);
        return 1;
    }

    const char *metodo = argv[1];
    double eps = atof(argv[2]);
    double x0 = atof(argv[3]);
    double x1 = atof(argv[4]);

    double resultado;
    int ok, passos;

    // DEFINA AQUI A FUNÇÃO

    double (*f)(double) = f3;

    printf("Metodo: %s\n", metodo);
    printf("Refinamento e criterio de parada: %g\n", eps);
    printf("Error maximo %.1E\n", eps);
    printf("x(0) ou a = %.20f\n", x0);
    printf("x(1) ou b = %.20f\n\n", x1);

    if (strcmp(metodo, "bs") == 0) {
        printf("*** Metodo da Bissecao ***\n");
        resultado = bissecao(f, x0, x1, eps, &ok, &passos);
    } else if (strcmp(metodo, "sec") == 0) {
        printf("*** Metodo da Secante ***\n");
        resultado = secante(f, x0, x1, eps, &ok, &passos);
    } else {
        printf("Metodo invalido. Use 'bs' para bissecao ou 'sec' para secante.\n");
        return 1;
    }

    printf("Error: %.8e\n", eps);
    printf("Intervalo: (%.6f, %.6f)\n", x0, x1);
    printf("fx(a = %.15f) = %.15f\n", x0, f(x0));
    printf("fx(b = %.15f) = %.15f\n", x1, f(x1));
    printf("\nInformacao da derivada:\n");
    printf("gx(a = %.15f) = %.15f\n", x0, derivada(f, x0));
    printf("gx(b = %.15f) = %.15f\n", x1, derivada(f, x1));

    if (ok) {
        printf("\nTEM RAIZ REAL <-**********\n");
        printf("Valor de x e %.15f - passos de iteracao %d\n", resultado, passos);
    } else {
        printf("\nNAO CONVERGIU OU NAO HA RAIZ NO INTERVALO.\n");
    }

    return 0;
}
double bissecao(double (*f)(double), double a, double b, double eps, int *ok, int *passos){
	double limite1= a;
	double limite2= b;
	double raiz, f1, f2, f3;
	int ctr = 1;
	*ok = 0;

	for(ctr= 1; ctr <= 1000; ctr++){
		f1= f(limite1);
		raiz= (limite1 + limite2) / 2.0;
		f2= f(raiz);
		f3= f(limite2);

		if(fabs(f2) < eps){
			*ok= 1;
			*passos= ctr;
			return raiz;
		}

		if(f1 * f2 < 0){
			limite2= raiz;
		}else if(f2 * f3 < 0){
			limite1= raiz;
		}else{
			*ok= 0;
			*passos= ctr;
			return raiz;
		}
	}
	*ok= 0;
	*passos = 1000;
    return raiz;
}

double secante(double (*f)(double), double x0, double x1, double eps, int *ok, int *passos){
    double raiz, f0, f1;
    int ctr = 1;
    *ok = 0;

    for(ctr= 1; ctr <= 1000; ctr++){
        f0= f(x0);
        f1= f(x1);
        if (fabs(f1 - f0) < eps) { 
            printf("Divisao por valor pequeno\n");
            *ok = 0;
            *passos = ctr;
            return raiz; 
        }
        raiz= x1 - (f1 * (x1 - x0)) / (f1 - f0);

        if(fabs(f(raiz)) < eps){
            *ok= 1;
            *passos= ctr;
            return raiz;
        }

        x0= x1;
        x1= raiz;
    }
    *ok= 0;
    *passos = 1000;
    return raiz;
}

double derivada(double (*f)(double), double x){
    double h = 1e-5; // passo pequeno
    return (f(x + h) - f(x - h)) / (2 * h);
}
