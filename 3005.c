#include <stdio.h>

int main(void) {
    int freq[101] = {0};

    int numsSize;
    scanf("%d", &numsSize);

    int temp = 0;
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &temp);
        freq[temp]++;
    }

    int max_freq = 0;
    for (int i = 0; i < 101; i++) max_freq = max_freq > freq[i] ? max_freq : freq[i];

    int sum = 0;
    for (int i = 0; i < 101; i++) 
        if (max_freq == freq[i]) sum += max_freq;

    printf("%d", sum);
}