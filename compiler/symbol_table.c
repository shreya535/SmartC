#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symbol_table.h"

Symbol table[MAX_SYMBOLS];
int    sym_count     = 0;
int    current_scope = 0;

void sym_init(){
    sym_count     = 0;
    current_scope = 0;
    memset(table, 0, sizeof(table));
    /* add common built-in functions */
    sym_declare("printf",   "builtin", 0, 1);
    sym_declare("scanf",    "builtin", 0, 1);
    sym_declare("malloc",   "builtin", 0, 1);
    sym_declare("free",     "builtin", 0, 1);
    sym_declare("strlen",   "builtin", 0, 1);
    sym_declare("strcpy",   "builtin", 0, 1);
    sym_declare("strcmp",   "builtin", 0, 1);
    sym_declare("strcat",   "builtin", 0, 1);
    sym_declare("fprintf",  "builtin", 0, 1);
    sym_declare("fopen",    "builtin", 0, 1);
    sym_declare("fclose",   "builtin", 0, 1);
    sym_declare("exit",     "builtin", 0, 1);
    sym_declare("atoi",     "builtin", 0, 1);
    sym_declare("atof",     "builtin", 0, 1);
    sym_declare("sprintf",  "builtin", 0, 1);
    sym_declare("memset",   "builtin", 0, 1);
    sym_declare("memcpy",   "builtin", 0, 1);
    sym_declare("abs",      "builtin", 0, 1);
    sym_declare("sqrt",     "builtin", 0, 1);
    sym_declare("pow",      "builtin", 0, 1);
}

void sym_enter_scope(){
    current_scope++;
}

void sym_exit_scope(){
    current_scope--;
}

int sym_declare(const char *name, const char *type, int line, int initialized){
    for(int i = 0; i < sym_count; i++){
        if(table[i].scope == current_scope &&
           strcmp(table[i].name, name) == 0 &&
           strcmp(table[i].type, "builtin") != 0){
            /* allow redeclaration if existing is a parameter (scope 0 issue) */
            if(strcmp(type, "builtin") == 0) return 0;
            /* update existing entry instead of reporting duplicate */
            table[i].initialized = initialized;
            table[i].line_declared = line;
            return 1;
        }
    }
    if(sym_count >= MAX_SYMBOLS) return 0;
    strncpy(table[sym_count].name, name, MAX_NAME-1);
    strncpy(table[sym_count].type, type, MAX_TYPE-1);
    table[sym_count].scope         = current_scope;
    table[sym_count].line_declared = line;
    table[sym_count].initialized   = initialized;
    table[sym_count].used          = 0;
    sym_count++;
    return 1;
}

int sym_lookup(const char *name){
    for(int s = current_scope; s >= 0; s--){
        for(int i = 0; i < sym_count; i++){
            if(table[i].scope == s &&
               strcmp(table[i].name, name) == 0){
                return i;
            }
        }
    }
    return -1;
}

void sym_mark_used(const char *name){
    int idx = sym_lookup(name);
    if(idx != -1) table[idx].used = 1;
}

void sym_mark_initialized(const char *name){
    int idx = sym_lookup(name);
    if(idx != -1) table[idx].initialized = 1;
}

void sym_check_unused(FILE *report){
    for(int i = 0; i < sym_count; i++){
        if(!table[i].used &&
           strcmp(table[i].type, "builtin") != 0 &&
           strcmp(table[i].type, "typedef") != 0 &&
           strcmp(table[i].type, "enum_const") != 0){
            printf("WARNING: '%s' declared at line %d but never used\n",
                   table[i].name, table[i].line_declared);
            if(report)
                fprintf(report,
                    "WARNING: '%s' declared at line %d but never used\n",
                    table[i].name, table[i].line_declared);
        }
    }
}

void sym_print(){
    printf("\n==============================================\n");
    printf("           SYMBOL TABLE\n");
    printf("==============================================\n");
    printf("%-20s %-10s %-6s %-6s %-5s\n",
           "Name","Type","Scope","Line","Init");
    printf("----------------------------------------------\n");
    for(int i = 0; i < sym_count; i++){
        printf("%-20s %-10s %-6d %-6d %-5s\n",
               table[i].name,
               table[i].type,
               table[i].scope,
               table[i].line_declared,
               table[i].initialized ? "yes" : "no");
    }
    printf("==============================================\n");
}