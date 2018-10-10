.PHONY:	all clean byte native profile debug test

OCB_FLAGS = -tag bin_annot -lib unix
OCB = 		ocamlbuild $(OCB_FLAGS)

all: native byte # profile debug

clean:
	$(OCB) -clean

native:
	$(OCB) ex01.native

byte:
	$(OCB) ex01.byte

profile:
	$(OCB) -tag profile ex01.native

debug:
	$(OCB) -tag debug ex01.byte

test: native
	./ex01.native
