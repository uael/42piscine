.PHONY:	all clean byte native profile debug test

OCB_FLAGS = -tag bin_annot -lib unix
OCB = 		ocamlbuild $(OCB_FLAGS)

all: native byte # profile debug

clean:
	$(OCB) -clean

native:
	$(OCB) ex00.native

byte:
	$(OCB) ex00.byte

profile:
	$(OCB) -tag profile ex00.native

debug:
	$(OCB) -tag debug ex00.byte

test: native
	./ex00.native
