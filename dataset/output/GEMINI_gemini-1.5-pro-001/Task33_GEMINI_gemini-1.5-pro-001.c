#include <stdio.h>
#include <stdlib.h>

int find_min_index(int arr[], int len) {
    int min_index = 0;
    for (int i = 1; i < len; i++) {
        if (arr[i] < arr[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

int solve_super_market_queue(int customers[], int num_customers, int n) {
    if (num_customers == 0) return 0;
    if (num_customers <= n) {
        int max_time = customers[0];
        for (int i = 1; i < num_customers; i++) {
            if (customers[i] > max_time) {
                max_time = customers[i];
            }
        }
        return max_time;
    }

    int tills[n];
    for (int i = 0; i < n; i++) {
        tills[i] = 0;
    }
    int customer_index = 0;
    for (int i = 0; i < n; i++) {
        tills[i] = customers[customer_index];
        customer_index++;
    }

    while (customer_index < num_customers) {
        int next_till = find_min_index(tills, n);
        tills[next_till] += customers[customer_index];
        customer_index++;
    }

    int max_time = tills[0];
    for (int i = 1; i < n; i++) {
        if (tills[i] > max_time) {
            max_time = tills[i];
        }
    }
    return max_time;
}