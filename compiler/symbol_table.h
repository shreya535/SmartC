#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAX_SYMBOLS 1000
#define MAX_NAME    64
#define MAX_TYPE    32

typedef struct {
    char name[MAX_NAME];
    char type[MAX_TYPE];
    int  scope;
    int  line_declared;
    int  initialized;
    int  used;
} Symbol;

void sym_init();
void sym_enter_scope();
void sym_exit_scope();
int  sym_declare(const char *name, const char *type, int line, int initialized);
int  sym_lookup(const char *name);
void sym_mark_used(const char *name);
void sym_mark_initialized(const char *name);
void sym_check_unused(FILE *report);
void sym_print();

extern Symbol table[MAX_SYMBOLS];
extern int    sym_count;
extern int    current_scope;

#endif