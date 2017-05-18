#ifndef STRINGS_H
#define STRINGS_H

int slen(const char *str);
char *schr(const char *str, const char item);
char *strstr(char *hstack, char *ndle);
char *sstok(char *str, const char *delim); 
int scmp(const char *bhind, const char *abve);
char *scpy(char *n_str, const char *i_str);

#endif//STRINGS H