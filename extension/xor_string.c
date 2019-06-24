// include the PHP API itself
#include <php.h>

// then include the header of your extension
#include "xor_string.h"
#include "zend_exceptions.h"

// register our function to the PHP API
// so that PHP knows, which functions are in this module
zend_function_entry xor_string_functions[] = {

    PHP_FE( xor_string, NULL )
    { NULL, NULL, NULL }

};

// some pieces of information about our module
zend_module_entry xor_string_module_entry = {

    STANDARD_MODULE_HEADER,
    XOR_STRING_EXTNAME,
    xor_string_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    XOR_STRING_VERSION,
    STANDARD_MODULE_PROPERTIES

};

// use a macro to output additional C code, to make ext dynamically loadable
ZEND_GET_MODULE( xor_string )

PHP_FUNCTION( xor_string ) {

    /* your accepted arguments here */
    char* value;
    size_t value_length;

    char* key;
    size_t key_length;

    size_t offset = 0;

    /* accepting arguments */
    if ( zend_parse_parameters( ZEND_NUM_ARGS() TSRMLS_CC, "ss|l", &value, &value_length, &key, &key_length, &offset ) != SUCCESS ) {

        RETURN_NULL();

    }

    if ( 64 != key_length ) {

        zend_throw_exception( zend_exception_get_default( TSRMLS_C ), "Supplied key must be exactly 64 bytes long.", 0 TSRMLS_CC );

    }

    for ( size_t i = 0; i < value_length; i++ ) {

        value[ i ] ^= key[ ( i + offset ) % key_length ];

    }

}
