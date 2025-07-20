#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef float matrix[3];	                                                            // declare 1D matrix
extern int computeAcceleration(float initialV, float finalV, float timeConsumed);

int checkValid(char answer){
	if(answer == 'Y' || answer == 'y')
		return 0;
	else if(answer == 'N' || answer == 'n')
		return 0;
	
	return 1;
}

char checkAnswer(char answer){
	if(answer == 'Y' || answer == 'y')
		return 'Y';
	
	return 'N';
}

int main(){
	int nCars;
	char answer;
	float initialV, finalV, timeConsumed;
    matrix *ptMatrix = NULL;
	

    printf("Enter number of cars to generate: ");                                   // ask for number of cars
    scanf("%d", &nCars);

    ptMatrix = malloc(nCars * sizeof(matrix));                                      // dynamically allocates a 2D array (row x 3).
    if (!ptMatrix) {
        printf("Memory allocation failed.\n");
        return 1;
    }


	do{
		printf("Do you want to generate the inputs randomly (Y/N): ");
		scanf(" %c", &answer);

	}while(checkValid(answer));
	
	
	switch(checkAnswer(answer)){
		case 'Y':
			srand(time(NULL));

            for(int i = 0; i < nCars; i++) {                                            // loop per row
                initialV = ((float)rand() / RAND_MAX) * 100.0f;
                finalV = ((float)rand() / RAND_MAX) * 100.0f;
                timeConsumed = 1.0f + ((float)rand() / RAND_MAX) * 9.0f;

                ptMatrix[i][0] = initialV;
                ptMatrix[i][1] = finalV;
                ptMatrix[i][2] = timeConsumed;
            }
			
            for(int i = 0; i < nCars; i++){
                printf("%f, %f, %f\n", ptMatrix[i][0], ptMatrix[i][1], ptMatrix[i][2]);
            }

			break;
			
		case 'N':
			for(int i = 0; i < nCars; i++){                                             // loop per row
				
				scanf("%f, %f, %f", &initialV, &finalV, &timeConsumed);
				
				ptMatrix[i][0] = initialV;
				ptMatrix[i][1] = finalV;
				ptMatrix[i][2] = timeConsumed;
			}
			
			break;
	}
	
	
	printf("\n");
	for(int i = 0; i < nCars; i++){                                                     // output returned + printing
		int acceleration = computeAcceleration(ptMatrix[i][0], ptMatrix[i][1], ptMatrix[i][2]);		// avoid passing array
		
		printf("%d\n", acceleration);
	}
	
	free(ptMatrix);
	return 0;
}