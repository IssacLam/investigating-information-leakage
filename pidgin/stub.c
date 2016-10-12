#include "config.h"

#include "gmem.h"

#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include "gslice.h"
#include "gbacktrace.h"
#include "gtestutils.h"
#include "gthread.h"
#include "glib_trace.h"

gchar* g_convert (const gchar *str,
		gssize       len,  
		const gchar *to_codeset,
		const gchar *from_codeset,
		gsize       *bytes_read, 
		gsize       *bytes_written, 
		GError     **error)
{
	gchar *res;
	GIConv cd;

	g_return_val_if_fail (str != NULL, NULL);
	g_return_val_if_fail (to_codeset != NULL, NULL);
	g_return_val_if_fail (from_codeset != NULL, NULL);

	cd = open_converter (to_codeset, from_codeset, error);

	if (cd == (GIConv) -1)
	{
		if (bytes_read)
			*bytes_read = 0;

		if (bytes_written)
			*bytes_written = 0;

		return NULL;
	}

	res = g_convert_with_iconv (str, len, cd,
			bytes_read, bytes_written,
			error);

	close_converter (cd);

	return res;
}

g_strdup

g_return_if_fail_warning

g_strdup_printf

gpointer g_malloc(gsize n_bytes){
	if (G_LIKELY (n_bytes))
	{
		gpointer mem;
		mem = malloc (n_bytes);
		TRACE (GLIB_MEM_ALLOC((void*) mem, (unsigned int) n_bytes, 0, 0));
		if (mem)
			return mem;

		g_error ("%s: failed to allocate %"G_GSIZE_FORMAT" bytes",
				G_STRLOC, n_bytes);
	}
	TRACE(GLIB_MEM_ALLOC((void*) NULL, (int) n_bytes, 0, 0));
	return NULL;
}

g_snprintf

void g_free(gpointer mem){
	if (G_LIKELY (mem))
		free (mem);
	TRACE(GLIB_MEM_FREE((void*) mem));
}


