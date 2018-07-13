TARGETS=HelloWorld

all: $(TARGETS)

%: %.hs
	stack test --ta '-m "$@"'

