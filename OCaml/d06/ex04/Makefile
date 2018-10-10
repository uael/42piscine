.PHONY:	all clean byte native profile debug test

OCB_FLAGS = -tag bin_annot -lib unix
OCB = 		ocamlbuild $(OCB_FLAGS)

all: native byte # profile debug

clean:
	$(OCB) -clean

native:
	$(OCB) ex04.native

byte:
	$(OCB) ex04.byte

profile:
	$(OCB) -tag profile ex04.native

debug:
	$(OCB) -tag debug ex04.byte

test: native
	./ex04.native
