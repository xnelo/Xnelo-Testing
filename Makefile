##########################################################
## Define Variables
##########################################################
OBJDIR = ./obj
BINDIR = ./bin
DEPDIR = ./obj/.deps
SRCDIR = ./source
INCDIR = ./include
LIBDIR = ./lib
EXAMPLEDIR = ./Example

LIBRARY_NAME = XneloTesting
EXAMPLE_PROG = example

SOURCES = OutStreamGenerator.cpp Test.cpp Test_Result.cpp TestSuite.cpp
SOURCES_DIR = $(SOURCES:%.cpp=$(SRCDIR)/%.cpp)
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)
OBJECTS_SHARED = $(SOURCES:%.cpp=$(OBJDIR)/%.os)

###########
##Advanced Dependencies
###########
df = $(DEPDIR)/$(*F)

INCLUDE_DIRS = $(INCDIR)
CFLAGS= -Wall

###########
##Commands
###########
MAKE_DIR = mkdir
REMOVE = rm
PRINT = echo
COPY = cp
STATICLIB = ar
CXX = g++
MAKEDEPEND = $(CXX) -M $(CPPFLAGS) -I$(INCLUDE_DIRS) -o $(df).d $<
##^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

bin: staticlib sharedlib example exampleshared
	@$(PRINT) Library and example program built

staticlib: makedirs $(OBJECTS)
	@$(PRINT) Creating Library File: lib$(LIBRARY_NAME).a
	$(STATICLIB) rvs $(LIBDIR)/lib$(LIBRARY_NAME).a $(OBJECTS)

example: staticlib
	@$(PRINT) Creating Example Program
	$(CXX) $(CFLAGS) -static -I$(INCLUDE_DIRS) -o $(BINDIR)/$(EXAMPLE_PROG) $(EXAMPLEDIR)/main.cpp $(LIBDIR)/lib$(LIBRARY_NAME).a

sharedlib: makedirs $(OBJECTS_SHARED)
	@$(PRINT) Creating Library File: lib$(LIBRARY_NAME).so
	$(CXX) $(CFLAGS) -shared -o $(LIBDIR)/lib$(LIBRARY_NAME).so $(OBJECTS_SHARED)	

exampleshared: sharedlib
	@$(PRINT) Creating Example Program dynamically linked
	$(CXX) $(CFLAGS) -I$(INCLUDE_DIRS) -o $(BINDIR)/$(EXAMPLE_PROG)_SHARED $(EXAMPLEDIR)/main.cpp $(LIBDIR)/lib$(LIBRARY_NAME).so

runsharedexample: exampleshared
	LD_LIBRARY_PATH=$(LIBDIR) && ./$(BINDIR)/$(EXAMPLE_PROG)_SHARED

makedirs:
	@$(PRINT) Creating needed directories
	$(MAKE_DIR) -p $(OBJDIR)
	$(MAKE_DIR) -p $(BINDIR)
	$(MAKE_DIR) -p $(DEPDIR)
	$(MAKE_DIR) -p $(LIBDIR)
	@$(PRINT) Done Creating directories

clean:
	@$(PRINT) Cleaning intermediary files
	$(REMOVE) -f $(OBJDIR)/*.o
	$(REMOVE) -f $(DEPDIR)/*.P
	$(REMOVE) -f $(OBJDIR)/*.os
	$(REMOVE) -f $(DEPDIR)/*.Ps
	@$(PRINT) Done Cleaning intermediary files

cleanall: clean
	@$(PRINT) Cleaning bin and lib directory
	$(REMOVE) -f $(BINDIR)/*
	$(REMOVE) -f $(LIBDIR)/*
	@$(PRINT) Done cleaning bin and lib directory

distclean: cleanall
	@$(PRINT) Removing added directories
	$(REMOVE) -rf $(DEPDIR)
	$(REMOVE) -rf $(OBJDIR)
	$(REMOVE) -rf $(BINDIR)
	$(REMOVE) -rf $(LIBDIR)
	@$(PRINT) Done removing added directories

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(MAKEDEPEND); \
	$(COPY) $(df).d $(df).P; \
	sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' -e '/^$$/ d' -e 's/$$/ :/' < $(df).d >> $(df).P; \
	$(REMOVE) -f $(df).d
	$(CXX) -c  $(CFLAGS) -I$(INCLUDE_DIRS) -o $@ $<

$(OBJDIR)/%.os : $(SRCDIR)/%.cpp
	@$(MAKEDEPEND); \
	$(COPY) $(df).d $(df).Ps; \
	sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' -e '/^$$/ d' -e 's/$$/ :/' < $(df).d >> $(df).Ps; \
	$(REMOVE) -f $(df).d
	$(CXX) -c -fPIC $(CFLAGS) -I$(INCLUDE_DIRS) -o $@ $<

-include $(SOURCES:%.cpp=$(DEPDIR)/%.P)
-include $(SOURCES:%.cpp=$(DEPDIR)/%.Ps)
# DO NOT DELETE
