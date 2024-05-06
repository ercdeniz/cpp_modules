EX00 = ./ex00
EX01 = ./ex01
EX02 = ./ex02
EX03 = ./ex03

all:
	@make -C EX00
	@make -C EX01
	@make -C EX02
	@make -C EX03
m0:
	@make -C EX00
m1:
	@make -C EX01
m2:
	@make -C EX02
m3:
	@make -C EX03
f0:
	@make fclean -C EX00
f1:
	@make fclean -C EX01
f2:	
	@make fclean -C EX02
f3:
	@make fclean -C EX03
clean:
	@make clean -C EX00
	@make clean -C EX01
	@make clean -C EX02
	@make clean -C EX03
fclean: clean
	@make fclean -C EX00
	@make fclean -C EX01
	@make fclean -C EX02
	@make fclean -C EX03
	@rm -rf .vscode

re: fclean all
re0: f0 m0
re1: f1 m1
re2: f2 m2
re3: f3 m3

.PHONY: all clean fclean re m0 m1 m2 m3 f0 f1 f2 f3 re0 re1 re2 re3