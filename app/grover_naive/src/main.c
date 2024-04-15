#include "platform_info.h"
#include "ervp_printf.h"
#include "ervp_multicore_synch.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define _USE_MATH_DEFINES
#define NUM_QUBIT 4
#define NUM_STATE (1<<NUM_QUBIT)
#define NUM_MAT_ENTRY (NUM_STATE)*(NUM_STATE)
#define NUM_ITERATE (int)floor(3.14*sqrt(NUM_STATE)/4)
#define FX_SOLUTION 12
	// 0 to NUM_STATE-1

// tensorProduct 함수 구현
void tensorProduct(const float *a, int sizeA, const float *b, int sizeB, float *result, int sizeResult) {
    int rowsA = (int)sqrt(sizeA);
    int colsA = rowsA;
    int rowsB = (int)sqrt(sizeB);
    int colsB = rowsB;
    
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            for (int k = 0; k < rowsB; k++) {
                for (int l = 0; l < colsB; l++) {
                    result[(i * rowsB + k) * (colsA * colsB) + (j * colsB + l)] = a[i * colsA + j] * b[k * colsB + l];
                }
            }
        }
    }
}

float H[4];

void matrixVectorMultiply(float *matrix, float *vector) {
    float result[NUM_STATE];
    int i,j;
    // 행렬-벡터 곱 계산
    for (i = 0; i < NUM_STATE; i++) {
        result[i] = 0; // 결과 벡터 초기화
        for (j = 0; j < NUM_STATE; j++) {
            result[i] += matrix[i * (NUM_STATE) + j] * vector[j];
        }
    }

    // 계산된 결과를 원래 벡터에 복사
    for (i = 0; i < NUM_STATE; i++) {
        vector[i] = result[i];
    }
}

void calculateHadamardTensorProduct(float *result) {
    float tempResult[NUM_MAT_ENTRY]; 
    float *a, *b = H;
    int tempSizeA, tempSizeB = 4;
    int i, qubit;

    
    for (i = 0; i < 4; i++) {
        result[i] = H[i];
    }

    
    for (qubit = 2; qubit <= NUM_QUBIT; qubit++) {
        tempSizeA = 1 << (qubit - 1); // a의 현재 크기
        tensorProduct(result, tempSizeA * tempSizeA, b, tempSizeB, tempResult, tempSizeA * tempSizeA * tempSizeB);
        // 중간 결과를 result 배열에 복사
        for (int i = 0; i < tempSizeA * tempSizeA * tempSizeB; i++) {
            result[i] = tempResult[i];
        }
    }
}

void calculateZorMatrix(float matrix[])
{
    int i,j;

    for(i = 0; i < NUM_STATE; i++)
        for(j = 0; j < NUM_STATE; j++)
        {
            if(i == 0 && j == 0)
                matrix[i*(NUM_STATE) + j] = 1.0;
            else if(i == j)
                matrix[i*(NUM_STATE) + j] = -1.0;
            else
                matrix[i*(NUM_STATE) + j] = 0.0;
        }

}

int fx(int x)
{
	return (x == FX_SOLUTION) ? 1 : 0;
}

void oracle(float state[])
{
	int i;
	for(i = 0; i < NUM_STATE; i++)
		if( fx(i) ) 
			state[i] = -state[i];
}

void hadamard(float hadamard_matrix[], float state[])
{
	matrixVectorMultiply(hadamard_matrix, state);
}

void z_or(float zor_matrix[], float state[]) // modify so that z_or implies matrix_vector multiplying
{
    matrixVectorMultiply(zor_matrix, state);
}

int main() {
    
    float hadamard_matrix[NUM_MAT_ENTRY];
    float zor_matrix[NUM_MAT_ENTRY];

	float state[NUM_STATE];
	int i,j;

    // long long begin, end;

    H[0] = 1.0/sqrt(2);
    H[1] = 1.0/sqrt(2);
    H[2] = 1.0/sqrt(2);
    H[3] = -1.0/sqrt(2);

    calculateZorMatrix(zor_matrix);
    calculateHadamardTensorProduct(hadamard_matrix);

    // begin = clock();

	for(i = 0; i < NUM_STATE; i++)
	{
		state[i] = sqrt(1.0 / (NUM_STATE));
	}
	
    //for(i = 0; i < NUM_STATE; i++)
    //    printf("%f\n", state[i]);

    // printf("NUM_ITERATE = %d\n",NUM_ITERATE);

	for(i = 0; i < NUM_ITERATE; i++)
	{
		oracle(state);
		hadamard(hadamard_matrix, state);
		z_or(zor_matrix, state);
		hadamard(hadamard_matrix, state);

        //for(j = 0; j < NUM_STATE; j++)
        //    printf("%f ", state[j]);
        //printf("\n");
	}
	
    // end = clock();

    /* check state value
    for(i = 0; i < NUM_STATE; i++)
        printf("%f\n", state[i]);
	*/
    return state[0];
}


 


