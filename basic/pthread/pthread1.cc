#include <pthread.h>
int pthread_create(pthread_t *restrict tidp,
                      const pthread_attr_t *restrict attr,
                      void *(*start_rtn) (void *),
                      voif *restrict arg);
int main()
{
  return 0;
}
