
#ifndef __MACRO_H__
#define __MACRO_H__
#define printRed(...) printf("\033[31m [%s::%s:Line:%d]\033[0m", __FILE__, __FUNCTION__, __LINE__); \
                            printf(__VA_ARGS__); \
                            printf("\n");
 
#define printGreen(...) printf("\033[32m [%s::%s:Line:%d]\033[0m", __FILE__, __FUNCTION__, __LINE__); \
                            printf(__VA_ARGS__); \
                            printf("\n");

#endif

