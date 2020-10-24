
# Commands
WX_CONFIG ?= wx-config
CXX ?= `$(WX_CONFIG) --cxx`
CC  ?= `$(WX_CONFIG) --cc`

## Directorys
SRCDIR := src
OBJDIR := obj
DEPDIR := dep
INCDIR := inc

## Files
TARGET=notepadsh

## Arguments
CXXDEP   ?= -MMD -MP -MF $(subst :,/,$(subst /,_,$(@:obj/%.o=dep:%.d)))
LDFLAGS  ?=
CXXFLAGS ?=

## Get Files
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEPS := $(SRCS:$(SRCDIR)/%.cpp=$(DEPDIR)/%.d)

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

### Targets
.PHONY: all info clean pch
all: $(TARGET)

# PHONY Targets
clean:
	$(RM) dep/* obj/*
	$(RM) notepadsh
	$(RM) inc/pch.h.gch

info:
	@echo "--------------------"
	@echo "| source  : $(SRCDIR) : $(SRCS)"
	@echo "| include : $(INCDIR) : -----"
	@echo "| object  : $(OBJDIR) : $(OBJS)"
	@echo "| depend  : $(DEPDIR) : $(DEPS)"
	@echo "--------------------"

# Program Rule
$(TARGET): $(INCDIR)/pch.h.gch $(OBJS)
	@echo "building $@"
	@$(CXX) -o $@ $(WX_CPPFLAGS) $(LDFLAGS) $(OBJS)

# Pch Rule
$(INCDIR)/pch.h.gch: $(INCDIR)/pch.h
	@echo "compile pch '$(INCDIR)/pch.h' to '$@'"
	@$(CXX) -std=gnu++11 -o    $@ -Wall -Wextra  $(shell $(WX_CONFIG) --cxxflags $(WX_CONFIG_FLAG)) -I $(INCDIR) $(CXXFLAGS) $(INCDIR)/pch.h

# .cpp -> .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo compile $< to '$@'
	@$(CXX) -std=gnu++11 -c -o $@ $(CXXDEP) -Wall -Wextra  $(WX_CPPFLAGS) -I $(INCDIR) $(CXXFLAGS) $<

# Source Dependencies
-include $(DEPS)
