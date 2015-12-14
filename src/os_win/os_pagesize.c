/*-
 * Copyright (c) 2014-2015 MongoDB, Inc.
 * Copyright (c) 2008-2014 WiredTiger, Inc.
 *	All rights reserved.
 *
 * See the file LICENSE for redistribution information.
 */

#include "wt_internal.h"

/*
 * __wt_os_get_pagesize --
 *	Return the default page size of a virtual memory page.
 */
int
__wt_os_get_pagesize(WT_SESSION_IMPL *session, uint32_t *page_size)
{
  SYSTEM_INFO system_info;
  GetSystemInfo(&system_info);
  *page_size = system_info.dwPageSize;
				

	return 0;
}
