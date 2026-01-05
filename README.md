# Ford-Johnson algorithm (merge-insertion sort)

I implemented a merge-insertion Ford-Johnson algorithm and compare vector and deque containers speed to sort: 
This algorithm is interesting as it tries to minimize a number of comparisons which corresponds to increase speed of computing.

Implemented features:
<pre>
* Sources:			Donald E. Knuth, The Art of Computer Programming, Vol. 3, Sect. 5.3.1.
					Jacobsthal sequence

* Recursion:		The algorithm is implemented using recursive calls.

* Algorithm:		Works for any number of unsorted elements.
					
					Recursion continues until 2–3 elements remain, which are sorted directly. 
                	At this point, the main chain is formed, and unsorted elements 
					from each pair are inserted into the main chain using binary search, 
					starting from the largest index of the unsorted element 
					down to the smallest. 
                	
					The Jacobsthal sequence is used to determine the largest index 
                	of each unsorted element to be inserted into the main chain.

* Benchmark:		Benchmarks are implemented for the Vector and Deque standard containers 
                	to compare sorting speed using the Ford-Johnson algorithm.
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