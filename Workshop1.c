#include <stdio.h>    // em không nộp được file .c lên edunext nên em gửi link github ạ, nếu có vấn đề gì thì em mong cô sẽ gửi mail cho e qua phamanh8084@gmail.com em cảm ơn ạ 

int main() {
    int n, i;
    float score, total = 0;
    int passCount = 0, failCount = 0;
  
    do {
        printf("Enter the number of students (>=1): ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Invalid number of student. Please try again.\n");
        }
    } while (n <= 0);


    for (i = 0; i < n; i++) {
        do {
            printf("Enter the score of student %d (0-10): ", i + 1);
            scanf("%f", &score);
            if (score < 0 || score > 10) {
                printf("Invalid score. Please enter again.\n");
            }
        } while (score < 0 || score > 10);


        total += score;


        if (score >= 5) {
            passCount++;
        } else {
            failCount++;
        }
    }


    printf("\nStatistics:\n");
    printf("Total score of the class: %.0f\n", total);
    printf("Average score of the class: %.2f\n", total / n);
    printf("Number of students who passed (>=5): %d\n", passCount);
    printf("Number of students who failed (< 5): %d\n", failCount);

    system("pause");
    return 0;
}
