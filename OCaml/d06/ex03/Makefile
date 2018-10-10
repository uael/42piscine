.PHONY:	all clean byte native profile debug test

OCB_FLAGS = -tag bin_annot -lib unix
OCB = 		ocamlbuild $(OCB_FLAGS)

all: native byte # profile debug

clean:
	$(OCB) -clean

native:
	$(OCB) ex03.native

byte:
	$(OCB) ex03.byte

profile:
	$(OCB) -tag profile ex03.native

debug:
	$(OCB) -tag debug ex03.byte

test: native
	./ex03.native
