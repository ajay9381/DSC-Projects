#include<stdio.h>
#include<stdlib.h>
int main (int argc, char **argv) {
printf("argc= %d\n", argc);
printf("Value passed to program = %s\n",argv [1]);
double k = atof(argv[1]);
printf("after converting string to double,value = %f \n",k);
if(k<2) {
printf("Low CPU usage!\n");
} else if(k>10){
printf("High CPU usage!\n");
} else{
printf("Moderate CPU usage!\n");
}
return 0;
}
