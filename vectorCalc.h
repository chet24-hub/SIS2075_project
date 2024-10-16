#ifndef VECTORCALC_H
#define VECTORCALC_H

#include<stdio.h>
#include<math.h>

// Function to calculate the magnitude of a vector
double vectorMagnitude(double vector[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += vector[i] * vector[i];
    }
    return sqrt(sum);
}

// Function to calculate the dot product of two vectors
double dot_product(double vector1[], double vector2[], int size) {
    double result = 0.0;
    for (int i = 0; i < size; i++) {
        result += vector1[i] * vector2[i];
    }
    return result;
}

// Function to calculate the cross product of two 3D vectors
void cross_product(double vector1[], double vector2[], double result[]) {
    result[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
    result[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
    result[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];
}

// Function to calculate the L2 norm (Euclidean norm) of a vector
double calculateL2Norm(double vector[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += vector[i] * vector[i];
    }
    return sqrt(sum);
}

// Function to calculate the angle between two vectors
double calculateAngle(double vector1[], double vector2[], int size) {
    double dotProd = dot_product(vector1, vector2, size);
    double magnitude1 = vectorMagnitude(vector1, size);
    double magnitude2 = vectorMagnitude(vector2, size);
    double cosTheta = dotProd / (magnitude1 * magnitude2);
    return acos(cosTheta) * (180.0 / M_PI); // Return the angle in degrees
}

void vector() {
    FILE *file = fopen("vector_results.txt", "w");  // Open file to write results
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int size;
    int choice;

    printf("Enter the size of the vector (2 for 2D vector or 3 for 3D vector): ");
    scanf("%d", &size);

    if (size != 2 && size != 3) {
        printf("This calculator is only for 2D and 3D vectors.\n");
        fprintf(file, "This calculator is only for 2D and 3D vectors.\n");
        fclose(file);
        return;
    }

    double vector1[3], vector2[3], result[3];

    // Input the first vector
    printf("Enter the elements of the first vector:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%lf", &vector1[i]);
    }

    printf("Select the operation you want to perform:\n");
    printf("1. Vector magnitude\n");
    printf("2. Dot Product\n");
    printf("3. Cross Product (Only for 3D vector)\n");
    printf("4. Euclidean Norm\n");
    printf("5. Angle between two Vectors\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fprintf(file, "The magnitude of the vector is %.2lf\n", vectorMagnitude(vector1, size));
            printf("The magnitude of the vector is %.2lf\n", vectorMagnitude(vector1, size));
            break;

        case 2:
            printf("Enter the elements of the second vector:\n");
            for (int i = 0; i < size; i++) {
                printf("Element %d: ", i + 1);
                scanf("%lf", &vector2[i]);
            }
            fprintf(file, "The dot product of the vectors is %.2lf\n", dot_product(vector1, vector2, size));
            printf("The dot product of the vectors is %.2lf\n", dot_product(vector1, vector2, size));
            break;

        case 3:
            if (size != 3) {
                fprintf(file, "Cross product is only defined for 3D vectors.\n");
                printf("Cross product is only defined for 3D vectors.\n");
            } else {
                printf("Enter the elements of the second vector:\n");
                for (int i = 0; i < size; i++) {
                    printf("Element %d: ", i + 1);
                    scanf("%lf", &vector2[i]);
                }
                cross_product(vector1, vector2, result);
                fprintf(file, "The cross product of the vectors is: [%.2lf, %.2lf, %.2lf]\n", result[0], result[1], result[2]);
                printf("The cross product of the vectors is: [%.2lf, %.2lf, %.2lf]\n", result[0], result[1], result[2]);
            }
            break;

        case 4:
            fprintf(file, "The L2 norm of the vector is: %.2lf\n", calculateL2Norm(vector1, size));
            printf("The L2 norm of the vector is: %.2lf\n", calculateL2Norm(vector1, size));
            break;

        case 5:
            printf("Enter the elements of the second vector:\n");
            for (int i = 0; i < size; i++) {
                printf("Element %d: ", i + 1);
                scanf("%lf", &vector2[i]);
            }
            fprintf(file, "The angle between the vectors is: %.2lf degrees\n", calculateAngle(vector1, vector2, size));
            printf("The angle between the vectors is: %.2lf degrees\n", calculateAngle(vector1, vector2, size));
            break;

        default:
            fprintf(file, "Your choice is invalid.\n");
            printf("Your choice is invalid.\n");
            break;
    }

    fclose(file);  // Close the file after writing the results
    printf("Results saved in 'vector_results.txt'\n");

    // Open the file to view results
    FILE *openFile = fopen("vector_results.txt", "r");
    if (openFile == NULL) {
        printf("Error opening file!\n");
        return;
    }
    printf("\nContents of the result file:\n");
    char c;
    while ((c = fgetc(openFile)) != EOF) {
        putchar(c);
    }
    fclose(openFile);
     // Open the output file after the program exits
                #ifdef _WIN32
                    system("notepad vector_results.txt"); 
                #else
                    system("open vector_results.txt");  //Mac
                #endif
                
                return;
}

#endif // VECTORCALC_H
