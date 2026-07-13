# Green Efficiency Analysis

## Measurement Methodology

In this project, I measured the execution time using the clock() function and converted the results to seconds using CLOCKS_PER_SEC. I compiled all programs with the required compiler flags and ran them on the same machine. I executed the baseline benchmark three times because the execution time can change slightly between runs. For the comparison program, I recorded the execution time for both algorithms in each run and calculated the average. In the instrumentation task, I measured the total execution time and the time for each phase separately.

## Observed Performance Differences

The baseline benchmark showed small differences between runs, which is normal. The comparison benchmark showed a much bigger difference. The naive algorithm took an average of about 0.758456 seconds, while the single-pass algorithm took about 0.000030 seconds. This means the naive implementation was about 25,000 times slower. Both algorithms produce the same result, but the single-pass version is much faster because it only goes through the data once.

## Relation Between Runtime and Energy Consumption

This project does not measure actual energy usage, but execution time can be used as a simple indicator. A program that runs longer keeps the CPU busy for a longer time. Based on my measurements, the naive algorithm spent much more time running than the single-pass algorithm. In general, reducing unnecessary work helps improve efficiency and can reduce resource usage.

## Limitations of the Experiment

There are some limitations in this experiment. I only ran each benchmark three times, so the average may change slightly if more runs are performed. Background processes running on the computer can also affect the measurements. In addition, clock() measures processor time, not actual electrical energy, so these results only show performance and not real power consumption.

## Practical Engineering Takeaway

This project showed me that measuring performance is better than guessing. Two programs can produce the same output but have very different execution times. The comparison benchmark clearly showed that choosing a better algorithm can greatly improve performance without changing the result. Simple benchmarking is a useful way to compare implementations and make better engineering decisions based on real measurements.
