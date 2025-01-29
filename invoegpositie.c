#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target) {
   //Vul hier jouw code in

}

// Testfunctie
void runTests() {
    struct TestCase {
        int nums[10]; // Maximale grootte voor testcases
        int size;
        int target;
        int expected;
    };

    struct TestCase testCases[] = {
        {{1, 3, 5, 6}, 4, 5, 2},  // Doelwaarde zit in de array
        {{1, 3, 5, 6}, 4, 2, 1},  // Doelwaarde zou op index 1 moeten worden ingevoegd
        {{1, 3, 5, 6}, 4, 7, 4},  // Doelwaarde komt achteraan
        {{1, 3, 5, 6}, 4, 0, 0},  // Doelwaarde komt vooraan
        {{1}, 1, 0, 0},           // Enkelvoudige element test (voor de waarde)
        {{1}, 1, 2, 1},           // Enkelvoudige element test (achter de waarde)
        {{1, 2, 4, 6, 8, 10}, 6, 3, 2},  // Tussen twee getallen
        {{1, 3, 5, 7, 9}, 5, 6, 3}       // Getal past tussen 5 en 7
    };

    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    int passed = 0;

    for (int i = 0; i < numTests; i++) {
        struct TestCase test = testCases[i];
        int result = searchInsert(test.nums, test.size, test.target);
        if (result == test.expected) {
            printf("✅ Test %d geslaagd: target = %d, verwacht = %d, output = %d\n", 
                   i + 1, test.target, test.expected, result);
            passed++;
        } else {
            printf("❌ Test %d mislukt: target = %d, verwacht = %d, output = %d\n", 
                   i + 1, test.target, test.expected, result);
        }
    }

    printf("\nTests voltooid: %d/%d geslaagd\n", passed, numTests);
}

int main() {
    runTests();
    return 0;
}