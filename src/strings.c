#include <stdio.h>

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