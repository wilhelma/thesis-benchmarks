#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mx;
int x=0;

void *thread1() {
	pthread_mutex_lock(&mx);
	x=x+1;
	x=x+1;
	x=x+1;
	x=x+1;
	x=x+1;
	x=x+1;
	x=x+1;
	x=x+1;
	x=x+1;
	x=x+1;	
	pthread_mutex_unlock(&mx);
	return 0;
}

void *thread2() {
	pthread_mutex_lock(&mx);
	x=x-1;
	x=x-1;
	x=x-1;
	x=x-1;
	x=x-1;
	x=x-1;
	x=x-1;
	x=x-1;
	x=x-1;
	x=x-1;
	pthread_mutex_unlock(&mx);
	return 0;
}

void *thread3() {
	int a = x;
	return 0;
}

int main() {
  pthread_t t1, t2, t3;
  pthread_mutex_init(&mx, 0);
  pthread_create(&t1, 0, thread1, 0);
  pthread_create(&t2, 0, thread2, 0);
  pthread_create(&t3, 0, thread3, 0);
  pthread_join(t1, 0);
  pthread_join(t2, 0);
  pthread_join(t3, 0);
  assert(x!=1);
  pthread_mutex_destroy(&mx);
  return 0;
}

// Threader-OG '-no-main': 'program is correct', 9.91s
