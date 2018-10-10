.PHONY:	all clean byte native profile debug test

OCB_FLAGS = -tag bin_annot -lib unix
OCB = 		ocamlbuild $(OCB_FLAGS)

all: native byte # profile debug

clean:
	$(OCB) -clean

native:
	$(OCB) ex02.native

byte:
	$(OCB) ex02.byte

profile:
	$(OCB) -tag profile ex02.native

debug:
	$(OCB) -tag debug ex02.byte

test: native
	./ex02.native
