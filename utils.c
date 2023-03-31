#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process_manager.h"

/* Read processes from file into an array */
void read_file(char *filename, process *processes_list){
    FILE *file_ptr;

    file_ptr = fopen(filename, "r");
    if (file_ptr==NULL){
        printf("File not found\n");
        exit(1);
    }

    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    int n = 0;
    while ((linelen = getline(&line, &linecap, file_ptr)) > 0){
        int time_arrived = atoi(strtok(line, " "));
        char *process_name = strtok(NULL, " ");
        int service_time = atoi(strtok(NULL, " "));
        int memory_requirement = atoi(strtok(NULL, " "));

        process process_from_file;
        process_from_file.time_arrived = time_arrived;
        strcpy(process_from_file.process_name, process_name);
        process_from_file.service_time = service_time;
        process_from_file.memory_requirement = memory_requirement;

        processes_list[n] = process_from_file;
        n++;
    }

    fclose(file_ptr);
}