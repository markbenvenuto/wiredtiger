/*-
 * Copyright (c) 2008-2014 WiredTiger, Inc.
 *	All rights reserved.
 *
 * See the file LICENSE for redistribution information.
 */

/*
 * Windows does not support Posix Threads
 * WT needs it so we mock it up with the Windows concurrency primitives
 * Assumes Windows 7+/2008 R2+
 */
typedef CRITICAL_SECTION  _wt_mutex_t;

typedef CONDITION_VARIABLE _wt_cond_t;

typedef SRWLOCK _wt_rwlock_t;

typedef HANDLE _wt_thread_t;

/* Timespec is a POSIX structure not defined in Windows */
struct timespec {
    time_t  tv_sec;    /* seconds */
    long    tv_nsec;   /* nanoseconds */
};

#define	strncasecmp _strnicmp

/*
 * Windows Portability stuff
 * These are POSIX types which Windows lacks
 * Eventually WiredTiger will migrate away from these types
 */
typedef uint32_t u_int;
typedef unsigned char u_char;
typedef unsigned long u_long;

/* < VS 2013 is not C99 compat */
#if _MSC_VER < 1900
#define	snprintf _snprintf
#endif

/*
 * Windows does have ssize_t
 * Python headers declare also though so we need to guard it
 * Berkeley DB headers also defined it
 */
#if !defined(HAVE_SSIZE_T) && !defined(_DB_H_)
typedef int ssize_t;
#endif

/*
 * Provide a custom version of vsnprintf that returns the
 * needed buffer length instead of -1 on truncation
 */
#define	vsnprintf _wt_vsnprintf

_Check_return_opt_ int __cdecl _wt_vsnprintf(
    _Out_writes_(_MaxCount) char * _DstBuf,
    _In_ size_t _MaxCount,
    _In_z_ _Printf_format_string_ const char * _Format,
    va_list _ArgList);

/* Provide a custom version of localtime_r */
struct tm *localtime_r(const time_t* timer, struct tm* result);
