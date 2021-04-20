CFLAGS = -Wall -Wextra -Werror -I src
CPPFLAGS = -MMD

geometry: obj/src/geometry/main.o obj/libhello.a
	$(CC) $(CFLAGS) -o $@ $^

obj/src/geometry/main.o: src/geometry/main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

obj/libhello.a: obj/src/libgeometry/function.o
	ar rcs $@ $^

obj/src/libgeometry/function.o: src/libgeometry/function.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

.PHONY : clean

clean:
	rm -rf obj/src/libgeometry/*.o obj/src/geometry/*.o geometry

-include main.d function.d
