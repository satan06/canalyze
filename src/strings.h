#ifndef STRINGS_H
#define STRINGS_H

char *schr(const char *str, const char item);
char *strstr(char *hstack, char *ndle);
char *sstok(char *str, const char *delim); 
int scmp(const char *bhind, const char *abve);

#endif//STRINGS H