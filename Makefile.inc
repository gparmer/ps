LNAME     = ps
CLIB      = lib$(LNAME).a

CINC     += -I. $(CINC_ENV)
CC        = $(CROSS_COMPILE)gcc
LD        = $(CC)
MAKE      = make

COPT      = -O3
CWARN     = -Wno-long-long
CFLAGS    = -MD -MP -std=c11 -Wall -Wpedantic -Wextra $(CWARN) $(COPT) $(CINC) -Wno-unused-function -Wno-address-of-packed-member

ifeq ($(ARCHNAME), x86)
CFLAGS   += -m32 -D__x86__
else ifeq ($(ARCHNAME), armv7a)
CFLAGS   += -march=armv7-a -D__arm__
endif

MAKEFLAGS = --no-print-directory --section-alignment 0x1000 -I$(PWD)
