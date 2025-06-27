#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("planner.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int completedCourses;
    printf("1. How many courses are completed so far: ");
    scanf("%d", &completedCourses);
    fprintf(file, "Completed Courses: %d\n", completedCourses);

    char courseName[100];
    printf("2. What are their names:\n");
    getchar(); // clear newline from buffer
    for (int i = 0; i < completedCourses; i++) {
        printf("  Course %d: ", i + 1);
        fgets(courseName, sizeof(courseName), stdin);
        fprintf(file, "  Course %d: %s", i + 1, courseName);
    }

    char ongoingCourse[100];
    printf("3. What is the ongoing course you are doing (name): ");
    fgets(ongoingCourse, sizeof(ongoingCourse), stdin);
    fprintf(file, "Ongoing Course: %s", ongoingCourse);

    int doneClasses, totalClasses;
    printf("4. No. of classes done in it: ");
    scanf("%d", &doneClasses);
    printf("   Total no. of classes in it: ");
    scanf("%d", &totalClasses);
    fprintf(file, "Classes Done: %d / %d\n", doneClasses, totalClasses);

    int detailedTopics;
    printf("5. How many topics you have completed in detailed revision: ");
    scanf("%d", &detailedTopics);
    fprintf(file, "Detailed Topics Completed: %d\n", detailedTopics);

    printf("6. Name of those topics:\n");
    getchar(); // clear newline from buffer
    for (int i = 0; i < detailedTopics; i++) {
        printf("  Topic %d: ", i + 1);
        fgets(courseName, sizeof(courseName), stdin);
        fprintf(file, "  Topic %d: %s", i + 1, courseName);
    }

    int fastRevTopics;
    printf("7. How many of the topics you have completed in fast-paced revision: ");
    scanf("%d", &fastRevTopics);
    fprintf(file, "Fast-paced Topics Completed: %d\n", fastRevTopics);

    fclose(file);
    printf("Data saved to planner.txt successfully.\n");

    return 0;
}
