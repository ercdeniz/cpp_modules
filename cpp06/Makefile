EX00 := ex00
EX01 := ex01
EX02 := ex02

MAKE := make
GREP := grep -v 'directory'
TARGETS := $(EX00) $(EX01) $(EX02)

all: $(TARGETS)

$(TARGETS):
	@$(MAKE) -C $@ | $(GREP)

clean:
	@for dir in $(TARGETS); do \
		$(MAKE) clean -C $$dir | $(GREP); \
	done

fclean:
	@for dir in $(TARGETS); do \
		$(MAKE) fclean -C $$dir | $(GREP); \
	done

m%:
	@$(MAKE) -C $(EX0$(@:m%=%)) | $(GREP)

c%:
	@$(MAKE) clean -C $(EX0$(@:c%=%)) | $(GREP)

f%:
	@$(MAKE) fclean -C $(EX0$(@:f%=%)) | $(GREP)

re: fclean all

.PHONY: all clean fclean re $(TARGETS) m% c% f%
