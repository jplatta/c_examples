bin/hello_world: src/hello_world.c
	gcc $^ -Wall -o $@

bin/blab_functions: src/blab_functions.c
	gcc $^ -Wall -o $@

blab_functions.o: src/blab_functions.c src/blab_functions.h
	gcc -c src/blab_functions.c

advice_bot.o: src/advice_bot.c src/blab_functions.h
	gcc -c src/advice_bot.c

advice_bot: advice_bot.o blab_functions.o
	gcc advice_bot.o blab_functions.o -o bin/advice_bot

bin/knock_knock_server.o: src/knock_knock_server.c
	gcc -c src/knock_knock_server.c -o $@

bin/knock_knock: bin/knock_knock_server.o 
	gcc bin/knock_knock_server.o -o $@

test: tests.out
	@./tests.out

tests.out: test/*.c src/*.c src/*.h
	gcc -Wall src/*.c test/unity/unity.c test/*.c -o tests.out

test_blab_functions: tests_blab_functions.out
	@./tests_blab_functions.out

tests_blab_functions.out: test/test_blab_functions.c src/blab_functions.c src/blab_functions.h
	gcc -Wall src/blab_functions.c test/unity/unity.c test/test_blab_functions.c -o tests_blab_functions.out

clean:
	rm -rf bin/*.o bin/*.out bin/*.out.dSYM
  
