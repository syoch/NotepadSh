
# Commands
WX_CONFIG ?= wx-config
CXX ?= `$(WX_CONFIG) --cxx`
CC  ?= `$(WX_CONFIG) --cc`

## Directorys
SRCDIR  = ./src/
OBJDIR  = ./obj
## Files
TARGET=notepadsh

## Arguments
LDFLAGS ?=
CFLAGS  ?=
CXXFLAGS?=
CPPFLAGS?=

## Get Files
SRCS = $(foreach dir,$(SRCDIR) $(filter ./%/,$(wildcard ./src/*/)),$(wildcard $(dir)*.cpp))
OBJS = $(addprefix ./obj/,$(subst /,_,$(SRCS:./src/%.cpp=%.o)))
DEPS = $(addprefix ./dep/,$(subst /,_,$(SRCS:./src/%.cpp=%.d)))

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
.PHONY: all info
all: info notepadsh
info:
	@echo "--------------------"
	@echo "Detected source files: $(SRCS)"
	@echo "         object files: $(OBJS)"
	@echo "         depend files: $(DEPS)"
	@echo "--------------------"

notepadsh: $(subst _,/,$(OBJS))
	@$(CXX) -o $@ $(OBJS) $(WX_CPPFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)%.cpp
	@echo compile object $(subst obj_,obj/,$(subst /,_,$@))
	@$(CXX) -c -o $(subst obj_,obj/,$(subst /,_,$@)) -Wall -Wextra -MMD -MP -MF $(subst :,/,$(subst /,_,$(@:obj/%.o=dep:%.d))) $(notepadsh_CXXFLAGS) $(WX_CPPFLAGS) $(CXXFLAGS) $^

# Source Dependencies
-include $(DEPS)
