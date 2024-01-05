#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Task {
    char description[100];
    int completed;
};


void addTask(struct Task tasks[], int *taskCount);
void displayTasks(struct Task tasks[], int taskCount);
void markTaskAsCompleted(struct Task tasks[], int taskCount);
void removeTask(struct Task tasks[], int *taskCount);

int main() {
    struct Task tasks[100]; 
    int taskCount = 0; 

    int choice;

    do {
        printf("\nTo-Do List Uygulamasi\n");
        printf("1. Yeni Gorev Ekle\n");
        printf("2. Gorevleri Goruntule\n");
        printf("3. Gorevi Tamamlandi Olarak Isaretle\n");
        printf("4. Gorevi Sil\n");
        printf("0. Cikis\n");

        printf("Seciminizi yapin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                displayTasks(tasks, taskCount);
                break;
            case 3:
                markTaskAsCompleted(tasks, taskCount);
                break;
            case 4:
                removeTask(tasks, &taskCount);
                break;
            case 0:
                printf("Cikis yapiliyor...\n");
                break;
            default:
                printf("Gecersiz secim. Tekrar deneyin.\n");
        }
    } while (choice != 0);

    return 0;
}

void addTask(struct Task tasks[], int *taskCount) {
    if (*taskCount < 100) {
        printf("Yeni gorevi girin: ");
        scanf(" %[^\n]", tasks[*taskCount].description);
        tasks[*taskCount].completed = 0; 
        (*taskCount)++;
        printf("Gorev eklendi.\n");
    } else {
        printf("Maksimum gorev sayisina ulasildi.\n");
    }
}

void displayTasks(struct Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("Gorev bulunmamaktadir.\n");
    } else {
        printf("Gorevler:\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d. %s %s\n", i + 1, tasks[i].description,
                   tasks[i].completed ? "[Tamamlandi]" : "");
        }
    }
}

void markTaskAsCompleted(struct Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("Gorev bulunmamaktadir.\n");
    } else {
        int taskIndex;
        printf("Tamamlandi olarak isaretlemek istediginiz gorevin numarasini girin: ");
        scanf("%d", &taskIndex);

        if (taskIndex > 0 && taskIndex <= taskCount) {
            tasks[taskIndex - 1].completed = 1;
            printf("Gorev tamamlandi olarak isaretlendi.\n");
        } else {
            printf("Gecersiz gorev numarasi.\n");
        }
    }
}

void removeTask(struct Task tasks[], int *taskCount) {
    if (*taskCount == 0) {
        printf("Silinecek gorev bulunmamaktadir.\n");
    } else {
        int taskIndex;
        printf("Silmek istediginiz gorevin numarasini girin: ");
        scanf("%d", &taskIndex);

        if (taskIndex > 0 && taskIndex <= *taskCount) {
            
            for (int i = taskIndex - 1; i < *taskCount - 1; i++) {
                tasks[i] = tasks[i + 1];
            }

            (*taskCount)--;
            printf("Gorev silindi.\n");
        } else {
            printf("Gecersiz gorev numarasi.\n");
        }
    }
}
