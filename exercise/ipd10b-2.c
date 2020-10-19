#include <libipd.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * 10.b.1
 * This video talks about two ways of solving the problem where to store strings
 *
 * How can we work with strings more flexibly?
 *
 * function: string->string(as large as needed), we need to allocating the result string
 *
 * Uniform-capacity strings: fix a uniform size for all the strings in our program. Easy but inflexible.
 * define a struct for storing string and put an array in that struct, copy that around, which
 * works fine with smaller string, but it's really inefficient for long string
 *
 *
 * Storing C-style strings
 * using a pointer for the first character, stop when hit 0.
 * but it has some pre-condition
 * DST actually points to a string with a 0 and Dst points to another buffer that has sufficient capacity
 * otherwise its undefined behaviour.
 *
 * how can we ensure the buffer has enough capacity?
 * uppercase a string
 * 1. reuse existing memory, not working the the length of string grow
 * 2. let the caller to worry about where to put the result
 * 3. find new memory for the result, but you can't return a pointer to a local variable
 *  because it goes away when it returns
 *
 *  we need dynamic memory allocation
 */


// Returns a string that is like `s`, but any uppercase letters doubled.
//
// Examples:
//  - double_upper("hello")        => "hello"
//  - double_upper("Hello")        => "HHello"
//  - double_upper("IPD")          => "IIPPDD"
//  - double_upper("Evanston, IL") => "EEvanston, IILL"
//
char* double_upper(const char* s)
{

    char *ret = malloc (strlen (s) * 2 + 2);
    if (ret == NULL) return NULL;

        for(size_t i = 0; i<strlen (s);i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                strncat(ret,&s[i],1);
                strncat(ret,&s[i],1);
            }else
            strncat(ret,&s[i],1);
        }

    return ret;
}

void test_double_upper(void)
{
    char * result = double_upper("Hello");
    puts(result);
    free(result);
    CHECK_STRING(double_upper("Hello"),"HHello");

    char * result2 = double_upper("hello");
    puts(result2);
    free(result2);
    CHECK_STRING(double_upper("hello"),"hello");

    char * result3 = double_upper("IPD");
    puts(result3);
    free(result3);
    CHECK_STRING(double_upper("IPD"),"IIPPDD");

    char * result4 = double_upper("Evanston, IL");
    puts(result4);
    free(result4);
    CHECK_STRING(double_upper("Evanston, IL"),"EEvanston, IILL");

    char * result5 = double_upper("EvanSSSSSston, IL");
    puts(result5);
    free(result5);
    CHECK_STRING(double_upper("EvanSSSSSston, IL"),"EEvanSSSSSSSSSSston, IILL");


}


int main(void)
{
    test_double_upper();
}

/*
 * 10.b.3
 * this video shows various use of NUll
 * 1. The null pointer is a pointer that doesn't point to any object.
 * If you don't have an address to assign to a pointer, you can use null.
 *
 *2. Null pointer constant
 *
 * 3. (char)0 : string terminator values
 * NULL is a macro in whereas NUL is the name given to the first ASCII character.
 *
 * 4. '\0', #define NUL '\0'
 */
