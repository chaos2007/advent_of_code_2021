all: rust cpp

.PHONY: rust
rust:
	$(MAKE) -C rust

.PHONY: cpp
cpp:
	$(MAKE) -C c++
