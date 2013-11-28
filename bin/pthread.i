/* Simple model for functions from the Pthread library. */

typedef unsigned long int pthread_t;
typedef int __attribute__ ((__lock__)) pthread_mutex_t;
typedef int pthread_cond_t;
typedef void * pthread_attr_t;
typedef void * pthread_mutexattr_t;
typedef void * pthread_condattr_t;

int pthread_mutex_init(pthread_mutex_t *mutex,
		       const pthread_mutexattr_t *mutexattr) { 
  *mutex = 0; // The mutex is initially unlocked.
  return 0; 
}

int pthread_mutex_destroy(pthread_mutex_t *mutex) { 
  //  assert(*mutex==0); // the mutex must be unlocked
  return 0; 
}

int pthread_mutex_lock(pthread_mutex_t *mutex) { 
  { __blockattribute__((atomic))
    assume(*mutex==0);
    *mutex = 1;
  }
  return 0; 
}

int pthread_mutex_unlock(pthread_mutex_t *mutex) { 
  //  assert(*mutex==1);  // check that *mutex==1
  *mutex = 0;
  return 0; 
}

int pthread_attr_init(pthread_attr_t *attr) { 
  return 0; 
}

int pthread_cond_init(pthread_cond_t *cond,
		      const pthread_condattr_t *cond_attr) { 
  return 0; 
}

int pthread_cond_signal(pthread_cond_t *cond) { 
  return 0; 
}

int pthread_cond_broadcast(pthread_cond_t *cond) {
  return 0; 
}

int pthread_cond_wait(pthread_cond_t *cond,
		      pthread_mutex_t *mutex) {
  pthread_mutex_unlock(mutex);
  pthread_mutex_lock(mutex);
  return 0; 
}

int pthread_cond_destroy(pthread_cond_t *cond) {
  return 0; 
}

/* Additional functions that are interpreted by Threader:
int pthread_create(pthread_t *newthread,
		   const pthread_attr_t *attr,
		   void *(*start_routine) (void *),
		   void *arg, );

int pthread_join(pthread_t threadid, 
		 void **thread_return);

int pthread_kill(pthread_t threadid, 
		 int signo);
*/
