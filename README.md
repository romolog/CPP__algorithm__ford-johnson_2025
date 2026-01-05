# Ford-Johnson algorithm (merge-insertion sort)

I implemented a merge-insertion Ford-Johnson algorithm and compare vector and deque containers speed to sort: 
This algorithm is interesting as it tries to minimize a number of comparisons which corresponds to increase speed of computing.

Implemented features:
<pre>
* Sources:			Donald E. Knuth, 
						The Art of Computer Programming, Vol. 3, Sect. 5.3.1.
					Jacobsthal sequence

* Recursion:		Algorithm is implemented as recursevely calling itself
* Algorithm:		Algorithm is implemented for any possible number of unsorted elements.
					Recursion is used till the 2-3 elements are left and could be sorted simply.
					Since that moment the main chain is formed and unsorted elements from each pair 
					are inserted in the main chain by binary search starting from largest index 
					of unsorted element to the smallest index.
					Jacobsthal sequence is used to calculate the largest index 
					of the unsorted element, which should be inserted in the main chain.
* Benchmark:		Benchmark implemented for Vector and Deque standard containers 
					to compare sorting speed using Ford-Johnson algorithm
</pre>

---

### System Requirements

- Linux (Ubuntu)
- g++
- make

---

### Build

```bash
git clone https://github.com/romolog/CPP__algorithm__ford-johnson_2025 ford_johnson;
cd ford_johnson;
make;
```

### Run
```bash
./ford_johnson 2 1 3 4;
```

### Run with 3000 unsorted integers
```bash
./ford_johnson `shuf -r -i 1-1000 -n 3000 | tr "\n" " " `;
```