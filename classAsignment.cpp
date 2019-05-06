#include<iostream>
#include<math.h> 

using namespace std;

int func(float a, float b, float c, float *x1, float*x2);

int main(){
	float a, b, c;
	float x1, x2;
	cout << "Nhap a, b, c: ";
	cin >> a >> b >> c;

	switch (func(a, b, c, &x1, &x2)){
		case 0:{
			cout << "No solution" << endl;
			break;
		}
		case 1:{
                        cout << "One solution" << endl;
			printf("x = %.3f \n", x1);
                        break;
                }
		case 2:{
                        cout << "Double solution" << endl;
                        printf("x1 = x2 = %.3f \n", x1);
                        break;
                }
		case 3:{
                        cout << "Two solution" << endl;
                        printf("x1 = %.3f, x2 = %.3f \n", x1, x2);
                        break;
                }
		case 4:{
                        cout << "Any solution" << endl;
                        break;
                }
	}
}

int func(float a, float b, float c, float *x1, float *x2){

	float denta = (b)*(b) - 4*(a)*(c);
	//cout << "denta: " << denta << endl;
	if (a == 0){
		if (b == 0){
			if (c==0){
			return 4; //any solution
			}
			else return 0;
		}
		else {
		*x1 = -c/b;
		return 1; //one solution
		}
	}

	else if (denta < 0) {return 0;} //no solution
	else if (denta == 0) {
		*x1 = (-b/(2*a));
		return 2; //double solution
	}
	else if (denta > 0){
		*x1 = (-b + sqrt(denta))/(2*a);
		*x2 = (-b - sqrt(denta))/(2*a);
		return 3; //two solution
	}
}
