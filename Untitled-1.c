#include <stdio.h>

float avg(float data[], int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}




void vcecalc(float data[], int n) {
    // Calls back to the original function to get the mean
    float mean = avg(data, n);
    float sumsqrdif = 0.0;

    for (int i = 0; i < n; i++) {
        // Use the newly created mean function rather than the original avg(data, n)
        float difference = data[i] - mean;
        // Having data[i] keeps the product of each data[i] - avg as a separate category
        sumsqrdif += difference * difference;
    }

    float variance = sumsqrdif / n;

    for (int i = 0; i < n; i++) {
        // Again, using the new function rather than the old
        float difference = data[i] - mean;
        printf("data[%d]:\n variance: %f\n", i, difference * difference);
    }
}





int main() {
    float arr[] = {2.5, 3.5, 4.0, 5.5, 6.0, 7.0};
    int s = sizeof(arr)/sizeof(arr[0]);

    printf("Mean AKA average: \n %f", avg(arr, s)); 
    vcecalc(arr, s);

    return  0;
}