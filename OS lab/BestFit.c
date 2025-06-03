#include <stdio.h>

void bestFit(int blockSize[], int m, int fileSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= fileSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= fileSize[i];
        }
    }

    printf("\nFile Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("File Size %d is put in Block %d\n", fileSize[i], allocation[i] + 1);
        else
            printf("File Size %d must Wait\n", fileSize[i]);
    }
}

int main() {
    int m, n;
    
    printf("Enter the number of blocks: ");
    scanf("%d", &m);
    int blockSize[m];

    printf("Enter the size of the blocks:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of files: ");
    scanf("%d", &n);
    int fileSize[n];

    printf("Enter the size of the files:\n");
    for (int i = 0; i < n; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &fileSize[i]);
    }

    bestFit(blockSize, m, fileSize, n);

    return 0;
}
