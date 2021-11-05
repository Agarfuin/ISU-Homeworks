#include<stdio.h>

float side1,side2,side3;
int equilateral, scalene, isoscele;

void classify_triangles(int side1, int side2, int side3);

int main() {
	while(1) {
		printf("Enter the side lengths of the triangle\n");
		scanf("%f %f %f", &side1,&side2,&side3);
		if(side1 == -1 && side2 == -1 && side3 == -1)
			break;
		else
			classify_triangles(side1, side2, side3);
	}
	printf("Equilateral triangles: %d\n", equilateral);
	printf("Isosceles triangles: %d\n", isoscele);
	printf("Scalene triangles: %d\n", scalene);
	return 0;
}

void classify_triangles(side1, side2, side3) {
	if(side1+side2+side3 <= 12) {
		printf("You entered a small triangle\n");
		if(side1 == side2 && side2 == side3 && side3 == side1)
			equilateral += 1;
		else if(side1 != side2 && side2 != side3 && side3 != side1)
			scalene += 1;
		else
			isoscele += 1;
	}
	else {
		if(side1 == side2 && side2 == side3 && side3 == side1)
			equilateral += 1;
		else if(side1 != side2 && side2 != side3 && side3 != side1)
			scalene += 1;
		else
			isoscele += 1;
	}
}