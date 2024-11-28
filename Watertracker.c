#include <stdio.h>
#include <stdlib.h>
float getWaterConsumption(int day) {
    float consumption;
    while (1) {
        printf("Day %d: ", day);
        if (scanf("%f", &consumption) != 1 || consumption < 0) {
            printf("Invalid input. Please enter a valid positive number for Day %d.\n", day);
            while (getchar() != '\n');
        } else {
            return consumption;
        }
    }
}
float calculateTotalWater(float *water, int days) {
    if (days == 0) {
        return 0.0;
    }
    return water[days - 1] + calculateTotalWater(water, days - 1);
}
void provideHealthFeedback(float totalWater) {
    if (totalWater > 12) {
        printf("Health Feedback: You're drinking lots of water. Ensure it's within healthy limits.\n");
    } else if (totalWater < 12) {
        printf("Health Feedback: Your water intake is low. Aim for more water to stay hydrated.\n");
    } else {
        printf("Health Feedback: Keep going, you're doing great! You're right on target with 12 liters.\n");
    }
}
int main() {
    int days;
    printf("Enter the number of days you want to track water consumption for: ");
    while (1) {
        if (scanf("%d", &days) != 1 || days <= 0) {
            printf("Invalid input. Please enter a positive integer for the number of days.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    }
    float *water = (float *)malloc(days * sizeof(float));
    if (water == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    printf("\nEnter the water consumption (in liters) for each day:\n");
    for (int i = 0; i < days; i++) {
        water[i] = getWaterConsumption(i + 1);
    }
    float totalWater = calculateTotalWater(water, days);
    float averageWater = totalWater / days;
    printf("\n--- Water Consumption Summary ---\n");
    printf("Total water consumption for %d day(s): %.2f liters\n", days, totalWater);
    printf("Average daily water consumption: %.2f liters\n", averageWater);
    printf("\n");
    provideHealthFeedback(totalWater);
    free(water);
    return 0;
}