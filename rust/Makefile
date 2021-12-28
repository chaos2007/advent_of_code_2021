FOLDERS := $(wildcard day_*)

all: $(FOLDERS)

$(FOLDERS): 
	cd $@; cargo test

.PHONY: all $(FOLDERS)
