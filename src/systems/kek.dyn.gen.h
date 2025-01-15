/**
 * File is generated
 **/

#ifndef SYSTEMS_KEK_DYN_C
#define SYSTEMS_KEK_DYN_C

#include <dlfcn.h>
#include <inttypes.h>


#ifndef _DYN_SPLIT_BUILD

void do_kek (int , int );


#else

extern int printf (const char *__restrict __format, ...);

void reg_dyn (char* mpath, char* symbol, void** target, void* registrar);

static void (* __ptr_do_kek) (int a, int BBB) = 0;
void do_kek (int a, int BBB) {
  static int inited = 0; 
  if (!inited) {
    inited = 1; 
    printf("[PROXY.init] initing do_kek\n");
    reg_dyn(
        "/home/grug/projects/anotherreloadc/out/systems/kek.dyn.so",
        "do_kek",
        (void*)&__ptr_do_kek,
        //(void*)&inited
        "src/systems/kek.dyn.c"
    );
  }
  if (__ptr_do_kek) {
    return __ptr_do_kek(a, BBB);
  }
}


#endif

#endif
