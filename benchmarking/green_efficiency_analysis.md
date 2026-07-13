# Green Efficiency Analysis

## Measurement Methodology

I measured the execution time using the `clock()` function and converted the results to seconds using `CLOCKS_PER_SEC`. All programs were compiled using the required compiler flags and tested on the same machine to keep the results as consistent as possible. The baseline program was executed three times because the execution time can change slightly between runs. For the comparison program, I recorded the execution time of both algorithms in each run, then calculated the average execution time. In the instrumentation task, I measured the total execution time and the time spent in each phase separately.

## Observed Performance Differences

The baseline program showed small differences between runs, which is normal even when the program always does the same work. In the comparison task, the difference between the two algorithms was much bigger. The naive algorithm took an average of about **0.758456 seconds**, while the single-pass algorithm took about **0.000030 seconds**. This means the naive implementation was around **25,000 times slower**. Both algorithms solve the same problem, but the single-pass version finishes much faster because it only goes through the data once.

## Relation Between Runtime and Energy Consumption

This project does not measure actual power usage, but execution time can be used as a simple indicator. If a program runs for a longer time, the CPU stays busy for longer. Based on my results, the naive algorithm spent much more time running than the single-pass algorithm, so it is reasonable to expect that it would also use more processing resources. Writing more efficient code can help reduce unnecessary work and improve overall efficiency.

## Limitations of the Experiment

The results are based on only three executions, so small differences between runs are expected. The operating system may also be running other background tasks that affect the timing. In addition, `clock()` measures processor time, not actual electrical energy, so these measurements should be used only as an estimate of performance.

## Practical Engineering Takeaway

This project showed that measuring performance is better than guessing. Even when two programs produce the same result, one implementation can be much more efficient than the other. Choosing a better algorithm can reduce execution time without changing the output. Simple benchmarking is useful because it helps developers make decisions based on real measurements instead of assumptions.
