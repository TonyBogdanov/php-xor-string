PHP_ARG_ENABLE(xor_string, Whether to enable the XOR String extension, [ --enable-xor-string Enable XorString])

if test "$XOR_STRING" != "no"; then
    PHP_NEW_EXTENSION(xor_string, xor_string.c, $ext_shared)
fi
