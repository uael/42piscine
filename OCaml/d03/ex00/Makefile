.PHONY:	all clean byte native profile debug test

OCB_FLAGS = -tag bin_annot -lib graphics
OCB = 		ocamlbuild $(OCB_FLAGS)

all: native byte # profile debug

clean:
	$(OCB) -clean

native:
	$(OCB) ft_graphics.native

byte:
	$(OCB) ft_graphics.byte

profile:
	$(OCB) -tag profile ft_graphics.native

debug:
	$(OCB) -tag debug ft_graphics.byte

test: native
	./ft_graphics.native
