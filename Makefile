CC ?= gcc
CPPFLAGS ?= -I.
CFLAGS ?= -std=gnu11 -O2
LDFLAGS ?=
LDLIBS ?=

LIBNC_SOURCES = libnc.c src/libnc_impl.c src/libnc_extra.c
LIBNC_SOURCES += src/libnc_device_helpers.c src/libnc_graph_helpers.c
LIBNC_SOURCES += src/libnc_param_io.c src/libnc_parallel.c src/libnc_cuda_loader.c
LIBNC_HEADERS = libnc.h cutils.h list.h src/libnc_internal.h

TEST_SOURCES = tests/nctest.c tests/matmul_test.c tests/ncspeed.c tests/own_tests.c

ifeq ($(OS),Windows_NT)
EXEEXT := .exe
SHLIB := libnc.dll
SHLIB_IMPLIB := libnc.dll.a
CUDA_LIB := libnc_cuda.dll
CUDA_IMPLIB := libnc_cuda.dll.a
TEST_BINS := nctest.exe matmul_test.exe ncspeed.exe own_tests.exe
RUN_ENV :=
RUN_NCTEST := ./nctest.exe -d cpu
RUN_MATMUL := ./matmul_test.exe -c 0 0 4 4 4 && ./matmul_test.exe -c 1 0 4 4 4 && ./matmul_test.exe -c 0 1 4 4 4
RUN_NSPEED := ./ncspeed.exe -d cpu -n 10000 -w 64 add mul sum reduce_sum_sqr sigmoid reduce_sum_col soft_max layer_norm convert_bf16 rnd_unif rnd_dropout masked_fill
RUN_OWN := ./own_tests.exe
ALL_TARGETS := $(SHLIB) $(CUDA_LIB) $(TEST_BINS)
else
EXEEXT :=
SHLIB := libnc.so
TEST_BINS := nctest matmul_test ncspeed own_tests
RUN_ENV := LD_LIBRARY_PATH=.
RUN_NCTEST := ./nctest -d cpu
RUN_MATMUL := ./matmul_test -c 0 0 4 4 4 && ./matmul_test -c 1 0 4 4 4 && ./matmul_test -c 0 1 4 4 4
RUN_NSPEED := ./ncspeed -d cpu -n 10000 -w 64 add mul sum reduce_sum_sqr sigmoid reduce_sum_col soft_max layer_norm convert_bf16 rnd_unif rnd_dropout masked_fill
RUN_OWN := ./own_tests
ALL_TARGETS := $(SHLIB) $(TEST_BINS)
endif

.PHONY: all libnc cuda tests test clean check

all: $(ALL_TARGETS)

libnc: $(SHLIB)

cuda:
ifeq ($(OS),Windows_NT)
	$(MAKE) $(CUDA_LIB)
else
	@echo "CUDA backend source in this repository is Windows-targeted."
endif

tests: $(TEST_BINS)

test: all
	$(RUN_ENV) $(RUN_NCTEST)
	$(RUN_ENV) $(RUN_MATMUL)
	$(RUN_ENV) $(RUN_NSPEED)
	$(RUN_ENV) $(RUN_OWN)

check: test

$(SHLIB): $(LIBNC_SOURCES) $(LIBNC_HEADERS)
ifeq ($(OS),Windows_NT)
	$(CC) $(CPPFLAGS) $(CFLAGS) -shared -o $@ libnc.c -Wl,--out-implib,$(SHLIB_IMPLIB)
else
	$(CC) $(CPPFLAGS) $(CFLAGS) -fPIC -shared -o $@ libnc.c -lpthread -ldl -lm
endif

ifeq ($(OS),Windows_NT)
$(CUDA_LIB): $(SHLIB) src/libnc_cuda_backend.c src/libnc_internal.h libnc.h cutils.h list.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -shared -o $@ src/libnc_cuda_backend.c -L. -lnc -Wl,--out-implib,$(CUDA_IMPLIB)
endif

ifeq ($(OS),Windows_NT)
%.exe: tests/%.c $(SHLIB)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -L. -lnc -o $@
else
%: tests/%.c $(SHLIB)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -L. -lnc -Wl,-rpath,'$$ORIGIN' -lpthread -ldl -lm -o $@
endif

clean:
	rm -f $(SHLIB) $(TEST_BINS)
	rm -f $(SHLIB_IMPLIB) $(CUDA_LIB) $(CUDA_IMPLIB) *.o
