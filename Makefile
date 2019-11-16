BIN = flow
BINPATH = bin/
SRCPATH = src/
LEDADIR = /work/LEDA/
EXE = $(BINPATH)$(BIN)

CC = g++
CHDRS = $(wildcard $(SRCPATH)*.h)
CSRCS = $(wildcard $(SRCPATH)*.cpp)
COBJS = $(addsuffix .o, $(basename $(CSRCS)))
CINCLS = -Llib/LEDA \
		 -I$(LEDADIR)/incl
CLIBS = -lleda
CFLAGS = -std=c++11 -O3 -Wall

ECHO = echo
RM = rm
MKDIR = mkdir

$(EXE): $(COBJS)
	@$(MKDIR) -p $(BINPATH)
	@$(ECHO) "[Bulid Target] $(EXE)"
	@$(CC) $(CFLAGS) $(COBJS) -o $(EXE) $(CINCLS) $(CLIBS)

$(SRCPATH)%.o: $(SRCPATH)%.cpp $(CHDRS)
	@$(ECHO) "[Compile] $<"
	@$(CC) $(CFLAGS) -c $< -o $@ $(CINCLS) $(CLIBS)

clean:
	@$(RM) -rf $(EXE) $(COBJS)