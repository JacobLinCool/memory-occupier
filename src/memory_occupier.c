#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define MB (1024 * 1024 / sizeof(uint64_t))
#define BLOCK_MAX (1024 * 64)

typedef struct Block {
    uint64_t data[MB];
} Block;

int main(int argc, char* argv[]) {
    srand(time(NULL));

    Block* blocks[BLOCK_MAX] = { 0 };
    size_t size = 0;

    if (argc == 2) {
        int sz = atoi(argv[1]);
        for (int i = 0; i < sz && size < BLOCK_MAX; i++) {
            blocks[size] = malloc(sizeof(Block));
            for (size_t j = 0; j < MB; j++) {
                blocks[size]->data[j] = rand();
            }
            size++;
        }
    }


    printf("PID: %d\n", getpid());
    printf("add <size>     : Occupy <size> MB of memory\n");
    printf("release <size> : Release <size> MB of memory\n");
    printf("quit           : Quit\n");

    bool keep = true;
    while (keep) {
        printf("Memory Occupied: %zu MB\n", size);

        char* command = malloc(sizeof(char) * 1024);
        scanf("%s", command);

        switch (command[0]) {
        case 'a': {
            int sz = 0;
            scanf("%d", &sz);
            for (int i = 0; i < sz && size < BLOCK_MAX; i++) {
                blocks[size] = malloc(sizeof(Block));
                for (size_t j = 0; j < MB; j++) {
                    blocks[size]->data[j] = rand();
                }
                size++;
            }
            break;
        }
        case 'r': {
            int sz = 0;
            scanf("%d", &sz);
            for (int i = 0; i < sz && size > 0; i++) {
                free(blocks[size - 1]);
                size--;
            }
            break;
        }
        case 'q': {
            while (size > 0) {
                free(blocks[size - 1]);
                size--;
            }
            keep = false;
            break;
        }
        default:
            printf("Unknown command\n");
            break;
        }

        free(command);
    }

    return EXIT_SUCCESS;
}
