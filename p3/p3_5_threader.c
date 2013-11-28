#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mx, my;
int x=2, y=2;

void *thread1() {
	int a;
	pthread_mutex_lock(&mx);
	a = x;
	pthread_mutex_lock(&my);
	y = y + a;
	y = y + a;
	y = y + a;
	y = y + a;
	y = y + a;
	pthread_mutex_unlock(&my);
	a = a + 1;		
	pthread_mutex_lock(&my);
	y = y + a;
	y = y + a;
	y = y + a;
	y = y + a;
	y = y + a;
	pthread_mutex_unlock(&my);
	x = x + x + a;
	pthread_mutex_unlock(&mx);
	assert(x!=27);
	return 0;
}

void *thread2() {
	pthread_mutex_lock(&mx);
	x=x+2;
	x=x+2;
	x=x+2;
	x=x+2;
	x=x+2;
	pthread_mutex_unlock(&mx);
	return 0;
}

void *thread3() {
	pthread_mutex_lock(&my);
	y=y+2;
	y=y+2;
	y=y+2;
	y=y+2;
	y=y+2;
	pthread_mutex_unlock(&my);
	y=2; // added to create a race
	return 0;
}

int main() {
  pthread_t t1, t2, t3;
  pthread_mutex_init(&mx, 0);
  pthread_mutex_init(&my, 0);
  pthread_create(&t1, 0, thread1, 0);
  pthread_create(&t2, 0, thread2, 0);
  pthread_create(&t3, 0, thread3, 0);
  pthread_join(t1, 0);
  pthread_join(t2, 0);
  pthread_join(t3, 0);
  pthread_mutex_destroy(&mx);
  pthread_mutex_destroy(&my);
  return 0;
}

/* ./cream --debug --no-main
  ?? returns 'program is correct' after 5.5s (8 iterations)
*/

/* ./cream --debug --no-main --algorithm:rely-guarantee
  ??
*/
