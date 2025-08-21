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

**Tested on:** M1 MacBook Air 8GB RAM

| Vector Instructions | Naive Approach | Loop Tiling Approach |
|---------------------|---------------|---------------------|
| **Enabled**         | 1.3374 s      | 0.1266 s            |
| **Disabled**        | 4.1524 s      | 3.6948 s            |

**Tested on:** i5-8250U HP 15-bs101ne 8GB RAM

| Vector Instructions | Naive Approach | Loop Tiling Approach |
|---------------------|---------------|---------------------|
| **Enabled**         | 7.9754 s      | 5.0045 s            |
| **Disabled**        | 18.2969 s      | 10.8587 s            |

**Tested on:** Dell 11th Gen Intel i7-1185G7 (8) @ 4.800GHz 16GB RAM

| Vector Instructions | Naive Approach | Loop Tiling Approach |
|---------------------|---------------|---------------------|
| **Enabled**         | 3.2220 s      | 1.9487 s            |
| **Disabled**        | 6.1121 s      | 4.8843 s            |
