CFLAGS=-Wall -g 
LDFLAGS=-Wall -g -lpthread

COMPILE=g++ $(CFLAGS) -c
LINK=g++ $(LDFLAGS) -o

SRCDIR=./src
OBJDIR=./obj
#OBJ=$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(wildcard $(SRCDIR)/*.cpp))
OBJ=$(OBJDIR)/main.o $(OBJDIR)/mythread.o $(OBJDIR)/server.o $(OBJDIR)/client.o
BINDIR=./bin
BIN=$(BINDIR)/chat


all: $(BIN) 

$(BIN): $(OBJ)
	$(LINK) $(BIN) $(OBJ)

$(OBJDIR)/%.o:	$(SRCDIR)/%.cpp
	$(COMPILE) $< -o $@

clean:
	rm -f $(OBJ) $(BIN)

