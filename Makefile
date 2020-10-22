
# Commands
WX_CONFIG ?= wx-config
CXX ?= `$(WX_CONFIG) --cxx`
CC  ?= `$(WX_CONFIG) --cc`

## Directorys
SRCDIR := src
OBJDIR := obj
DEPDIR := dep

## Files
TARGET=notepadsh

## Arguments
CXXDEP  ?= -MMD -MP -MF $(subst :,/,$(subst /,_,$(@:obj/%.o=dep:%.d)))
LDFLAGS ?=
CXXFLAGS?=

## Get Files
SRCS = $(foreach dir,$(SRCDIR) $(filter ./%/,$(wildcard ./src/*/)),$(wildcard $(dir)*.cpp))
OBJS = $(addprefix $(OBJDIR)/,$(subst /,_,$(SRCS:./src/%.cpp=%.o)))
DEPS = $(addprefix $(DEPDIR)/,$(subst /,_,$(SRCS:./src/%.cpp=%.d)))

# wx-config arguments
WX_CONFIG_FLAG ?= 

WX_SHARED ?= $(shell if test -z `$(WX_CONFIG) --query-linkage`; then echo 1; else echo 0; fi)
ifeq ($(WX_SHARED),0)
WX_CONFIG_FLAG := $(WX_CONFIG_FLAG) --static=yes
endif
ifeq ($(WX_SHARED),1)
WX_CONFIG_FLAG := $(WX_CONFIG_FLAG) --static=no
endif

WX_CHARTYPE ?= $(shell $(WX_CONFIG) --query-chartype)
ifeq ($(WX_CHARTYPE),ansi)
WX_CONFIG_FLAG := $(WX_CONFIG_FLAG) --unicode=no
endif
ifeq ($(WX_CHARTYPE),unicode)
WX_CONFIG_FLAG := $(WX_CONFIG_FLAG) --unicode=yes
endif

WX_CONFIG_FLAG := $(WX_CONFIG_FLAG) $(shell $(WX_CONFIG) --query-version)
WX_CONFIG_FLAG := $(WX_CONFIG_FLAG) $(shell $(WX_CONFIG) --query-toolkit)

WX_CPPFLAGS ?= $(shell $(WX_CONFIG) --cxxflags --libs core,base $(WX_CONFIG_FLAG))
notepadsh_OBJECTS =  main.o

### Targets
.PHONY: all info clean
all: info $(TARGET)
info:
	@echo "--------------------"
	@echo "Detected source files: $(SRCS)"
	@echo "         object files: $(OBJS)"
	@echo "         depend files: $(DEPS)"
	@echo "--------------------"

clean:
	$(RM) dep/* obj/*
	$(RM) notepadsh

$(TARGET): $(subst _,/,$(OBJS))
	@$(CXX) -o $@ $(OBJS) $(WX_CPPFLAGS) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)%.cpp
	@echo compile object $(subst obj_,obj/,$(subst /,_,$@))
	@$(CXX) -c -o $(subst obj_,obj/,$(subst /,_,$@)) -Wall -Wextra $(CXXDEP) $(WX_CPPFLAGS) $(CXXFLAGS) $^

# Source Dependencies
-include $(DEPS)
