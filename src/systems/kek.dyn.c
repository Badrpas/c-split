#include <inttypes.h> // pub
#define _GNU_SOURCE   // pub
#include <dlfcn.h>    // pub
#include "stdio.h"
#include "dummy.h"

#include "kek.dyn.gen.h"
#include "../sub_host.dyn.gen.h"


static struct {
    const char* dli_fname; /* Pathname of shared object that
                              contains address */
    void* dli_fbase;       /* Address at which shared object
                              is loaded */
    const char* dli_sname; /* Name of nearest symbol with address
                              lower than addr */
    void* dli_saddr;       /* Exact address of symbol named
                              in dli_sname */
} __dl_info = {0};

int dladdr(void *addr, typeof(__dl_info) *info);

extern int global_frame;

void do_kek (int a, int BBB) {
    printf(LUL " + do_kek(%i, %i); koka = %i\n", a, BBB, subhost_ret123());
    dladdr((void*)do_kek, &__dl_info);
    global_frame += 5;
    printf(LUL " + %s dokeks global_framve=%i\n", __dl_info.dli_sname, global_frame);
}


