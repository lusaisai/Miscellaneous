/* 
 * File:   main.c
 * Author: lusaisai
 *
 * Created on September 11, 2014, 7:57 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void *generic_binary_search( void *data, void *key, int cellcount, int cellsize, int (*compare)(void *a, void *b) ) {
    if( cellcount <= 0 ) return NULL;
    
    int halfcount = cellcount / 2;
    char *middle = (char *)data + halfcount*cellsize;
    
    int result = compare(key, middle);
    
    if( result == 0 ) {
        return middle;
    } else if ( result < 0 ) {
        return generic_binary_search( data, key, halfcount, cellsize, compare );
    } else {
        return generic_binary_search( middle + cellsize, key, cellcount - halfcount - 1, cellsize, compare );
    }
    
}

int int_compare( void *a, void *b ) {
    if( *(int *)a == *(int *)b ) {
        return 0;
    } else if ( *(int *)a < *(int *)b ) {
        return -1;
    } else {
        return 1;
    }
}

void int_test(){
    int data[] = {1,2,3,3,4,6,6,7,7,8,9,10};
    int *result;
    int will_find = 8;
    int will_not_find = 5;
    
    result = generic_binary_search(data, &will_find, sizeof(data)/sizeof(data[0]), sizeof(data[0]), int_compare);
    assert( *result == will_find );
    
    result = generic_binary_search(data, &will_not_find, sizeof(data)/sizeof(data[0]), sizeof(data[0]), int_compare);
    assert( result == NULL );
}


void str_test(){
    char *data[] = { "c", "pointer", "is", "amazing", "!" };
    char *result;
    char *will_find = "amazing";
    char *will_not_find = "sucking";
    
    result = generic_binary_search(data, &will_find, sizeof(data)/sizeof(data[0]), sizeof(data[0]), strcmp);
    assert( strcmp(result, will_find) );
    
    result = generic_binary_search(data, &will_not_find, sizeof(data)/sizeof(data[0]), sizeof(data[0]), strcmp);
    assert( result == NULL );
}

/*
 * 
 */
int main(int argc, char** argv) {
    int_test();
    str_test();
    
    return (EXIT_SUCCESS);
}

