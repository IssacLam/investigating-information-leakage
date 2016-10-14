#include "gtypes.h"
#include <stdarg.h>
#include <stdio.h>

/*gchar* g_convert (const gchar *str, gssize len,  
		const gchar *to_codeset,
		const gchar *from_codeset,
		gsize       *bytes_read, 
		gsize       *bytes_written, GError **error)
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
}*/
/*
 gchar*
   g_strdup (const gchar *str)
   {
     gchar *new_str;
     gsize length;
   
     if (str)
       {
         length = strlen (str) + 1;
         new_str = g_new (char, length);
         memcpy (new_str, str, length);
       }
     else
       new_str = NULL;
   
     return new_str;
   }
  */ 

 void
  g_return_if_fail_warning (const char *log_domain,
                const char *pretty_function,
                const char *expression)
  {
    /*g_log (log_domain,
       G_LOG_LEVEL_CRITICAL,
       "%s: assertion '%s' failed",
       pretty_function,
       expression);*/
  }

/*gchar*
   g_strdup_printf (const gchar *format,
                    ...)
   {
     gchar *buffer;
     va_list args;
   
     va_start (args, format);
     buffer = g_strdup_vprintf (format, args);
     va_end (args);
   
     return buffer;
   }
*/
gint
   g_snprintf (gchar   *string,
           gulong   n,
           gchar const *format,
           ...)
   {
     va_list args;
     gint retval;
   
     va_start (args, format);
     retval = g_vsnprintf (string, n, format, args);
     va_end (args);
     
     return retval;
   }


