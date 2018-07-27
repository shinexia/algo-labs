SRC_HS=$(wildcard *Spec.hs)
TARGETS=$(SRC_HS:Spec.hs=)

all: $(TARGETS)

%: %Spec.hs
	stack test --ta '-m "$@"'

