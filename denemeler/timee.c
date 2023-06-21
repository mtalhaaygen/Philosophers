#include <stdio.h>
#include <sys/time.h>

int main()
{
	struct timeval tv;
	time_t start_time;

	gettimeofday(&tv, NULL);
	printf("seconds : %ld\nmicro seceonds : %d\n", tv.tv_sec, tv.tv_usec);
	start_time = ((long int)tv.tv_sec * 1000) + (tv.tv_usec / 1000); 
	printf("toplam : %ld", start_time);
	// milisaniye cinsinden Unix timestamp tan itibaren geçen toplam süreyi yazdık
}