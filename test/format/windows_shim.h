#ifdef _WIN32
#define R_OK 04
#define X_OK R_OK

#define getpid() 0

#define snprintf _snprintf

typedef uint32_t useconds_t;

int
sleep(int seconds);

int
usleep(useconds_t useconds);

#define BERKELEY_DB_PATH "d:\\wt\\bdb"

#endif
