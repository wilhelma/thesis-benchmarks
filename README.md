thesis-benchmarks
=================

Benchmarks supporting the master's thesis on efficient verification of multi-threaded software.

The directory contains benchmarks for programs P1-x, P2-x, P3-x, and P4-x.
You can run the benchmark suite by executing script runBechmarks.

Usage: 		"runBenchmarks [ option params* ]*"
Option List:	-no-trans 	: Use no transactional reasoning
		-no-mhp		: Use no mhp-based reasoning
		-no-threader	: Use no threader for benchmarks
		-no-og		: Use no Owicki-Gries rule for benchmarks
		-no-impara	: Use no impara for benchmarks
		-timeout=x(s|m)	: set timeout interval to x (seconds|minutes) (default:90m)
		-help		: Display this list of options
