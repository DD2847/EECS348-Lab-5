#include <stdio.h>

void reader(float *ptr){
    FILE *salesNums = fopen("sales_nums.txt", "r");
    for (int i = 0; i < 12; i++){
        fscanf(salesNums, "%f", &ptr[i]);
    }
    fclose(salesNums);
}

void summary(float *nums, double *min, double *max, double *avg){
    *min = nums[0];
    *max = nums[0];
    for (int i = 0; i < 12; i++){
        //printf("Current: %.2f, Min: %-10.2f\n", ptr[i], min); HEY LOOK HERE! The syntax of the Min is tight af. The number to the left of the decimal defines how much space is allowed for the numbers. The minus alligns it to the left which will be important for printing the sales reports.
        if (nums[i] < *min){
            *min = nums[i];
        }
        if (nums[i] > *max){
            *max = nums[i];
        }
        *avg += nums[i];
    }
    *avg = *avg/12;
}

float sixer(float *nums, int a, int b){
    float movingAvg = 0;
    for (int i = a-1; i < b; i++){
        movingAvg += nums[i];
    }
    return movingAvg/6;
}

void sorter(float *nums){
    char monArray[][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October","November", "December"};
    float tester[12];
    for (int i = 0; i < 12; i++){
        tester[i] = nums[i];
    }
    for (int i = 1; i < 12; i++){
        float temp = tester[i];
        int j = i - 1;
        while (j >= 0 && tester[j] < temp){
            tester[j + 1] = tester[j];
            j--;
        }
        tester[j + 1] = temp;
    }
    for (int i = 0; i < 12; i++){
       for (int k = 0; k < 12; k++){
            if (tester[i] == nums[k]){
                printf("$%-15.2f%-15s\n", nums[k], monArray[k]);
            }
        }
    }
}

void report(float *nums, double *min, double *max, double *avg){
    char monArray[][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October","November", "December"};
    printf("Monthly Sales Report for 2023:\n\n");
    printf("%-15s %-15s\n", "Month","Sales");
    for (int i = 0; i < 12; i++){
        printf("%-15s $%-15.2f\n", monArray[i], nums[i]);
    }
    printf("\n\nSales Summary:\n\n");
    for (int i = 0; i < 12; i++){
        if (nums[i] == *min){
            printf("Minimum Sales:  $%-10.2f(%s)\n", *min, monArray[i]);
        }
        if (nums[i] == *max){
            printf("Maximum Sales:  $%-10.2f(%s)\n", *max, monArray[i]);
        }
    }
    printf("Average Sales:  $%-12.2f\n", *avg);
    printf("\n\nSix-Month Moving Average Report:\n\n");
    for (int i = 1, j = 6; i < 8; i++, j++){
        printf("%-11s%-3s%-13s$%-10.2f\n", monArray[i-1], "-", monArray[j-1], sixer(nums,i,j));
    }
    printf("\n\nSales Report (Highest to Lowest):\n\n");
    printf("%-15s %-15s\n", "Month","Sales");
    sorter(nums);
}

int main(){
    float numArray[12];
    double min, max, avg;
    reader(numArray);
    summary(numArray, &min, &max, &avg);
    report(numArray, &min, &max, &avg);
    return 0;
}