# Matrix Multiplication Algorithms Comparison

This project compares simple matrix multiplication algorithms:  
- **Naive approach**  
- **Loop tiling approach**

## Configuration

- **Matrix size:** `1024 × 1024`
- **Block size:** `32` (optimal)

## Usage

If you are using a Unix-based OS, simply run:

```sh
make
```

## Benchmarks

**Tested on:** M1 MacBook Air

| Vector Instructions | Naive Approach | Loop Tiling Approach |
|---------------------|---------------|---------------------|
| **Enabled**         | 1.3374 s      | 0.1266 s            |
| **Disabled**        | 4.1524 s      | 3.6948 s            |