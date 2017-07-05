PROJECT = eastro
PROJECT_DESCRIPTION = New project
PROJECT_VERSION = 0.1.0

SP = 2

DEPS = astrolog
dep_astrolog = git https://github.com/drumanew/astrolog testing

include erlang.mk

export C_SRC_OUTPUT_FILE
export CFLAGS
export LDFLAGS
export LDLIBS

deps::
	make -C $(DEPS_DIR)/astrolog install DESTDIR=$(CURDIR)/priv/astrolog

distclean::
	rm -rf $(CURDIR)/priv/astrolog
