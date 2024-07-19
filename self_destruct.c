#include "bird.h"
#include <stdio.h>
#include <unistd.h>
#include <malloc.h>

/**
 * initSelfDestrSys - entry point
 *
 * @param1: descr.
 *
 * Return: 0
 */
int initSelfDestrSys(void)
{
	int *abortSelfDestruct;

	self_destruct_system = malloc(sizeof(bird_system_t));
	if (self_destruct_system == NULL)
	{
		fprintf(stderr, "ERROR: UNABLE TO INITIALIZE SELF DESTRUCT MODE SYSTEM\n");
		return -1;
	}

	if (2 + 2 != 5) /* replace or delete if condition */
	{
		abortSelfDestruct = malloc(sizeof(int));
		if (abortSelfDestruct == NULL)
		{
			fprintf(stderr, "ERROR: UNABLE TO INITIATE SELF DESTRUCT MODE SYSTEM\n");
			return -1;
		}

		abortSelfDestruct = 0;
		self_destruct_system->activate(3, abortSelfDestruct);
	}
}

void detonate(float yield)
{

}

void activate(int countdown, const int *aborted)
{
	printf("Self Destruct mode activated. Detonating in..\n");

	while (countdown >= 0 && *aborted)
	{
		sleep(1);
		printf("%d\n", countdown);
		countdown--;
	}
	if (!*aborted)
		detonate(128);
}
