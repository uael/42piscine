.PHONY:	all clean byte native profile debug test

OCB_FLAGS = -tag bin_annot -lib graphics
OCB = 		ocamlbuild $(OCB_FLAGS)

all: native byte # profile debug

clean:
	$(OCB) -clean

native:
	$(OCB) gardening.native

byte:
	$(OCB) gardening.byte

profile:
	$(OCB) -tag profile gardening.native

debug:
	$(OCB) -tag debug gardening.byte

test: native
	./gardening.native
