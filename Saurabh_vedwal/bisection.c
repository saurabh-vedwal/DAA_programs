#include<stdio.h>
#include<math.h>

double fun(double x){
	return pow(x,3)- (4*x) -9;
}

int main(){
	float x,y;
	double x0,x1;
	float dec;
	printf("ENTER THE VALUE OF FIRST INTERVAL ");
	scanf("%f",&x);
	scanf("%f",&y);
	printf("ENTER THE ERROR		");
	scanf("%f",&dec);
	x0=fun(x);
	x1=fun(y);
	
	if(x0*x1>0.0){
		printf("INCORRECT INTERVAL ");
	}
	float x2=(x+y)/2.0;
	int i=1;
	do{
		printf("value of iteration at i=  %d  x2= %f \n",i,x2);
		if(fun(x)*fun(x2)<0){
			y=x2;
		}
		else{
			x=x2;
		}
		x2=(x+y)/2.0;
		i++;
	}while(fabs(x2-x)>=0.0001 || fabs(x2-y)>=0.0001);
	
}
