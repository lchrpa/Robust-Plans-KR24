# Robust-Plans-KR24
Source code and benchmark data for the paper "On Verifying and Generating Robust Plans for Planning Tasks with Exogenous Events" published at KR 2024

# Compiling the code

- Set up a path to fastdownward in `include/paths.h` (fastdownward can be obtained at fast-downward.org)

type `make`

# Running the benchmarks

- Update a path to the LAMA planner in the `benchmarks/lama-script`

run `benchmarks/run-bench.sh` (it should be run from the main directory, where the compiled `verifier` binary is)

results can be found at `benchmarks/results/`


# References to Existing Code (on which our code is built)

The compiler to FOND (benchmarks/toFOND/) has been taken from: https://github.com/martinpilat/events-FOND 
The PDDL translator (modified FastDownward one) and the ``SAS representation'' classes have been taken from: https://gitlab.com/ctu-fee-fras/public/server-client-simulator-kr-2021 
