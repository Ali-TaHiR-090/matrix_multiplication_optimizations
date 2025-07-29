src := src/mat_mil.c
build_dir := build

all: run

run: compile
	@echo "Running optimized version:"
	./$(build_dir)/output_vector_multiplication
	@echo "\nRunning unoptimized version:"
	./$(build_dir)/output_no_vector_multiplication

compile:
	mkdir -p $(build_dir)
	gcc $(src) -O3 -o $(build_dir)/output_vector_multiplication
	gcc $(src) -O0 -o $(build_dir)/output_no_vector_multiplication

clean:
	rm -rf $(build_dir)/*


.PHONY: all run compile clean

