default: main
.PHONY: default

include $(PUREC_DIR)/mk/target.mk

main: bower_components

main_CFLAGS =
main_LD_FLAGS =

$(eval $(call purs_mk_target,main,Test.Main,src test))
