#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float calculateOutput(float Input, float Weight) {
	return Input * Weight;
}

float getRandomNumber01() {
	srand(time(NULL));
	float Rand = (float)rand() / (float)RAND_MAX;
	return Rand;
}

bool areCloseEnough(float A, float B) {
	float Diff = (A > B) ? (A - B) : (B - A);
	return (Diff < 1.0f);
}


//const int NUM_INPUTS = 3;
//float Input[NUM_INPUTS] = {1.0f, 2.0f, 3.0f};
//float ExpectedOutput[NUM_INPUTS] = {3.0f, 6.0f, 9.0f};


int main()
{
//	srand(time(NULL));
//	float Rand = (float)rand() / (float)RAND_MAX;
//	printf("Rand: %f\n", Rand);
//	return 0;

	// training data
	float Input = 1.0f;
	float ExpectedOutput = 3.0f;

	// model
	float Weight = 7.1f;

	bool IsGoodEnough = false;
	while (!IsGoodEnough) {
		float RealOutput = calculateOutput(Input, Weight);
		printf("%f, %f\n", RealOutput, ExpectedOutput);
//		if (RealOutput == ExpectedOutput) {
		if (areCloseEnough(RealOutput, ExpectedOutput)) {
			IsGoodEnough = true;
		} else {
			Weight = getRandomNumber01() * 6.0f;
		}
	}

	printf("Weight = %f\n", Weight);

	return 0;
}