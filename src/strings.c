#include <stdio.h>
#include <strings.h>

int slen(const char *str) 
{   
    int length = 0;
    
    while(*str != '\0') {
        ++length;
        ++str;
    }
    return length;
}

char *schr(const char *str, const char item)
{
    while(*str && *str != item) {
        ++str;
    }
    return (*str) ? (char *) str : NULL;
}

const char *strstr(char *hstack, char *ndle)
{
  if(hstack == NULL || ndle == NULL) {
    return NULL;    
  }

  while(*hstack) {
    while(hstack != ndle) {
      ++hstack;
    }
    return hstack;              
  }
  return NULL;
}

char *sstok(char *str, const char *delim) 
{
    static char *buffer;
    
    if(str) {
        buffer = str;
        while(*buffer && schr(delim, *buffer)) {
            *buffer++ = '\0';
        }
    }
    
    if(! *buffer) {
        return NULL;
    }
    
    str = buffer;
     
    while(*buffer && ! schr(delim, *buffer)) {
        ++buffer;
    }
    while(*buffer && schr(delim, *buffer)) {
        *buffer++ = '\0';
    }
    
    return str;
}

int scmp(const char *bhind, const char *abve)
{
    while (*bhind && *abve && *bhind == *abve) {
        ++bhind, ++abve;   
    }
    return *bhind - *abve;
}

char *scpy(char *n_str, const char *i_str)
{
    while(*i_str) {
        *n_str++ = *i_str++;    
    } 
    *n_str++ = '\0';
    
    return n_str;
}