.PHONY:	all clean byte native profile debug test

OCB_FLAGS = -tag bin_annot
OCB = 		ocamlbuild $(OCB_FLAGS)

all: native byte # profile debug

clean:
	$(OCB) -clean

native:
	$(OCB) jokes.native

byte:
	$(OCB) jokes.byte

profile:
	$(OCB) -tag profile jokes.native

debug:
	$(OCB) -tag debug jokes.byte

test: native
	./jokes.native
