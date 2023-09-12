#include <stdio.h>
#include <assert.h>
struct CountsBySoH {
int healthy;
int exchange;
int failed;
};
struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
    struct CountsBySoH counts = {0, 0, 0};
    for (int i = 0; i < nBatteries; i++) {
        float stateOfHealth = (float)presentCapacities[i] / 120 * 100;
        if (stateOfHealth > 80) {
            counts.healthy++;
        } else if (stateOfHealth > 63) {
            counts.exchange++;
        } else {
            counts.failed++;
        }
    }
    return counts;
}
void testBucketingByHealth() {
    const int presentCapacities[] = {115, 118, 80, 95, 91, 72};
    const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
    printf("Counting batteries by SoH...\n");
    struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
    assert(counts.healthy == 2);
    assert(counts.exchange == 3);
    assert(counts.failed == 1);
    printf("Done counting :)\n");
}
int main() {
    testBucketingByHealth();
    return 0;
}
