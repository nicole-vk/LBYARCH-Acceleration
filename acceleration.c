#include <stdio.h>
#include <stdlib.h>

typedef float matrix[3];	// declare 1D matrix
extern int computeAcceleration(float initialV, float finalV, float time);


int main(){
	int nCars;
	float initialV, finalV, time;
	
	// ask for number of cars
	scanf("%d", &nCars);
	
	// dynamically allocates a 2D array (row x 3).
	matrix *ptMatrix = malloc(nCars * sizeof(matrix));
    if (!ptMatrix) {
        printf("Memory allocation failed.\n");
        return 1;
    }
	
	
	// loop per row
	for(int i = 0; i < nCars; i++){
		
		scanf("%f, %f, %f", &initialV, &finalV, &time);
		
		ptMatrix[i][0] = initialV;
		ptMatrix[i][1] = finalV;
		ptMatrix[i][2] = time;
	}
	
	// print output
	printf("\n");
	for(int i = 0; i < nCars; i++){
		int acceleration = computeAcceleration(ptMatrix[i][0], ptMatrix[i][1], ptMatrix[i][2]);		// avoid passing array
		
		printf("%d\n", acceleration);
	}
	
	free(ptMatrix);
	return 0;
}