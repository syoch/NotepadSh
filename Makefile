
# Commands
WX_CONFIG ?= wx-config
CXX ?= `$(WX_CONFIG) --cxx`
CC  ?= `$(WX_CONFIG) --cc`

## Directorys
SRCDIR  = ./src
OBJDIR  = ./obj

## Files
TARGET=notepadsh

## Arguments
LDFLAGS ?=
CFLAGS  ?=
CXXFLAGS?=
CPPFLAGS?=

## Get Files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))
DEPS = $(OBJS:.o=.d)

### Variables
CPPDEPS = -MD -MP -MT$@
# wxwidgets

WX_VERSION ?= $(shell $(WX_CONFIG) --query-version)
WX_TOOLKIT ?= $(shell $(WX_CONFIG) --query-toolkit)

WX_SHARED ?= $(shell if test -z `$(WX_CONFIG) --query-linkage`; then echo 1; else echo 0; fi)
ifeq ($(WX_SHARED),0)
WX_CONFIG_SHARED_FLAG = --static=yes
endif
ifeq ($(WX_SHARED),1)
WX_CONFIG_SHARED_FLAG = --static=no
endif

WX_UNICODE ?= $(shell $(WX_CONFIG) --query-chartype)
ifeq ($(WX_UNICODE),ansi)
WX_CONFIG_UNICODE_FLAG = --unicode=no
endif
ifeq ($(WX_UNICODE),unicode)
WX_CONFIG_UNICODE_FLAG = --unicode=yes
endif

WX_CPPFLAGS ?= $(shell $(WX_CONFIG) --cxxflags --libs core,base --toolkit=$(WX_TOOLKIT) --version=$(WX_VERSION) $(WX_CONFIG_UNICODE_FLAG) $(WX_CONFIG_SHARED_FLAG))

notepadsh_OBJECTS =  main.o

### Targets
notepadsh: $(OBJS)
	@echo linking
	$(CXX) -o $@ $(OBJS) $(WX_CPPFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo compiling
	$(CXX) -c -o $@ -Wall -Wextra -MMD -MP $(notepadsh_CXXFLAGS) $(WX_CPPFLAGS) $(CXXFLAGS) $(CPPDEPS) $<

# Source Dependencies
-include $(DEPS)
