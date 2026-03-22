#ifndef FIX_ENGINE_H
#define FIX_ENGINE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES    10000
#define MAX_LINE_LEN 512
#define MAX_FIXES    100
#define MAX_ERRORS   100

typedef struct {
    int  line_num;
    char type[64];
    char description[256];
} Error;

typedef struct {
    int  line_num;
    char description[256];
    char fixed_line[MAX_LINE_LEN];
} Fix;

extern Error errors[MAX_ERRORS];
extern int   error_count;

extern Fix   fixes[MAX_FIXES];
extern int   fix_count;
extern int   error_count;
extern int   warning_count;
extern FILE *report;

void fix_engine_run(const char *source_file,
                    const char *report_file,
                    const char *output_file);

void fix_engine_print_report();

#endif