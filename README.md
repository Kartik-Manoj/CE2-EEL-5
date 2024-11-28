# CE2-EEL-5
1.	Research

•	Recursive Function: TechTerms - Recursive Function
•	Average Calculation: GeeksforGeeks - Average in Maths
•	Health Feedback Based on Water Intake: Harvard School of Public Health - Water
________________________________________
2. Analysis
Problem Statement: To accurately track and analyze daily water intake to ensure proper hydration and provide health feedback.
Data Requirements:
1.	Daily Water Consumption Data:
o	Data collection for each day of the week to monitor and analyze trends in water intake.
2.	Parameters for Healthy Water Intake:
o	Establishing a baseline for recommended daily water intake based on health guidelines.
o	Identifying thresholds for low, adequate, and high water consumption to provide relevant health feedback.
________________________________________
3. Ideate
Concepts:
1.	Recursive Function for Total Water Calculation:
o	Implementing a recursive function to sum up water consumption over a week.
2.	Input Validation:
o	Ensuring that user inputs for daily water consumption are valid (non-negative values).
________________________________________
4.Build
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
o	int main() {
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
________________________________________
5.Test

Output 
Enter the water consumption (in liters) for each day of the week:
Day 1: 2.5
Day 2: 1.8
Day 3: 2.0
Day 4: 3.1
Day 5: 2.7
Day 6: 1.9
Day 7: 2.2

Total water consumption for the week: 16.20 liters
Average daily water consumption: 2.31 liters

Health Feedback: Good job! Keep maintaining your water intake.

Invalid output

________________________________________
6. Implementation
Practical Application:
1.	Health and Fitness Applications:
o	The program can be integrated into mobile apps or wearable devices to help users track their daily water intake and receive personalized health feedback.
2.	Educational Tools:
o	Useful in educational settings to teach students about the importance of hydration and how to implement basic recursive functions in programming.
Challenges and Considerations:
1.	User Input Accuracy:
o	Ensuring that users input accurate water consumption values for meaningful analysis.
2.	Feedback Mechanism:
o	Providing relevant and actionable health feedback based on the calculated average water intake.
3.	Scalability:
o	Adapting the program to handle larger datasets or integrate with other health monitoring systems.
________________________________________

