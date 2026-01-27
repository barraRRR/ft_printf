# ft_printf
A custom C library that replicates the standard printf() function. It supports variadic arguments and core conversions like %c, %s, %p, %d, %i, %u, %x, %X, and %% .

creo que es tontería intentar utilizar libft tal cual. mejor utilizar funciones custom (8 casos)
itero por el string
voy sumando len
cuando detecto %, evaluo
si es doble %, cuento uno y sigo iterando
else
	funcion que devuelve len y error




Print formatted data to stdout
Writes the C string pointed by format to the standard output (stdout). If format includes format specifiers (subsequences beginning with %), the additional arguments following format are formatted and inserted in the resulting string replacing their respective specifiers.



Resources

https://www.it.uc3m.es/pbasanta/asng/course_notes/input_output_printf_es.html

https://www.youtube.com/watch?v=oDC208zvsdg

man stdarg

https://www.youtube.com/watch?v=7Sph8JlRo0g

https://www.youtube.com/watch?v=kM-DOhKR080

https://medium.com/@scarletskynned/variadic-functions-in-c-stdarg-h-f466101f1d47
