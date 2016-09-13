TARGET = praca.pdf
SRC = praca.tex
BIB = bibliografia.bib
PROD = *.pdf

all: clean create

.PHONY: create
create: $(SRC) $(BIB)
	pdflatex ${SRC} 
	bibtex praca
	pdflatex ${SRC}	
	pdflatex ${SRC}

.PHONY: exec
exec:
	xpdf ${TARGET}

.PHONY: clean
clean:
	rm -rf ${PROD} ${TARGET}
