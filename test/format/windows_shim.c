#include "format.h"

int
sleep(int seconds)
{
	Sleep(seconds * 1000);
}


int
usleep(useconds_t useconds)
{
	uint32_t milli;
	milli = useconds / 1000;
	if (milli == 0)
		milli++;
	Sleep(milli);
	return (0);
}

