#include <stdio.h>
#include <string.h>
#define MAX_ELEMENTS 118

struct Element
{
    char name[50];
    char symbol[3];
    int atomicNumber;
    float atomicWeight;
    char typeofelement[50];
};

void displayMenu();
void addElement(struct Element *elements, int *elementCount);
void exploreElements(struct Element *elements, int *elementCount);
void searchByName(const struct Element *elements, int elementCount);
void searchBySymbol(const struct Element *elements, int elementCount);
void searchByAtomicNumber(const struct Element *elements, int elementCount);
void searchByAtomicWeight(const struct Element *elements, int elementCount);

int main()
{
    struct Element periodicTable[MAX_ELEMENTS];
    int elementCount = 0;
    int choice;

    do
    {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addElement(periodicTable, &elementCount);
            break;
        case 2:
            exploreElements(periodicTable, &elementCount);
            break;
        case 3:
            printf("Exiting the Periodic Table Generator. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

void displayMenu()
{
    printf("\n");
    printf("             Periodic Table Generator         \n");
    printf("    **********************************************     \n");
    printf("           Enter the corresponding number:\n");
    printf("           1. Add New Element Information\n");
    printf("           2. Explore\n");
    printf("           3. Quit\n                     ");
}

void addElement(struct Element *elements, int *elementCount)
{
    if (*elementCount == MAX_ELEMENTS)
    {
        printf("Cannot add more elements. The maximum limit is reached.\n");
        return;
    }

    struct Element newElement;
    FILE *file = fopen("elements.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    printf("Enter the following information for the new element:\n");
    printf("Name: ");
    scanf("%s", newElement.name);
    printf("Symbol: ");
    scanf("%s", newElement.symbol);
    printf("Atomic Number: ");
    scanf("%d", &newElement.atomicNumber);
    printf("Atomic Weight: ");
    scanf("%f", &newElement.atomicWeight);
    printf("Type of element: ");
    scanf("%s", newElement.typeofelement);

    fprintf(file, "%s %s %d %.3f %s\n", newElement.name, newElement.symbol,
            newElement.atomicNumber, newElement.atomicWeight, newElement.typeofelement);
    fclose(file);

    printf("Element added successfully!\n");
    elements[*elementCount] = newElement;
    (*elementCount)++;
}

void exploreElements(struct Element *elements, int *elementCount)
{
    int exploreChoice;
    do
    {
        printf("\nPeriodic Table Generator\n");
        printf("\n");
        printf("Enter the corresponding Number:\n");
        printf("1. Search by Name\n");
        printf("2. Search by Symbol\n");
        printf("3. Search by Atomic Number\n");
        printf("4. Search by Atomic Weight\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &exploreChoice);

        switch (exploreChoice)
        {
        case 1:
            searchByName(elements, *elementCount);
            break;
        case 2:
            searchBySymbol(elements, *elementCount);
            break;
        case 3:
            searchByAtomicNumber(elements, *elementCount);
            break;
        case 4:
            searchByAtomicWeight(elements, *elementCount);
            break;
        case 5:
            printf("Returning to the main menu.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (exploreChoice != 5);
}

void searchByName(const struct Element *elements, int elementCount)
{
    char searchName[50];
    printf("Enter the name of the element: ");
    scanf("%s", searchName);
    int found = 0;

    FILE *file = fopen("elements.txt", "r");
    if (file != NULL)
    {
        while (fscanf(file, "%s %s %d %f %s", elements[elementCount].name, elements[elementCount].symbol,
                      &elements[elementCount].atomicNumber, &elements[elementCount].atomicWeight, elements[elementCount].typeofelement) == 5)
        {
            if (strcmp(elements[elementCount].name, searchName) == 0)
            {
                printf("\nName: %s\nSymbol: %s\nAtomic Number: %d\nAtomic Weight: %.3f\nType of element: %s\n",
                       elements[elementCount].name, elements[elementCount].symbol, elements[elementCount].atomicNumber,
                       elements[elementCount].atomicWeight, elements[elementCount].typeofelement);
                found = 1;
                break;
            }
        }
        fclose(file);
    }

    if (found != 1)
    {
        printf("Element not found.\n");
    }
}

void searchBySymbol(const struct Element *elements, int elementCount)
{
    char searchSymbol[3];
    printf("Enter the symbol of the element: ");
    scanf("%s", searchSymbol);
    int found = 0;

    FILE *file = fopen("elements.txt", "r");
    if (file != NULL)
    {
        while (fscanf(file, "%s %s %d %f %s", elements[elementCount].name, elements[elementCount].symbol,
                      &elements[elementCount].atomicNumber, &elements[elementCount].atomicWeight, elements[elementCount].typeofelement) == 5)
        {
            if (strcmp(elements[elementCount].symbol, searchSymbol) == 0)
            {
                printf("\nName: %s\nSymbol: %s\nAtomic Number: %d\nAtomic Weight: %.3f\nType of element: %s\n",
                       elements[elementCount].name, elements[elementCount].symbol, elements[elementCount].atomicNumber,
                       elements[elementCount].atomicWeight, elements[elementCount].typeofelement);
                found = 1;
                break;
            }
        }
        fclose(file);
    }

    if (found != 1)
    {
        printf("Element not found.\n");
    }
}

void searchByAtomicNumber(const struct Element *elements, int elementCount)
{
    int searchAtomicNumber;
    printf("Enter the atomic number of the element: ");
    scanf("%d", &searchAtomicNumber);
    int found = 0;

    FILE *file = fopen("elements.txt", "r");
    if (file != NULL)
    {
        while (fscanf(file, "%s %s %d %f %s", elements[elementCount].name, elements[elementCount].symbol,
                      &elements[elementCount].atomicNumber, &elements[elementCount].atomicWeight, elements[elementCount].typeofelement) == 5)
        {
            if (elements[elementCount].atomicNumber == searchAtomicNumber)
            {
                printf("\nName: %s\nSymbol: %s\nAtomic Number: %d\nAtomic Weight: %.3f\nType of element: %s\n",
                       elements[elementCount].name, elements[elementCount].symbol, elements[elementCount].atomicNumber,
                       elements[elementCount].atomicWeight, elements[elementCount].typeofelement);
                found = 1;
                break;
            }
        }
        fclose(file);
    }

    if (found != 1)
    {
        printf("Element not found.\n");
    }
}

void searchByAtomicWeight(const struct Element *elements, int elementCount)
{
    float searchAtomicWeight;
    printf("Enter the atomic weight of the element: ");
    scanf("%f", &searchAtomicWeight);
    int found = 0;

    FILE *file = fopen("elements.txt", "r");
    if (file != NULL)
    {
        while (fscanf(file, "%s %s %d %f %s", elements[elementCount].name, elements[elementCount].symbol,
                      &elements[elementCount].atomicNumber, &elements[elementCount].atomicWeight, elements[elementCount].typeofelement) == 5)
        {
            if (elements[elementCount].atomicWeight == searchAtomicWeight)
            {
                printf("\nName: %s\nSymbol: %s\nAtomic Number: %d\nAtomic Weight: %.3f\nType of element: %s\n",
                       elements[elementCount].name, elements[elementCount].symbol, elements[elementCount].atomicNumber,
                       elements[elementCount].atomicWeight, elements[elementCount].typeofelement);
                found = 1;
                break;
            }
        }
        fclose(file);
    }

    if (found != 1)
    {
        printf("Element not found.\n");
    }
}
