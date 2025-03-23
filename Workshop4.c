#include <stdio.h>
#include <stdlib.h>

// Constants
#define MAX_DAYS 100

// Struct definition
typedef struct {
    int sales[MAX_DAYS];
    int days[MAX_DAYS];
    int count;
} SalesData;

// Function prototypes
SalesData inputSales();
void displaySales(SalesData data);
void sortAscending(SalesData data);
void sortDescending(SalesData data);
void searchGreaterThan(SalesData data, int target);

int main() {
    SalesData data;
    int choice, target;

    do {
        printf("\n=== Enhanced Sales Data Management Menu ===\n");
        printf("1. Input Sales Data\n");
        printf("2. Display Sales Data\n");
        printf("3. Sort Sales Data in Ascending Order\n");
        printf("4. Sort Sales Data in Descending Order\n");
        printf("5. Search for Sales Greater Than a Target\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                data = inputSales();
                break;
            case 2:
                if (data.count == 0) {
                    printf("No data available.\n");
                } else {
                    displaySales(data);
                }
                break;
            case 3:
                if (data.count == 0) {
                    printf("No data available.\n");
                } else {
                    sortAscending(data);
                }
                break;
            case 4:
                if (data.count == 0) {
                    printf("No data available.\n");
                } else {
                    sortDescending(data);
                }
                break;
            case 5:
                if (data.count == 0) {
                    printf("No data available.\n");
                } else {
                    printf("Enter the target sales value: ");
                    scanf("%d", &target);
                    searchGreaterThan(data, target);
                }
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    system("pause");
    return 0;
}

SalesData inputSales() {
    SalesData data;
    int n;

    do {
        printf("Enter the number of days (1-100): ");
        scanf("%d", &n);
        if (n < 1 || n > MAX_DAYS) {
            printf("Invalid number of days! Please try again.\n");
        }
    } while (n < 1 || n > MAX_DAYS);

    data.count = n;

    printf("Enter sales data for %d days:\n", n);
    for (int i = 0; i < n; i++) {
        data.days[i] = i + 1;
        printf("Day %d (Sales Value): ", data.days[i]);
        scanf("%d", &data.sales[i]);
    }

    return data;
}

void displaySales(SalesData data) {
    printf("\nSales data:\n");
    for (int i = 0; i < data.count; i++) {
        printf("Day %d: %d\n", data.days[i], data.sales[i]);
    }
}

void sortAscending(SalesData data) {
    int tempDays[MAX_DAYS], tempSales[MAX_DAYS];

    for (int i = 0; i < data.count; i++) {
        tempDays[i] = data.days[i];
        tempSales[i] = data.sales[i];
    }

    for (int i = 0; i < data.count - 1; i++) {
        for (int j = 0; j < data.count - i - 1; j++) {
            if (tempSales[j] > tempSales[j + 1]) {
                int tmpSale = tempSales[j];
                tempSales[j] = tempSales[j + 1];
                tempSales[j + 1] = tmpSale;

                int tmpDay = tempDays[j];
                tempDays[j] = tempDays[j + 1];
                tempDays[j + 1] = tmpDay;
            }
        }
    }

    printf("Sales data sorted in ascending order:\n");
    for (int i = 0; i < data.count; i++) {
        printf("Day %d: %d\n", tempDays[i], tempSales[i]);
    }
}

void sortDescending(SalesData data) {
    int tempDays[MAX_DAYS], tempSales[MAX_DAYS];

    for (int i = 0; i < data.count; i++) {
        tempDays[i] = data.days[i];
        tempSales[i] = data.sales[i];
    }

    for (int i = 0; i < data.count - 1; i++) {
        for (int j = 0; j < data.count - i - 1; j++) {
            if (tempSales[j] < tempSales[j + 1]) {
                int tmpSale = tempSales[j];
                tempSales[j] = tempSales[j + 1];
                tempSales[j + 1] = tmpSale;

                int tmpDay = tempDays[j];
                tempDays[j] = tempDays[j + 1];
                tempDays[j + 1] = tmpDay;
            }
        }
    }

    printf("Sales data sorted in descending order:\n");
    for (int i = 0; i < data.count; i++) {
        printf("Day %d: %d\n", tempDays[i], tempSales[i]);
    }
}

void searchGreaterThan(SalesData data, int target) {
    int indices[MAX_DAYS], filteredCount = 0;

    for (int i = 0; i < data.count; i++) {
        if (data.sales[i] > target) {
            indices[filteredCount++] = i;
        }
    }

    for (int i = 0; i < filteredCount - 1; i++) {
        for (int j = i + 1; j < filteredCount; j++) {
            if (data.sales[indices[i]] < data.sales[indices[j]]) {
                int tmp = indices[i];
                indices[i] = indices[j];
                indices[j] = tmp;
            }
        }
    }

    printf("Sales values greater than %d:\n", target);
    for (int i = 0; i < filteredCount; i++) {
        printf("Day %d: %d\n", data.days[indices[i]], data.sales[indices[i]]);
    }
}
