default: main
.PHONY: default

include $(PUREC_DIR)/mk/target.mk

main: .spago

main_CFLAGS = -g
main_LD_FLAGS = -lm

$(eval $(call purs_mk_target,main,Test.Main,src test))
$(eval $(call purs_mk_target,lib,,src))

check: main
	./main.out

.PHONY: check
