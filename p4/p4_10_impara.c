#include <stdio.h>
#include <pthread.h>

int mx=0;
int x=0, y=0;

void *thread1() {
	__CPROVER_atomic_begin();__CPROVER_assume(mx==0);mx=1;__CPROVER_atomic_end();
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
	mx=0;
	y=y+1;
}

void *thread2() {
	__CPROVER_atomic_begin();__CPROVER_assume(mx==0);mx=1;__CPROVER_atomic_end();
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
	mx=0;
	y=y+1;
}

void *thread3() {
	int a = x;
	y=y+1;
}

int main() {
  __CPROVER_ASYNC_1: thread1();
  __CPROVER_ASYNC_1: thread2();
  __CPROVER_ASYNC_1: thread3();
  __CPROVER_assume(y==3);
  assert(x!=1);
  return 0;
}

// 'program is correct' after 3m20s
