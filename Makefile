servs:
	mkdir bin
	gcc -o bin/ads add_service.c
	gcc -o bin/cs color_service.c
	gcc -o bin/ps position_service.c
	gcc -o bin/os output_service.c
	gcc -o bin/es erase_service.c
	gcc -o bin/crs create_service.c
	gcc -o bin/rms remove_service.c

main:
	gcc -o cn host.c coniox/libconiox.c

rmb:
	rm -rf bin

rms:
	rm -rf *.c
