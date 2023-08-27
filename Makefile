lab4:
	gcc -Wall -g -o eseg lab4exe1.c
	./eseg /home/piergiuseppe/my_exercise_1/
clean:
	rm -f eseg eseg2_1 eseg2_2
	clear
	ls
fork1 :
	gcc lab4exe2_1.c -o eseg2_1
	./eseg2_1
fork2 :
	gcc lab4exe2_2.c -o eseg2_2
	./eseg2_2
