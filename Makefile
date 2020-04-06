services:
	mkdir bin
	gcc -o bin/ads servs/add_service.c
	gcc -o bin/cs servs/color_service.c
	gcc -o bin/ps servs/position_service.c
	gcc -o bin/os servs/output_service.c coniox/libconiox.c
	gcc -o bin/es servs/erase_service.c
	gcc -o bin/crs servs/create_service.c
	gcc -o bin/rms servs/remove_service.c
	gcc -o bin/fs servs/find_service.c
	gcc -o bin/rs servs/replace_service.c

main:
	gcc -o cn host_src/host.c host_src/host_funcs.c host_src/flag_processing.c coniox/libconiox.c

rmb:
	rm -rf bin

rms:
	rm -rf *.c
