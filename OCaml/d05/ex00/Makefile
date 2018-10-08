.PHONY:	all clean byte native profile debug test

OCB_FLAGS = -tag bin_annot -lib unix
OCB = 		ocamlbuild $(OCB_FLAGS)

all: native byte # profile debug

clean:
	$(OCB) -clean

native:
	$(OCB) micronap.native

byte:
	$(OCB) micronap.byte

profile:
	$(OCB) -tag profile micronap.native

debug:
	$(OCB) -tag debug micronap.byte

test: native
	./micronap.native
