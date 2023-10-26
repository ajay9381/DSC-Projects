#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>
double error (double estimated_value);
double monteCarloIntegration(int N) {
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
	double x = (2.0 * rand() / (double)RAND_MAX) - 1.0;
	sum += 1.0 / (1.0 + x * x);
   }
    return (2.0 / N) * sum;
}
int main() {
    int Imax=30;
   double estimated_value,err;
   FILE *file = fopen("NvsError.dat", "w");
   for(int i=1;i<=Imax;i++){
	   int N =(int)pow(2,i);
	   srand(time(NULL));
	   estimated_value = monteCarloIntegration(N);
	   err=error(estimated_value);
	   printf("%d    ",N);
          printf("%lf\n", err);
	  fprintf(file,"%d  %lf\n",N,err);
   }
    return 0;
}
double error(double estimated_value){
	const double pi=3.141592653589793;
	double absolute_error=fabs(estimated_value - pi /2.0);
	return absolute_error;
}

