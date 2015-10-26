# Copyright (C) 2011, 2012, 2013, 2014 The uOFW team
# See the file COPYING for copying permission.

TARGET = usbacc
OBJS = usbacc.o

#DEBUG = 1

LIBS = -lInterruptManagerForKernel -lThreadManForKernel -lUtilsForKernel

include ../../lib/build.mak
