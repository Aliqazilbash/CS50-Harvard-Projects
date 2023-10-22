#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a person
typedef struct Person {
    struct Person* parents[2];
    char alleles[2];
} Person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

// Function prototypes
Person* create_family(int generations);
void print_family(Person* p, int generation);
void free_family(Person* p);
char random_allele();

int main(void) {
    // Seed the random number generator
    srand(time(0));

    // Create a new family with three generations
    Person* p = create_family(GENERATIONS);

    // Print the family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with 'generations'
Person* create_family(int generations) {
    // Allocate memory for a new person
    Person* n = malloc(sizeof(Person));
    if (n == NULL) {
        return NULL;
    }

    // If there are still generations left to create
    if (generations > 1) {
        // Create two new parents for the current person by recursively calling create_family
        n->parents[0] = create_family(generations - 1);
        n->parents[1] = create_family(generations - 1);

        // Set parent pointers for the current person
        n->alleles[0] = n->parents[0]->alleles[rand() % 2];
        n->alleles[1] = n->parents[1]->alleles[rand() % 2];
    } else {
        // Set parent pointers to NULL
        n->parents[0] = NULL;
        n->parents[1] = NULL;

        // Randomly assign alleles
        n->alleles[0] = random_allele();
        n->alleles[1] = random_allele();
    }

    return n;
}

// Free 'p' and all ancestors of 'p'
void free_family(Person* p) {
    // Handle the base case
    if (p == NULL) {
        return;
    }

    // Free parents recursively
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // Free the current person
    free(p);
}

// Print each family member and their alleles
void print_family(Person* p, int generation) {
    // Handle the base case
    if (p == NULL) {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++) {
        printf(" ");
    }

    // Determine the person's role based on generation
    const char* role;
    if (generation == 0) {
        role = "Child";
    } else if (generation == 1) {
        role = "Parent";
    } else {
        role = "Grandparent";
        for (int i = 0; i < generation - 2; i++) {
            printf("Great-");
        }
    }

    // Print person's information
    printf("%s (Generation %i): blood type %c%c\n", role, generation, p->alleles[0], p->alleles[1]);

    // Print parents of the current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly choose a blood type allele
char random_allele() {
    int r = rand() % 3;
    if (r == 0) {
        return 'A';
    } else if (r == 1) {
        return 'B';
    } else {
        return 'O';
    }
}
