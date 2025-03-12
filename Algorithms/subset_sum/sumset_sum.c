#include <stdio.h>
#include <time.h>
#include "subset_sum.h"


int main(void)
{
    int S1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33};
    int t1 = 540;
    int n1 = 33;

    int S2[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40};
    int t2 = 390;
    int n2 = 20;

    int S3[] = {1, 2, 4, 5, 7, 8, 11, 13, 14, 15, 21, 55, 99, 111, 128, 200, 210, 230, 300, 333};
    int t3 = 444;
    int n3 = 20;


    clock_t start, end;
    double cpu_time_used;

    printf("Test case 1\n");
    start = clock();
    printf("Number of subsets DP: %d\n", subsetSumDP(S1, t1, n1));
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", cpu_time_used);

    start = clock();
    printf("Number of subsets Brute: %d\n", subsetSumBrute(S1, t1, n1));
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", cpu_time_used);


    printf("Test case 2\n");
    start = clock();
    printf("Number of subsets DP: %d\n", subsetSumDP(S2, t2, n2));
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", cpu_time_used);

    start = clock();
    printf("Number of subsets Brute: %d\n", subsetSumBrute(S2, t2, n2));
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", cpu_time_used);


    printf("Test case 3\n");
    start = clock();
    printf("Number of subsets DP: %d\n", subsetSumDP(S3, t3, n3));
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", cpu_time_used);

    start = clock();
    printf("Number of subsets Brute: %d\n", subsetSumBrute(S3, t3, n3));
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", cpu_time_used);

    return 0;
}