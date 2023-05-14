typedef int myth_t;
myth_t myth_create(myth_t *thread, void *(*fn) (void *), void *arg);
myth_t myth_join(myth_t thread);
void myth_exit(void *retVal);