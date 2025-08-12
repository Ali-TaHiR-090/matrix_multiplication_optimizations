src := src/mat_mil.c
build_dir := build

optimized   := $(build_dir)/output_vector_multiplication.out
unoptimized := $(build_dir)/output_no_vector_multiplication.out

all: run

run: compile
	@echo "Running optimized version:"
	$(optimized)
	@echo "\nRunning unoptimized version:"
	$(unoptimized)

compile: $(optimized) $(unoptimized)

$(optimized): $(src)
	mkdir -p $(build_dir)
	gcc $< -O3 -o $@

$(unoptimized): $(src)
	mkdir -p $(build_dir)
	gcc $< -O0 -o $@

clean:
	rm -rf $(build_dir)/*

.PHONY: all run compile clean

