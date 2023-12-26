#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a tab
struct Tab {
    int tabID;
    char title[50];
    struct Tab *next;
};

// Function to create a new tab
struct Tab* createTab(int id, const char* title) {
    struct Tab* newTab = (struct Tab*)malloc(sizeof(struct Tab));
    newTab->tabID = id;
    strcpy(newTab->title, title);
    newTab->next = NULL;
    return newTab;
}

// Function to add a new tab at the end of the list
void addTab(struct Tab** head, int id, const char* title) {
    struct Tab* newTab = createTab(id, title);
    if (*head == NULL) {
        *head = newTab;
        return;
    }
    struct Tab* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newTab;
}

// Function to display all tabs
void displayTabs(struct Tab* head) {
    struct Tab* temp = head;
    while (temp != NULL) {
        printf("Tab ID: %d, Title: %s\n", temp->tabID, temp->title);
        temp = temp->next;
    }
}

// Function to free memory allocated for tabs
void freeTabs(struct Tab* head) {
    struct Tab* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Tab* tabs = NULL;

    // Adding tabs
    addTab(&tabs, 1, "Tab 1");
    addTab(&tabs, 2, "Tab 2");
    addTab(&tabs, 3, "Tab 3");

    // Displaying tabs
    printf("Tabs:\n");
    displayTabs(tabs);

    // Freeing memory
    freeTabs(tabs);

    return 0;
}
