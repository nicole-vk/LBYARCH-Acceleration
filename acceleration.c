#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef float matrix[3];	                                                            // declare 1D matrix
extern int computeAcceleration(float initialV, float finalV, float timeConsumed);

int isValidAnswer(char answer){
	return (answer == 'Y' || answer == 'y' || answer == 'N' || answer == 'n') ? 0 : 1;
}

char checkAnswer(char answer){
	return (answer == 'Y' || answer == 'y') ? 'Y' : 'N';
}

int main(){
	int nCars, result;
	char answer;
	float initialV, finalV, timeConsumed;
	matrix *ptMatrix = NULL;
	

    do {
        printf("Enter number of cars to generate: ");
        result = scanf("%d", &nCars);												// returns 1 if an integer was successfully read

        if (result != 1) {
            printf("Invalid input. Please enter a valid number.\n");

            while (getchar() != '\n');  											// clear the input buffer and discard leftover characters
        }

    } while (result != 1);
	

    ptMatrix = malloc(nCars * sizeof(matrix));                                      // dynamically allocates a 2D array (row x 3).
    if (!ptMatrix) {
        printf("Memory allocation failed.\n");
        return 1;
    }


	do{
		printf("Do you want to generate the inputs randomly (Y/N): ");
		scanf(" %c", &answer);

		if (isValidAnswer(answer))
			while (getchar() != '\n');

	}while(isValidAnswer(answer));
	
	
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