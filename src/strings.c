#include <stdio.h>
#include <strings.h>

char *schr(const char *str, const char item)
{
    while(*str && *str != item) {
        ++str;
    }
    return (*str) ? (char *) str : NULL;
}

char *strstr(char *hstack, char *ndle)
{
  char *ndle_ptr = NULL, *hstack_ptr = NULL;
  int trigger_out = 1;
 
  if(hstack == NULL || ndle == NULL)
    
    return NULL;
 
  while(*hstack) {    
    if(*hstack == *ndle) {
      ndle_ptr = ndle;
      hstack_ptr = hstack;
 
      while(*ndle_ptr && *hstack_ptr) {
        trigger_out = trigger_out && (*ndle_ptr == *hstack_ptr);
      }
 
      if(trigger_out)
        return hstack;
    }
    ++hstack;
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