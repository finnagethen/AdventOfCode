#include "../utils.h"

int cmp(const int* a, const int* b) {
    return *a - *b;
}

void part1(int* nums_left, int* nums_right, size_t nums_size) {
    qsort(nums_left, nums_size, sizeof(int), (int (*)(const void *, const void *))cmp);
    qsort(nums_right, nums_size, sizeof(int), (int (*)(const void *, const void *))cmp);

    int dist_sum = 0;
    for (size_t i = 0; i < nums_size; i++) {
        dist_sum += abs(nums_left[i] - nums_right[i]);
    }

    printf("%d\n", dist_sum);
}

void part2(int* nums_left, int* nums_right, size_t nums_size) {
    // assume nums_left and nums_right are sorted because of part 1
    int total_simularity = 0;

    for (size_t i = 0; i < nums_size; i++) {
        int cnt = 0;
        for (size_t j = 0; j < nums_size; j++) {
            if (nums_left[i] < nums_right[j]) {
                total_simularity += cnt * nums_left[i];
                break;
            }
            if (nums_left[i] == nums_right[j]) {
                cnt++;
            }
        }
    }

    printf("%d\n", total_simularity);
}

void solution() {
    TIMER_START;

    FILE* file = fopen("../day1/input.txt", "r");
    assert(file);

    constexpr size_t nums_max_size = 1024;
    size_t nums_size = 0;
    int nums_left[nums_max_size];
    int nums_right[nums_max_size];

    constexpr size_t line_buffer_size = 128;
    char line_buffer[line_buffer_size];

    while (fgets(line_buffer, line_buffer_size, file) != nullptr) {
        int left, right;
        sscanf(line_buffer, "%d %d", &left, &right);
        nums_left[nums_size] = left;
        nums_right[nums_size] = right;
        nums_size += 1;
    }
    
    fclose(file);

    printf("-- Part 1 --\n\t");
    part1(nums_left, nums_right, nums_size);

    printf("-- Part 2 --\n\t");
    part2(nums_left, nums_right, nums_size);

    TIMER_STOP;
}